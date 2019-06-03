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

#pragma once

#pragma warning(push)
#pragma warning(disable:4146)
#pragma warning(disable:4141)
#pragma warning(disable:4244)
#pragma warning(disable:4267)
#pragma warning(disable:4291)
#pragma warning(disable:4624)
#pragma warning(disable:4996)
#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS  1

#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/BasicBlock.h>

#include <llvm/ADT/StringRef.h>

#include <llvm/Bitcode/BitcodeReader.h>
#include <llvm/Bitcode/BitcodeWriter.h>

#undef _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
#pragma warning(pop)

#include "ast.hh"

#include "generated/lidVisitor.h"
#include "generated/lidParser.h"
#include "generated/lidLexer.h"

#include <fstream>
#include <iostream>
#include <stack>
#include <string_view>

class ModuleBuilder : public lidVisitor
{
public:

    struct CodeGenResult
    {
        std::unique_ptr<llvm::Module>       Module;
        std::unique_ptr<llvm::IRBuilder<>>  Builder;
    };

    // TODO: Implement a proper scope stack
    AST::ExpressionScope RootScope;

    CodeGenResult ParseAndGenerate(std::string_view inFile, llvm::LLVMContext* LLVMContext,
                                   lidParser::ProgramContext *context);

    virtual antlrcpp::Any visitProgram(lidParser::ProgramContext *context) override;

    virtual antlrcpp::Any visitToplevel(lidParser::ToplevelContext *context) override;

    virtual antlrcpp::Any visitNamedFunction(lidParser::NamedFunctionContext *context) override;

    virtual antlrcpp::Any visitNamedConstant(lidParser::NamedConstantContext *context) override;

    virtual antlrcpp::Any visitNamedStruct(lidParser::NamedStructContext *context) override;

    virtual antlrcpp::Any visitStructMember(lidParser::StructMemberContext *context) override;

    virtual antlrcpp::Any visitExpression(lidParser::ExpressionContext *context) override;

    virtual antlrcpp::Any visitConstant(lidParser::ConstantContext *context) override;

    virtual antlrcpp::Any visitSymbolReference(lidParser::SymbolReferenceContext *context) override;

    virtual antlrcpp::Any visitCallable(lidParser::CallableContext *context) override;

    virtual antlrcpp::Any visitParameter(lidParser::ParameterContext *context) override;

    virtual antlrcpp::Any visitLambda(lidParser::LambdaContext *context) override;

    virtual antlrcpp::Any visitTypedParameter(lidParser::TypedParameterContext *context) override;

    virtual antlrcpp::Any visitLet(lidParser::LetContext *context) override;

    virtual antlrcpp::Any visitTypedValueBinding(lidParser::TypedValueBindingContext *context) override;

    virtual antlrcpp::Any visitTypedValueQualifier(lidParser::TypedValueQualifierContext *context) override;

    virtual antlrcpp::Any visitTypeName(lidParser::TypeNameContext *context) override;

    virtual antlrcpp::Any visitRegularTypeName(lidParser::RegularTypeNameContext *context) override;

    virtual antlrcpp::Any visitFunctionTypeName(lidParser::FunctionTypeNameContext *context) override;

    virtual antlrcpp::Any visitSet(lidParser::SetContext *context) override;

    virtual antlrcpp::Any visitBranch(lidParser::BranchContext *context) override;

    virtual antlrcpp::Any visitBranchCondition(lidParser::BranchConditionContext *context) override;

    virtual antlrcpp::Any visitBranchBegin(lidParser::BranchBeginContext *context) override;

    virtual antlrcpp::Any visitBranchItem(lidParser::BranchItemContext *context) override;

    virtual antlrcpp::Any visitBranchEnd(lidParser::BranchEndContext *context) override;

    virtual antlrcpp::Any visitLoop(lidParser::LoopContext *context) override;

    virtual antlrcpp::Any visitLoopBindingExpression(lidParser::LoopBindingExpressionContext *context) override;

    virtual antlrcpp::Any visitBinary(lidParser::BinaryContext *context) override;

    virtual antlrcpp::Any visitBinaryOperator(lidParser::BinaryOperatorContext *context) override;

    virtual antlrcpp::Any visitUnary(lidParser::UnaryContext *context) override;

    virtual antlrcpp::Any visitUnaryOperator(lidParser::UnaryOperatorContext *context) override;

private:

    std::list<std::string> mCopiedStrings; // TODO: Refactor this

    template <typename T>
    std::string_view CopyString(T* antlrObject)
    {
        if (antlrObject != nullptr) {
            mCopiedStrings.emplace_back(antlrObject->getText());
            return mCopiedStrings.back();
        }
        return std::string_view();
    }
};
