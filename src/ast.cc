/** MIT License

    Copyright (c) 2019 Kyrylo Bazhenov

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
*/

#pragma warning(push)
#pragma warning(disable:4146)
#pragma warning(disable:4141)
#pragma warning(disable:4244)
#pragma warning(disable:4267)
#pragma warning(disable:4291)
#pragma warning(disable:4624)
#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS  1

#include "ast.hh"

#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Constants.h>

#include <llvm/ADT/StringRef.h>

#include <llvm/Support/FormatVariadic.h>

#undef _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
#pragma warning(pop)

#include <iostream>
#include <iomanip>
#include <typeinfo>
#include <typeindex>

#ifdef _WIN32
#pragma comment(lib, "kernel32.lib")
extern "C" bool IsDebuggerPresent();
#endif

static llvm::StringRef ToLLVM(std::string_view sv)
{
    return llvm::StringRef(sv.data(), sv.size());
}

namespace AST
{
    //-----------------------------------------------------------------------------------------------------------------
    // BaseExpression
    BaseExpression::BaseExpression(SourceParseContext context)
     : ParseContext(context)
    {}

    BaseExpression::~BaseExpression() {}

    void BaseExpression::Assert(bool condition, std::string_view message) const
    {
        if (!condition) {
            std::cerr << message << " at line " << ParseContext.LineNumber << std::endl
                      << ParseContext.Source << std::endl;
#ifdef _WIN32
            if (IsDebuggerPresent()) {
                __debugbreak();
            }
#endif
            exit(-1);
        }
    }

    std::string BaseExpression::GetTypeName(llvm::Type* type) const
    {
        std::string type_str;
        llvm::raw_string_ostream rso(type_str);
        type->print(rso);
        return rso.str();
    }

    // TODO: Rework
    bool BaseExpression::IsSafeTypeCastPossible(llvm::Value* value, llvm::Type* desiredType) const
    {
        llvm::Type* valueType = value->getType();
        if (valueType != desiredType) {
            if (desiredType->isStructTy() || valueType->isStructTy()) {
                return false;
            }

            if (llvm::Constant::classof(value)) {
                if (desiredType->isIntegerTy() && valueType->isIntegerTy()) {
                    return true;
                } else if (desiredType->isFloatingPointTy()) {
                    return  true; // Can always convert constants to float
                }
            } else {
                if (desiredType->isIntegerTy() && valueType->isIntegerTy()) {
                    return true;
                } else if (desiredType->isFloatingPointTy() && valueType->isFloatingPointTy()) {
                    return  true;
                }
            }

            //if (valueType->isPointerTy() && desiredType->isPointerTy()) {
            //    return true;
            //}

            return false;
        }

        return true;
    }

    llvm::Type* BaseExpression::ResolveType(ExpressionType type, const GeneratedScope &scope) const
    {
        if (!type.IsFunction) {
            auto itr = scope.Types.find(type.TypeName);
            Assert(itr != scope.Types.end(), "Unknown type");

            llvm::Type* baseType = (*itr).second;
            if (type.IsPointer) {
                baseType = baseType->getPointerTo();
            }
            return baseType;
        } else if (type.IsFunction) {
            llvm::Type* returnType = ResolveType(type.ArgumentTypes[0], scope);

            std::vector<llvm::Type*> argTypes;
            for (size_t i = 1; i < type.ArgumentTypes.size(); ++i) {
                argTypes.emplace_back(ResolveType(type.ArgumentTypes[i], scope));
            }

            llvm::Type* functionType = llvm::FunctionType::get(returnType, argTypes, false);
            return functionType->getPointerTo();
        }

        Assert(false, "Impossible type, this is likely a compiler bug");
        return nullptr;
    }

    llvm::Value* BaseExpression::GenerateSafeTypeCast(llvm::Value *value, llvm::Type *desiredType) const
    {
        llvm::Type* valueType = value->getType();
        if (valueType != desiredType) {
            if (desiredType->isStructTy()) {
                Assert(false, "Cannot implicitly cast a struct");
            }

            if (llvm::Constant::classof(value)) {
                if (desiredType->isIntegerTy()) {
                    Assert(valueType->isIntegerTy(),
                           "Cannot implicitly convert non-integer type to integer, please use a manual cast");

                    llvm::APInt apValue = static_cast<llvm::ConstantInt*>(value)->getValue();
                    // TODO: Check constant overflow
                    return llvm::ConstantInt::get(desiredType, apValue.getLimitedValue());
                } else if (desiredType->isFloatingPointTy()) {
                    if (valueType->isIntegerTy()) {
                        llvm::APInt apValue = static_cast<llvm::ConstantInt*>(value)->getValue();
                        // TODO: Check constant overflow
                        return llvm::ConstantFP::get(desiredType, double(apValue.getLimitedValue()));
                    } else if (valueType->isFloatingPointTy()) {
                        llvm::APFloat apValue = static_cast<llvm::ConstantFP*>(value)->getValueAPF();
                        // TODO: Check constant overflow
                        return llvm::ConstantFP::get(desiredType, apValue.convertToDouble());
                    }
                }
            }

            //if (valueType->isPointerTy() && desiredType->isPointerTy()) {
            //    return value;
            //}

            std::string errorMessage = llvm::formatv("Cannot perform implicit type conversion from \"{0}\" to \"{1}\"",
                                                     GetTypeName(valueType), GetTypeName(desiredType));
            Assert(false, errorMessage);
        }
        return value;
    }

    llvm::Value* BaseExpression::GenerateBoolean(CodeGenContext& cc, llvm::Value *value) const
    {
        Assert(value->getType()->isIntegerTy(), "Boolean or integer expected");
        llvm::IntegerType* intType = static_cast<llvm::IntegerType*>(value->getType());
        if (intType->getBitWidth() != 1) {
            value = cc.Builder->CreateICmpUGT(value,
                                              llvm::ConstantInt::get(intType, llvm::APInt(intType->getBitWidth(), 0, false)));
        }
        return value;
    }

    void BaseExpression::DebugPrint(int indent)
    {
        std::cerr << std::setfill(' ') << std::setw(indent)
                  << indent << "/" << ParseContext.LineNumber << "::"
                  << typeid(*this).name() << "::" << ParseContext.Source << std::endl;
    }

    //-----------------------------------------------------------------------------------------------------------------
    // BinaryOperator
    BinaryOperatorExpression::BinaryOperatorExpression(SourceParseContext parseContext,
                                                       BaseExpressionPtr&& lhs, BaseExpressionPtr&& rhs)
        : BaseExpression(parseContext),
          Operator(parseContext.Source), LHS(std::move(lhs)), RHS(std::move(rhs))
    {}

    CodeGenResult BinaryOperatorExpression::Generate(CodeGenContext &cc)
    {
        CodeGenResult generatedLHS = LHS->Generate(cc);
        CodeGenResult generatedRHS = RHS->Generate(cc);

        Assert(generatedLHS.NumValues == 1 && generatedRHS.NumValues == 1,
               "Binary operations on overloaded values are not supported (yet)");

        llvm::Value* lhs = generatedLHS.Values[0];
        llvm::Value* rhs = generatedRHS.Values[0];

        if (llvm::Constant::classof(lhs) && !llvm::Constant::classof(rhs)) {
            lhs = GenerateSafeTypeCast(lhs, rhs->getType());
        } else if (!llvm::Constant::classof(lhs) && llvm::Constant::classof(rhs)) {
            rhs = GenerateSafeTypeCast(rhs, lhs->getType());
        } else {
            rhs = GenerateSafeTypeCast(rhs, lhs->getType());
        }

        if (false) {}

        // Arithmetic operators
        else if (Operator == "+") {
            if (lhs->getType()->isStructTy()) {
                // TODO: structs support
                Assert(false, "Overloading binary operators for structures is not yet implemented");
            } else if (lhs->getType()->isIntegerTy()) {
                LocalValue = cc.Builder->CreateAdd(lhs, rhs);
                return CodeGenResult(&LocalValue);
            } else if (lhs->getType()->isFloatingPointTy()) {
                LocalValue = cc.Builder->CreateFAdd(lhs, rhs);
                return CodeGenResult(&LocalValue);
            }
        } else if (Operator == "-") {
            if (lhs->getType()->isStructTy()) {
                // TODO: structs support
                Assert(false, "Overloading binary operators for structures is not yet implemented");
            } else if (lhs->getType()->isIntegerTy()) {
                LocalValue = cc.Builder->CreateSub(lhs, rhs);
                return CodeGenResult(&LocalValue);
            } else if (lhs->getType()->isFloatingPointTy()) {
                LocalValue = cc.Builder->CreateFSub(lhs, rhs);
                return CodeGenResult(&LocalValue);
            }
        } else if (Operator == "*") {
            if (lhs->getType()->isStructTy()) {
                // TODO: structs support
                Assert(false, "Overloading binary operators for structures is not yet implemented");
            } else if (lhs->getType()->isIntegerTy()) {
                LocalValue = cc.Builder->CreateMul(lhs, rhs);
                return CodeGenResult(&LocalValue);
            } else if (lhs->getType()->isFloatingPointTy()) {
                LocalValue = cc.Builder->CreateFMul(lhs, rhs);
                return CodeGenResult(&LocalValue);
            }
        } else if (Operator == "/") {
            if (lhs->getType()->isStructTy()) {
                // TODO: structs support
                Assert(false, "Overloading binary operators for structures is not yet implemented");
            } else if (lhs->getType()->isIntegerTy()) {
                LocalValue = cc.Builder->CreateSDiv(lhs, rhs); // TODO: signed/unsigned division
                    return CodeGenResult(&LocalValue);
            } else if (lhs->getType()->isFloatingPointTy()) {
                LocalValue = cc.Builder->CreateFDiv(lhs, rhs);
                return CodeGenResult(&LocalValue);
            }
        }

        // Comparison operators
        else if (Operator == "==") {
            if (lhs->getType()->isStructTy()) {
                // TODO: structs support
                Assert(false, "Overloading binary operators for structures is not yet implemented");
            } else if (lhs->getType()->isIntegerTy()) {
                LocalValue = cc.Builder->CreateICmpEQ(lhs, rhs);
                return CodeGenResult(&LocalValue);
            } else if (lhs->getType()->isFloatingPointTy()) {
                LocalValue = cc.Builder->CreateFCmpOEQ(lhs, rhs); // TODO: OGT or UGT? OGT supports QNaN
                    return CodeGenResult(&LocalValue);
            }
        } else if (Operator == "!=") {
            if (lhs->getType()->isStructTy()) {
                // TODO: structs support
                Assert(false, "Overloading binary operators for structures is not yet implemented");
            } else if (lhs->getType()->isIntegerTy()) {
                LocalValue = cc.Builder->CreateICmpNE(lhs, rhs);
                return CodeGenResult(&LocalValue);
            } else if (lhs->getType()->isFloatingPointTy()) {
                LocalValue = cc.Builder->CreateFCmpONE(lhs, rhs); // TODO: OGT or UGT? OGT supports QNaN
                    return CodeGenResult(&LocalValue);
            }
        } else if (Operator == ">") {
            if (lhs->getType()->isStructTy()) {
                // TODO: structs support
                Assert(false, "Overloading binary operators for structures is not yet implemented");
            } else if (lhs->getType()->isIntegerTy()) {
                LocalValue = cc.Builder->CreateICmpSGT(lhs, rhs); // TODO: signed/unsigned comparison
                    return CodeGenResult(&LocalValue);
            } else if (lhs->getType()->isFloatingPointTy()) {
                LocalValue = cc.Builder->CreateFCmpOGT(lhs, rhs);
                return CodeGenResult(&LocalValue);
            }
        } else if (Operator == ">=") {
            if (lhs->getType()->isStructTy()) {
                // TODO: structs support
                Assert(false, "Overloading binary operators for structures is not yet implemented");
            } else if (lhs->getType()->isIntegerTy()) {
                LocalValue = cc.Builder->CreateICmpSGE(lhs, rhs);
                return CodeGenResult(&LocalValue);
            } else if (lhs->getType()->isFloatingPointTy()) {
                LocalValue = cc.Builder->CreateFCmpOGE(lhs, rhs);
                return CodeGenResult(&LocalValue);
            }
        } else if (Operator == "<") {
            if (lhs->getType()->isStructTy()) {
                // TODO: structs suppport
                Assert(false, "Overloading binary operators for structures is not yet implemented");
            } else if (lhs->getType()->isIntegerTy()) {
                LocalValue = cc.Builder->CreateICmpSLT(lhs, rhs);
                return CodeGenResult(&LocalValue);
            } else if (lhs->getType()->isFloatingPointTy()) {
                LocalValue = cc.Builder->CreateFCmpOLT(lhs, rhs);
                return CodeGenResult(&LocalValue);
            }
        } else if (Operator == "<=") {
            if (lhs->getType()->isStructTy()) {
                // TODO: structs suppport
                Assert(false, "Overloading binary operators for structures is not yet implemented");
            } else if (lhs->getType()->isIntegerTy()) {
                LocalValue = cc.Builder->CreateICmpSLE(lhs, rhs);
                return CodeGenResult(&LocalValue);
            } else if (lhs->getType()->isFloatingPointTy()) {
                LocalValue = cc.Builder->CreateFCmpOLE(lhs, rhs);
                return CodeGenResult(&LocalValue);
            }
        }

        // Logical operators
        else if (Operator == "&&") {
            if (lhs->getType()->isStructTy()) {
                Assert(false, "Overloading logical operators for structures is not yet implemented");
            } else {
                lhs = GenerateBoolean(cc, lhs);
                rhs = GenerateBoolean(cc, rhs);
                LocalValue = cc.Builder->CreateAnd(lhs, rhs);
                return CodeGenResult(&LocalValue);
            }
        } else if (Operator == "||") {
            if (lhs->getType()->isStructTy()) {
                Assert(false, "Overloading logical operators for structures is not yet implemented");
            } else {
                lhs = GenerateBoolean(cc, lhs);
                rhs = GenerateBoolean(cc, rhs);
                LocalValue = cc.Builder->CreateOr(lhs, rhs);
                return CodeGenResult(&LocalValue);
            }
        }

        // Bitwise operators
        else if (Operator == "&") {
            if (lhs->getType()->isStructTy()) {
                Assert(false, "Overloading bitwise operators for structures is not yet implemented");
            } else if (lhs->getType()->isIntegerTy()) {
                LocalValue = cc.Builder->CreateAnd(lhs, rhs);
                return CodeGenResult(&LocalValue);
            } else if (lhs->getType()->isFloatingPointTy()) {
                Assert(false, "Bitwise operators not supported for floats");
            }
        } else if (Operator == "|") {
            if (lhs->getType()->isStructTy()) {
                Assert(false, "Overloading bitwise operators for structures is not yet implemented");
            } else if (lhs->getType()->isIntegerTy()) {
                LocalValue = cc.Builder->CreateOr(lhs, rhs);
                return CodeGenResult(&LocalValue);
            } else if (lhs->getType()->isFloatingPointTy()) {
                Assert(false, "Bitwise operators not supported for floats");
            }
        } else if (Operator == "^") {
            if (lhs->getType()->isStructTy()) {
                Assert(false, "Overloading bitwise operators for structures is not yet implemented");
            } else if (lhs->getType()->isIntegerTy()) {
                LocalValue = cc.Builder->CreateXor(lhs, rhs);
                return CodeGenResult(&LocalValue);
            } else if (lhs->getType()->isFloatingPointTy()) {
                Assert(false, "Bitwise operators not supported for floats");
            }
        }

        Assert(false, "Unexpected binary operator");
        return {};
    }

    void BinaryOperatorExpression::DebugPrint(int indent)
    {
        BaseExpression::DebugPrint(indent);
        LHS->DebugPrint(indent + 1);
        RHS->DebugPrint(indent + 1);
    }

    //-----------------------------------------------------------------------------------------------------------------
    // UnaryOperator
    UnaryOperatorExpression::UnaryOperatorExpression(SourceParseContext parseContext,
                                                     BaseExpressionPtr&& rhs)
        : BaseExpression(parseContext)
        , Operator(parseContext.Source)
    {
        RHS = std::move(rhs);
    }

    CodeGenResult UnaryOperatorExpression::Generate(CodeGenContext &cc)
    {
        CodeGenResult generatedRHS = RHS->Generate(cc);
        Assert(generatedRHS.NumValues == 1,
               "Unary operations on overloaded values are not supported (yet)");

        llvm::Value* rhs = generatedRHS.Values[0];

        if (false) {}

        // Arithmetics
        else if (Operator == "+") {
            if (rhs->getType()->isStructTy()) {
                // TODO: structs support
                Assert(false, "Overloading unary operators for structures is not yet implemented");
            } else {
                return generatedRHS;
            }
        } else if (Operator == "-") {
            if (rhs->getType()->isStructTy()) {
                // TODO: structs support
                Assert(false, "Overloading unary operators for structures is not yet implemented");
            } else if (rhs->getType()->isIntegerTy()) {
                LocalValue = cc.Builder->CreateNeg(rhs);
                return CodeGenResult(&LocalValue);
            } else if (rhs->getType()->isFloatingPointTy()) {
                LocalValue = cc.Builder->CreateFNeg(rhs);
                return CodeGenResult(&LocalValue);
            }
        }

        // Logical operators
        else if (Operator == "!") {
            if (rhs->getType()->isStructTy()) {
                // TODO: structs support
                Assert(false, "Overloading unary operators for structures is not yet implemented");
            } else {
                rhs = GenerateBoolean(cc, rhs);
                LocalValue = cc.Builder->CreateNot(rhs);
                return CodeGenResult(&LocalValue);
            }
        }

        // Bitwise operators
        else if (Operator == "~") {
            if (rhs->getType()->isStructTy()) {
                // TODO: structs support
                Assert(false, "Overloading unary operators for structures is not yet implemented");
            } else if (rhs->getType()->isIntegerTy()) {
                LocalValue = cc.Builder->CreateNot(rhs);
                return CodeGenResult(&LocalValue);
            } else if (rhs->getType()->isFloatingPointTy()) {
                Assert(false, "Bitwise operators not supported for floats");
            }
        }

        Assert(false, "Unexpected unary operator");
        return {};
    }

    void UnaryOperatorExpression::DebugPrint(int indent)
    {
        BaseExpression::DebugPrint(indent);
        RHS->DebugPrint(indent + 1);
    }

    //-----------------------------------------------------------------------------------------------------------------
    // FunctionDecl
    FunctionExpression::FunctionExpression(SourceParseContext context, FunctionType &&type,
                                       std::vector<BaseExpressionPtr>&& body)
        : BaseExpression(context)
    {
        Overload overload;
        overload.Type = std::move(type);
        overload.Body = std::move(body);

        Overloads.emplace_back(std::move(overload));
    }

    void FunctionExpression::AddOverload(std::unique_ptr<FunctionExpression> &&expr)
    {
        auto localFunctionExpr = std::move(expr);

        for (auto& overload: localFunctionExpr->Overloads) {
            Overloads.emplace_back(std::move(overload));
        }
    }

    CodeGenResult FunctionExpression::Generate(CodeGenContext &cc)
    {
        for (const Overload& overload: Overloads) {
            const auto& Type = overload.Type;
            const auto& Body = overload.Body;

            // Resolve return and argument types
            llvm::Type* returnType = ResolveType(Type.ReturnType, cc.Scope);
            std::vector<llvm::Type*> argTypes;
            for (auto& type: Type.ArgTypes) {
                argTypes.emplace_back(ResolveType(type, cc.Scope));
            }

            // Create function
            llvm::FunctionType* functionType = llvm::FunctionType::get(returnType, argTypes, false);
            llvm::Function* functionValue = llvm::Function::Create(functionType, llvm::Function::ExternalLinkage,
                                                                   ToLLVM(ParseContext.Source), cc.Module);

            // Create body
            if (!Body.empty()) {
                GeneratedScope functionScope = cc.Scope;

                // Generate function body
                llvm::BasicBlock* block = llvm::BasicBlock::Create(*cc.Context, "__funcbody", functionValue);
                cc.Builder->SetInsertPoint(block);
                functionScope.RootBlock = block;

                // Load parameters
                if (!Type.ArgNames.empty()) {
                    //llvm::BasicBlock* paramsBlock = llvm::BasicBlock::Create(LLVMContext, "load_params", functionValue);
                    //Builder.SetInsertPoint(paramsBlock);

                    overload.LocalArgumentValues.reserve(Type.ArgNames.size());
                    for (size_t i = 0; i < Type.ArgNames.size(); ++i) {
                        if (!Type.ArgNames[i].empty()) {
                            Assert(functionScope.Bindings.find(Type.ArgNames[i]) == functionScope.Bindings.end(),
                                   "Conflicting binding name in function scope");
                            //llvm::Value* allocation = Builder.CreateAlloca(functionSignature.ArgTypes[i]);
                            //Builder.CreateStore(functionValue->arg_begin() + i, allocation);
                            //functionScope.Bindings.insert(std::make_pair(functionSignature.ArgNames[i], allocation));
                            overload.LocalArgumentValues.emplace_back(functionValue->arg_begin() + i);

                            CodeGenResult generatedFunctionArg;
                            generatedFunctionArg.Values = &overload.LocalArgumentValues[i];
                            generatedFunctionArg.NumValues = 1;

                            functionScope.Bindings.insert(std::make_pair(Type.ArgNames[i], generatedFunctionArg));
                        }
                    }
                }

                CodeGenContext localContext = {
                    std::move(functionScope),
                    cc.Builder, cc.Module, cc.Context
                };

                CodeGenResult generatedValue = {};
                for (auto& body: Body) {
                    generatedValue = body->Generate(localContext);
                }

                Assert(generatedValue.NumValues == 1,
                       "Returning overloaded values from functions is not supported(yet)");
                llvm::Value* value = generatedValue.Values[0];

                if (functionType->getReturnType()->isVoidTy()) {
                    cc.Builder->CreateRetVoid();
                } else {
                    // Cast to return type
                    if (value != nullptr) {
                        value = GenerateSafeTypeCast(value, returnType);
                    }

                    Assert((value == nullptr) || (value != nullptr && value->getType() == returnType),
                           "Function return type does not match expression type");

                    if (value == nullptr || value->getType()->isVoidTy()) {
                        cc.Builder->CreateRetVoid();
                    } else {
                        cc.Builder->CreateRet(value); // TODO: return statements
                    }
                }

                // Restore root block
                cc.Builder->SetInsertPoint(cc.Scope.RootBlock);

                if (ParseContext.Source == "main")  { // TODO: explicit dll storage class for functions
                    functionValue->setDLLStorageClass(llvm::Function::DefaultStorageClass);
                    functionValue->setVisibility(llvm::Function::DefaultVisibility);
                } else {
                    functionValue->setVisibility(llvm::Function::HiddenVisibility);
                    functionValue->setDLLStorageClass(llvm::Function::DefaultStorageClass);
                    functionValue->setLinkage(llvm::Function::InternalLinkage);
                }
            } else {
                functionValue->setDLLStorageClass(llvm::Function::DLLImportStorageClass);
                functionValue->setVisibility(llvm::Function::DefaultVisibility);
            }

            GeneratedOverloads.emplace_back(functionValue);
        }

        return CodeGenResult(GeneratedOverloads);
    }

    void FunctionExpression::DebugPrint(int indent)
    {
        BaseExpression::DebugPrint(indent);
        for (const auto& overload: Overloads) {
            for (const auto& body: overload.Body) {
                body->DebugPrint(indent + 1);
            }
        }
    }

    //-----------------------------------------------------------------------------------------------------------------
    // Branch
    BranchExpression::BranchExpression(SourceParseContext context, std::vector<ConditionAndValue>&& body)
        : BaseExpression(context)
    {
        Body = std::move(body);
    }

    CodeGenResult BranchExpression::Generate(CodeGenContext &cc)
    {
        // Blocks
        std::vector<llvm::BasicBlock*> generatedBlocks;
        generatedBlocks.resize(Body.size() + 1);

        std::vector<llvm::BasicBlock*> generatedCondBlocks;
        generatedCondBlocks.resize(Body.size() - 1);

        std::vector<llvm::Value*> generatedValues;
        generatedValues.resize(Body.size());

        // Create condition blocks first
        llvm::Function* parentFunction = cc.Builder->GetInsertBlock()->getParent();
        for (size_t i = 0; i < Body.size() - 1; ++i) {
            generatedCondBlocks[i] = llvm::BasicBlock::Create(*cc.Context, llvm::formatv("cond_{0}_test", i + 1), parentFunction);
        }

        for (size_t i = 0; i < Body.size(); ++i) {
            generatedBlocks[i] = llvm::BasicBlock::Create(*cc.Context, llvm::formatv("cond_{0}_body", i), parentFunction);
        }

        // Create merge
        llvm::BasicBlock* nextBlock = llvm::BasicBlock::Create(*cc.Context, "cond_next", parentFunction);
        generatedBlocks[generatedBlocks.size() - 1] = nextBlock;

        // Create conditions
        {
            GeneratedScope localScope = cc.Scope;
            CodeGenContext localContext = {
                localScope,
                cc.Builder, cc.Module, cc.Context
            };

            // Generate BRanches
            for (size_t i = 0; i < Body.size(); ++i) {
                // Generate condition
                if (i != generatedCondBlocks.size() && Body[i].Condition != nullptr) {
                    CodeGenResult generatedCondition = Body[i].Condition->Generate(localContext);
                    Assert(generatedCondition.NumValues == 1,
                           "Branching on overloaded values are not supported (yet)");

                    llvm::Value* condition = generatedCondition.Values[0];
                    condition = GenerateBoolean(cc, condition);

                    // Create branch
                    cc.Builder->CreateCondBr(condition, generatedBlocks[i], generatedCondBlocks[i]);

                    // Update blocks
                    localScope.RootBlock = generatedCondBlocks[i];
                    cc.Builder->SetInsertPoint(generatedCondBlocks[i]);
                } else {
                    cc.Builder->CreateBr(generatedBlocks[i]);
                }
            }

            // Generate bodies
            for (size_t i = 0; i < Body.size(); ++i) {
                localScope.RootBlock = generatedBlocks[i];
                cc.Builder->SetInsertPoint(generatedBlocks[i]);

                for (auto& value: Body[i].Values) {
                    CodeGenResult generatedValue = value->Generate(localContext);
                    Assert(generatedValue.NumValues == 1,
                           "Branching on overloaded values are not supported (yet)");

                    generatedValues[i] = generatedValue.Values[0];
                }

                cc.Builder->CreateBr(nextBlock);
            }
        }

        // This is the first place that modifies the insert point and does not restore it back
        cc.Builder->SetInsertPoint(nextBlock);
        cc.Scope.RootBlock = nextBlock;

        llvm::Type* desiredType = generatedValues[0]->getType();
        llvm::PHINode* phi = cc.Builder->CreatePHI(desiredType, uint32_t(Body.size()));
        for (size_t i = 0; i < Body.size(); ++i) {
            phi->addIncoming(GenerateSafeTypeCast(generatedValues[i], desiredType), generatedBlocks[i]);
        }

        LocalValue = phi;
        return CodeGenResult(&LocalValue);
    }

    void BranchExpression::DebugPrint(int indent)
    {
        BaseExpression::DebugPrint(indent);
        for (auto& bodyItem: Body) {
            if (bodyItem.Condition != nullptr) {
                bodyItem.Condition->DebugPrint(indent + 1);
            }
            for (auto& bodyValueItem: bodyItem.Values) {
                bodyValueItem->DebugPrint(indent + 1);
            }
        }
    }

    //-----------------------------------------------------------------------------------------------------------------
    // Form
    FunctionCallExpression::FunctionCallExpression(SourceParseContext parseContext,
                                                   BaseExpressionPtr&& functionExpr,
                                                   std::vector<BaseExpressionPtr> &&arguments)
        : BaseExpression(parseContext)
    {
        FunctionExpr = std::move(functionExpr);
        FunctionArguments = std::move(arguments);
    }

    CodeGenResult FunctionCallExpression::Generate(CodeGenContext &cc)
    {
        // Generate scope
        GeneratedScope generatedScope = cc.Scope;
        //for (const auto& expr: Scope.Bindings) {
        //    Assert(generatedScope.Bindings.find(expr.first) == generatedScope.Bindings.end(),
        //           "Conflicting binding name in form scope");
        //
        //    CodeGenContext localContext = {
        //        generatedScope,
        //        cc.Builder, cc.Module, cc.Context
        //    };
        //    generatedScope.Bindings.insert(std::make_pair(expr.first, expr.second->Generate(localContext)));
        //}

        CodeGenContext localContext = {
            std::move(generatedScope),
            cc.Builder, cc.Module, cc.Context
        };

        // TODO: This is generating arguments BEFORE resolving function name. Is it correct?
        std::vector<llvm::Value*> argumentValues;
        std::vector<llvm::Type*> argumentTypes;
        for (size_t i = 0; i < FunctionArguments.size(); ++i) {
            CodeGenResult argumentValue = FunctionArguments[i]->Generate(localContext);
            Assert(argumentValue.NumValues == 1,
                   "Passing overloaded values to function calls is not supported(yet)");

            argumentValues.emplace_back(argumentValue.Values[0]);
            argumentTypes.emplace_back(argumentValue.Values[0]->getType());
        }

        // Generate body
        Assert(FunctionExpr != nullptr, "Empty function call");
        CodeGenResult generatedValue = FunctionExpr->Generate(localContext);

        Assert(generatedValue.NumValues > 0,
               "Function has no overloads");

        // Pick default overload
        llvm::Value* selectedValue = generatedValue.Values[0];

        // Find compatible overload
        for (size_t i = 0; i < generatedValue.NumValues; ++i) {
            selectedValue = generatedValue.Values[i];
            llvm::Type* valueType = selectedValue->getType();

            bool isFunction = valueType->isPointerTy() && valueType->getPointerElementType()->isFunctionTy();
            Assert(isFunction, "Function expected");

            llvm::FunctionType* functionType = static_cast<llvm::FunctionType*>(valueType->getPointerElementType());
            if (functionType->getNumParams() == argumentTypes.size()) {
                for (size_t argumentIndex = 0; argumentIndex < argumentTypes.size(); ++argumentIndex) {
                    llvm::Type* argumentType = *(functionType->param_begin() + argumentIndex);
                    if (!IsSafeTypeCastPossible(argumentValues[argumentIndex], argumentType)) {
                        selectedValue = nullptr;
                        break;
                    }
                }
            }
        }

        // Generate error message if needed
        if (selectedValue == nullptr) {
            std::string argumentsString;
            std::string candidates;

            argumentsString += FunctionExpr->ParseContext.Source;
            argumentsString += "( ";
            for (llvm::Type* type: argumentTypes) {
                argumentsString += GetTypeName(type);
                argumentsString += " ";
            }
            argumentsString += ")";

            for (size_t i = 0; i < generatedValue.NumValues; ++i) {
                llvm::Value* value = generatedValue.Values[i];
                llvm::Type* valueType = value->getType();

                llvm::FunctionType* functionType = static_cast<llvm::FunctionType*>(valueType->getPointerElementType());

                candidates += FunctionExpr->ParseContext.Source;
                candidates += "( ";
                for (llvm::Type* type: functionType->params()) {
                    candidates += GetTypeName(type);
                    candidates +=  + " ";
                }
                candidates += ")\n";
            }

            std::string errorMessage = llvm::formatv("Could not find matching function for call to \""
                                                     "{0}\", candidates are:\n{1}", argumentsString, candidates);
            Assert(false, errorMessage);
        }

        // Generate code
        llvm::Type* valueType = selectedValue->getType();
        bool isFunction = valueType->isPointerTy() && valueType->getPointerElementType()->isFunctionTy();
        Assert(isFunction, "Function expected");

        llvm::FunctionType* functionType = static_cast<llvm::FunctionType*>(valueType->getPointerElementType());
        //if (FunctionArguments.size() != functionType->getNumParams()) {
        //    std::string errorMessage = llvm::formatv("Function \"{0}\" expects {1} arguments, not {2}",
        //                                             ToLLVM(FunctionExpr->ParseContext.Source),
        //                                             FunctionArguments.size(),
        //                                             functionType->getNumParams());
        //    Assert(false, errorMessage);
        //}

        for (size_t i = 0; i < FunctionArguments.size(); ++i) {
            llvm::Type* expectedType = *(functionType->param_begin() + i);
            argumentValues[i] = GenerateSafeTypeCast(argumentValues[i], expectedType);
        }

        LocalValue = cc.Builder->CreateCall(selectedValue, argumentValues);
        return CodeGenResult(&LocalValue);
    }

    void FunctionCallExpression::DebugPrint(int indent)
    {
        BaseExpression::DebugPrint(indent);
        if (FunctionExpr) {
            FunctionExpr->DebugPrint(indent + 1);
            for (auto& arg: FunctionArguments) {
                arg->DebugPrint(indent + 1);
            }
        }
    }

    //-----------------------------------------------------------------------------------------------------------------
    // Let
    LetExpression::LetExpression(SourceParseContext parseContext,
                                 std::unordered_map<std::string_view, Binding>&& bindings,
                                 std::vector<BaseExpressionPtr> &&body)
        : BaseExpression(parseContext)
    {
        Bindings = std::move(bindings);
        Body = std::move(body);
    }

    CodeGenResult LetExpression::Generate(CodeGenContext &cc)
    {
        // Generate bindings
        GeneratedScope localScope = cc.Scope;
        LocalBindingValues.reserve(Bindings.size());
        for (auto& binding : Bindings) {
            std::string_view bindingName = binding.first;

            auto itr = localScope.Bindings.find(bindingName);
            Assert(itr == localScope.Bindings.end(), "Conflicting binding name");

            ExpressionQualifiers qualifiers = binding.second.Qualifiers;

            CodeGenResult generatedBinding = binding.second.Body->Generate(cc);
            Assert(generatedBinding.NumValues == 1,
                   "Declaring local overloaded values is not supported(yet)");

            llvm::Value* bindingValue = generatedBinding.Values[0];
            llvm::Type* bindingType = bindingValue->getType();

            if (bindingType->isStructTy() || qualifiers.IsMutable) {// || !llvm::Constant::classof(bindingValue)) {
                llvm::Value* bindingAlloc = cc.Builder->CreateAlloca(bindingValue->getType());
                cc.Builder->CreateStore(bindingValue, bindingAlloc);
                bindingValue = bindingAlloc;
            }

            LocalBindingValues.emplace_back(bindingValue);

            CodeGenResult generatedBindingValue;
            generatedBindingValue.Values = &LocalBindingValues.back();
            generatedBindingValue.NumValues = 1;

            localScope.Bindings.insert(itr, { bindingName, generatedBindingValue });
        }

        // Generate body
        CodeGenContext localContext = {
            std::move(localScope),
            cc.Builder, cc.Module, cc.Context
        };

        CodeGenResult value = {};
        for (auto& body: Body) {
            value = body->Generate(localContext);
        }

        return value;
    }

    void LetExpression::DebugPrint(int indent)
    {
        BaseExpression::DebugPrint(indent);
        for (auto& expr: Bindings) {
            expr.second.Body->DebugPrint(indent + 1);
        }
        for (auto& body: Body) {
            body->DebugPrint(indent + 1);
        }
    }

    //-----------------------------------------------------------------------------------------------------------------
    // Set
    SetExpression::SetExpression(SourceParseContext parseContext,
                                 BaseExpressionPtr mutableValue, BaseExpressionPtr expression)
        : BaseExpression(parseContext)
    {
        MutableValue = std::move(mutableValue);
        Expression = std::move(expression);
    }

    CodeGenResult SetExpression::Generate(CodeGenContext &cc)
    {
        CodeGenResult generatedMutableValue = MutableValue->Generate(cc);
        CodeGenResult generatedExpression = Expression->Generate(cc);

        Assert(generatedMutableValue.NumValues == 1 && generatedExpression.NumValues == 1,
               "Assignment to overloaded values is not supported(yet)");

        llvm::Value* mutableValue = generatedMutableValue.Values[0];
        llvm::Value* expression = generatedExpression.Values[0];

        Assert(llvm::AllocaInst::classof(mutableValue) || llvm::GetElementPtrInst::classof(mutableValue),
               "(set) expects a mutable value");

        llvm::Type* desiredType = mutableValue->getType()->getPointerElementType();

        cc.Builder->CreateStore(GenerateSafeTypeCast(expression, desiredType), mutableValue);

        LocalValue = expression;
        return CodeGenResult(&LocalValue);
    }

    //-----------------------------------------------------------------------------------------------------------------
    // Literal
    // TODO: Refactor strings
    static llvm::Value* MakeStringLiteral(llvm::Module *module, llvm::LLVMContext &context, std::string_view value)
    {
        llvm::ArrayType* type = llvm::ArrayType::get(llvm::Type::getInt8Ty(context), value.size() + 1);
        llvm::Constant* constant = llvm::ConstantDataArray::getString(context, ToLLVM(value), true);
        llvm::GlobalValue* variable = new llvm::GlobalVariable(*module, type,
                                                               true, llvm::GlobalValue::InternalLinkage,
                                                               constant, "__str_literal");

        return variable;
     }

    LiteralExpression::LiteralExpression(SourceParseContext parseContext,
                                         LiteralType type)
        : BaseExpression(parseContext)
    {
        Type = type;
        RawValue = parseContext.Source;
    }

    CodeGenResult LiteralExpression::Generate(CodeGenContext& cc)
    {
        llvm::Value* value = nullptr;

        switch (Type) {
            case Integer: {
                llvm::IntegerType* type = llvm::Type::getInt128Ty(*cc.Context);
                value = llvm::ConstantInt::get(type, ToLLVM(RawValue), 10);
            } break;

            case Float: {
                llvm::Type* type = llvm::Type::getDoubleTy(*cc.Context);
                value = llvm::ConstantFP::get(type, ToLLVM(RawValue));
            } break;

            case String: {
                value = MakeStringLiteral(cc.Module, *cc.Context, RawValue);

                // TODO: refactor strings and arrays
                llvm::Value* indices[] = {
                    llvm::ConstantInt::get(llvm::Type::getInt64Ty(*cc.Context), 0),
                    llvm::ConstantInt::get(llvm::Type::getInt64Ty(*cc.Context), 0),
                };
                value = cc.Builder->CreateGEP(value->getType()->getContainedType(0),
                                              value, indices);
            } break;

            default: {
                Assert(false, "Unsupported literal type");
            } break;
        }

        LocalValue = value;
        return CodeGenResult(&LocalValue);
    }

    //-----------------------------------------------------------------------------------------------------------------
    // Value
    ValueExpression::ValueExpression(SourceParseContext parseContext, bool dereferencePointer)
        : BaseExpression(parseContext)
    {
        Value = parseContext.Source;
        DereferencePointer = dereferencePointer;
    }

    CodeGenResult ValueExpression::Generate(CodeGenContext &cc)
    {
        std::string_view symbolName = Value;
        size_t dotIndex = Value.find_first_of('.');

        // TODO: refactor scopes
        std::string_view rootSymbolName = symbolName;
        if (dotIndex != std::string_view::npos) {
            rootSymbolName = symbolName.substr(0, dotIndex);
        }
        auto itr = cc.Scope.Bindings.find(rootSymbolName);
        Assert(itr != cc.Scope.Bindings.end(), "Unknown identifier");

        CodeGenResult generatedValue = (*itr).second;

        // Try to resolve the name if it's not overloaded
        if (generatedValue.NumValues == 1) {
            llvm::Value* value = generatedValue.Values[0];
            llvm::Type* valueType = value->getType();

            while (dotIndex != std::string_view::npos) {
                Assert(generatedValue.NumValues == 1,
                       "Struct member overloading is not supported(yet)");

                Assert(valueType->getContainedType(0)->isStructTy(), "Value does not seem to be a struct");

                symbolName = symbolName.substr(dotIndex + 1, std::string_view::npos);
                dotIndex = symbolName.find_first_of('.');

                std::string_view memberName = symbolName;
                if (dotIndex != std::string_view::npos) {
                    memberName = memberName.substr(0, dotIndex);
                }

                auto typeInfoItr = cc.Scope.TypeInfoMap.find(valueType->getContainedType(0));
                if (typeInfoItr == cc.Scope.TypeInfoMap.end()) {
                    std::string errorMessage = llvm::formatv("Value \"{0}\" does not seem to be a struct",
                                                             ToLLVM(memberName));
                    Assert(false, errorMessage);
                }

                StructTypeInfo& typeInfo = (*typeInfoItr).second;
                auto memberItr = typeInfo.Members.find(memberName);

                if (memberItr == typeInfo.Members.end()) {
                    std::string errorMessage = llvm::formatv("No member named \"{0}\" found for struct \"{1}\"",
                                                             ToLLVM(memberName), valueType->getContainedType(0)->getStructName());
                    Assert(false, errorMessage);
                }
                StructTypeInfo::Member& member = (*memberItr).second;

                value = cc.Builder->CreateStructGEP(value, member.Index);
                valueType = value->getType();
            }

            // TODO: refactor strings and arrays
            if (valueType->isPointerTy() && value->getType()->getContainedType(0)->isArrayTy()) {
                llvm::Value* indices[] = {
                    llvm::ConstantInt::get(llvm::Type::getInt64Ty(*cc.Context), 0),
                    llvm::ConstantInt::get(llvm::Type::getInt64Ty(*cc.Context), 0),
                };
                LocalValue = cc.Builder->CreateGEP(value->getType()->getContainedType(0),
                                                   value, indices);
                return CodeGenResult(&LocalValue);
            }

            if (DereferencePointer && (llvm::AllocaInst::classof(value) || llvm::GetElementPtrInst::classof(value))) {
                LocalValue = cc.Builder->CreateLoad(value);
                return CodeGenResult(&LocalValue);
            }

            LocalValue = value;
            return CodeGenResult(&LocalValue);
        }

        // Return it as-is in case it's overloaded
        return generatedValue;
    }

    //-----------------------------------------------------------------------------------------------------------------
    // TypeCast
    TypeCastExpression::TypeCastExpression(SourceParseContext parseContext,
                                           ExpressionType desiredType,
                                           BaseExpressionPtr &&originalExpression)
        : BaseExpression(parseContext)
    {
        DesiredType = desiredType;
        OriginalExpression = std::move(originalExpression);
    }

    CodeGenResult TypeCastExpression::Generate(CodeGenContext &cc)
    {
        llvm::Type* generatedType = ResolveType(DesiredType, cc.Scope);
        CodeGenResult generatedValue = OriginalExpression->Generate(cc);

        Assert(generatedValue.NumValues == 1,
               "Type cast expressions are not supported on overloaded values(yet)");

        // TODO: Support unsafe type casts too
        LocalValue = GenerateSafeTypeCast(generatedValue.Values[0], generatedType);
        return CodeGenResult(&LocalValue);
    }

    //-----------------------------------------------------------------------------------------------------------------
    // LoopExpression
    LoopExpression::LoopExpression(SourceParseContext parseContext,
                                   std::vector<BindingExpression> &&bindings,
                                   std::vector<BaseExpressionPtr> &&body)
        : BaseExpression(parseContext)
    {
        Bindings = std::move(bindings);
        Body = std::move(body);
    }

    CodeGenResult LoopExpression::Generate(CodeGenContext &cc)
    {
        llvm::BasicBlock* parentBlock = cc.Builder->GetInsertBlock();
        llvm::Function* parentFunction = parentBlock->getParent();

        //llvm::BasicBlock* loopStart = llvm::BasicBlock::Create(*cc.Context, "loop_init", parentFunction);
        llvm::BasicBlock* loopBlock = llvm::BasicBlock::Create(*cc.Context, "loop_body", parentFunction);
        llvm::BasicBlock* nextBlock = llvm::BasicBlock::Create(*cc.Context, "loop_next", parentFunction);

        // Generate bindings
        struct GeneratedBinding
        {
            std::string_view    Name;
            llvm::Value*        Value;
        };
        std::vector<GeneratedBinding> generatedBindings;

        LocalTempValues.reserve(Bindings.size() * 3); // TODO: OMFG this is ugly

        // Generate initial stores and conditions
        {
            GeneratedScope localScope = cc.Scope;
            for (auto& binding : Bindings) {
                std::string_view bindingName = binding.Name;

                auto itr = localScope.Bindings.find(bindingName);
                Assert(itr == localScope.Bindings.end(), "Conflicting binding name");

                CodeGenResult generatedBinding = binding.InitialValue->Generate(cc);
                Assert(generatedBinding.NumValues == 1,
                       "Overloaded values are not supported in loop control blocks(yet)");

                llvm::Value* bindingValue = generatedBinding.Values[0];

                llvm::Type* bindingType = ResolveType(binding.DesiredType, localScope);
                bindingValue = GenerateSafeTypeCast(bindingValue, bindingType);

                llvm::Value* bindingAlloc = cc.Builder->CreateAlloca(bindingValue->getType());
                cc.Builder->CreateStore(bindingValue, bindingAlloc);

                generatedBindings.push_back({ bindingName, bindingAlloc });
                LocalTempValues.emplace_back(bindingValue);

                CodeGenResult generatedBindingValue;
                generatedBindingValue.Values = &LocalTempValues.back();
                generatedBindingValue.NumValues = 1;

                localScope.Bindings.insert({}, { bindingName, generatedBindingValue });
            }

            CodeGenContext localContext = {
                std::move(localScope),
                cc.Builder, cc.Module, cc.Context
            };

            llvm::Value* loopCondition = nullptr;
            for (size_t i = 0; i < Bindings.size(); ++i) {
                CodeGenResult generatedCondition = Bindings[i].ExitCondition->Generate(localContext);
                Assert(generatedCondition.NumValues == 1,
                       "Overloaded values are not supported in loop control blocks(yet)");

                llvm::Value* bindingCondition = generatedCondition.Values[0];
                Assert(bindingCondition->getType()->isIntegerTy(), "Boolean or integer expected");

                loopCondition = loopCondition == nullptr ?
                          bindingCondition : cc.Builder->CreateAnd(loopCondition, bindingCondition);
            }

            cc.Builder->CreateCondBr(loopCondition, loopBlock, nextBlock);
        }

        // Generate body
        CodeGenResult bodyValue = {};
        {
            GeneratedScope localScope = cc.Scope;

            // Update blocks
            localScope.RootBlock = loopBlock;
            cc.Builder->SetInsertPoint(loopBlock);

            // Generate scope and loads
            for (size_t i = 0; i < Bindings.size(); ++i) {
                auto itr = localScope.Bindings.find(generatedBindings[i].Name);
                Assert(itr == localScope.Bindings.end(), "Conflicting binding name");

                llvm::Value* bindingLoad = cc.Builder->CreateLoad(generatedBindings[i].Value);
                LocalTempValues.emplace_back(bindingLoad);

                CodeGenResult generatedBinding;
                generatedBinding.Values = &LocalTempValues.back();
                generatedBinding.NumValues = 1;

                localScope.Bindings.insert(itr, { generatedBindings[i].Name, generatedBinding });
            }

            CodeGenContext localContext = {
                std::move(localScope),
                cc.Builder, cc.Module, cc.Context
            };

            // Generate actual body
            for (size_t i = 0; i < Body.size(); ++i) {
                bodyValue = Body[i]->Generate(localContext);
            }

            // Generate steps and stores
            // TODO: Get rid of this copy-paste
            {
                GeneratedScope localScope = cc.Scope;

                for (size_t i = 0; i < Bindings.size(); ++i) {
                    CodeGenResult generatedStep = Bindings[i].Body->Generate(localContext);
                    Assert(generatedStep.NumValues == 1,
                           "Overloaded values are not supported in loop control blocks(yet)");

                    llvm::Value* stepValue = generatedStep.Values[0];
                    Assert(stepValue->getType() == generatedBindings[i].Value->getType()->getContainedType(0),
                           "Type mismatch, loop step value type should match the corresponding binding type");
                    cc.Builder->CreateStore(stepValue, generatedBindings[i].Value);

                    auto itr = localScope.Bindings.find(generatedBindings[i].Name);
                    Assert(itr == localScope.Bindings.end(), "Conflicting binding name");

                    LocalTempValues.emplace_back(stepValue);

                    CodeGenResult generatedStepValue;
                    generatedStepValue.Values = &LocalTempValues.back();
                    generatedStepValue.NumValues = 1;

                    localScope.Bindings.insert(itr, { generatedBindings[i].Name, generatedStepValue });
                }

                CodeGenContext localContext = {
                    std::move(localScope),
                    cc.Builder, cc.Module, cc.Context
                };

                llvm::Value* loopCondition = nullptr;
                for (size_t i = 0; i < Bindings.size(); ++i) {
                    CodeGenResult generatedCondition = Bindings[i].ExitCondition->Generate(localContext);
                    Assert(generatedCondition.NumValues == 1,
                           "Overloaded values are not supported in loop control blocks(yet)");

                    llvm::Value* bindingCondition = generatedCondition.Values[0];
                    Assert(bindingCondition->getType()->isIntegerTy(), "Boolean or integer expected");

                    loopCondition = loopCondition == nullptr ?
                              bindingCondition : cc.Builder->CreateAnd(loopCondition, bindingCondition);
                }

                // Create branches
                cc.Builder->CreateCondBr(loopCondition, loopBlock, nextBlock);
            }
        }

        Assert(LocalTempValues.size() == Bindings.size() * 3,
               "Something went wrong with LocalTempValues, double-check reserved size");
        Assert(bodyValue.NumValues == 1,
               "Using overloaded values for loop return statements is not supported(yet)");

        // This is the second place that modifies the insert point and does not restore it back
        cc.Builder->SetInsertPoint(nextBlock);
        cc.Scope.RootBlock = nextBlock;

        // TODO: This block juggling results in weird jumps in generated IR code, needs to be fixed. This could also be caused by LLVM debug printing which sorts blocks in a weird order.

        llvm::Type* desiredType = bodyValue.Values[0]->getType();
        llvm::PHINode* phi = cc.Builder->CreatePHI(desiredType, 1);
        phi->addIncoming(bodyValue.Values[0], loopBlock);

        // PHINode should have one entry for each predecessor of its parent basic block
        //  this means that we have to provide some sensible default value. Let it be zero
        llvm::Value* nullValue = llvm::Constant::getNullValue(desiredType);
        phi->addIncoming(nullValue, parentBlock);

        LocalValue = phi;
        return CodeGenResult(&LocalValue);
    }

    //-----------------------------------------------------------------------------------------------------------------
    // Struct

    StructExpression::StructExpression(SourceParseContext parseContext,
                                       std::vector<Member> &&members)
        : BaseExpression(parseContext)
    {
        Members = std::move(members);
    }

    CodeGenResult StructExpression::Generate(CodeGenContext &cc)
    {
        // Create struct type
        StructTypeInfo typeInfo;
        std::vector<llvm::Type*> memberTypes;
        for (size_t i = 0; i < Members.size(); ++i) {
            llvm::Type* memberType = ResolveType(Members[i].Type, cc.Scope);
            memberTypes.emplace_back(memberType);
            typeInfo.Members[Members[i].Name] = { unsigned(i), memberType };
        }

        llvm::Type* structType = llvm::StructType::create(*cc.Context, memberTypes,
                                                          ToLLVM(ParseContext.Source));
        cc.Scope.TypeInfoMap.insert(std::make_pair(structType, std::move(typeInfo)));

        Assert(cc.Scope.Types.find(ParseContext.Source) == cc.Scope.Types.end(),
               "Duplicated struct name");
        cc.Scope.Types.insert(std::make_pair(ParseContext.Source, structType));

        // Create constructor
        llvm::FunctionType* functionType = llvm::FunctionType::get(structType, memberTypes, false);
        llvm::Function* functionValue = llvm::Function::Create(functionType, llvm::Function::InternalLinkage,
                                                               ToLLVM(ParseContext.Source), cc.Module);

        llvm::BasicBlock* block = llvm::BasicBlock::Create(*cc.Context, "__funcbody", functionValue);
        cc.Builder->SetInsertPoint(block);

        llvm::Value* structAlloc = cc.Builder->CreateAlloca(structType);
        for (size_t i = 0; i < memberTypes.size(); ++i) {
            llvm::Value* memberPtr = cc.Builder->CreateStructGEP(structAlloc, unsigned(i));
            cc.Builder->CreateStore(functionValue->arg_begin() + i, memberPtr);
        }
        llvm::Value* structLoad = cc.Builder->CreateLoad(structAlloc);
        cc.Builder->CreateRet(structLoad);

        LocalValue = functionValue;
        CodeGenResult generatedFunctionValue(&LocalValue);

        cc.Scope.Bindings.insert(std::make_pair(ParseContext.Source, generatedFunctionValue));
        return generatedFunctionValue;
        //return structType;
    }
}
