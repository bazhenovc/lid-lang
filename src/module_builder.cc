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

#include "module_builder.hh"

static llvm::StringRef ToLLVM(std::string_view sv)
{
    return llvm::StringRef(sv.data(), sv.size());
}

ModuleBuilder::CodeGenResult ModuleBuilder::ParseAndGenerate(std::string_view inFile,
                                                             llvm::LLVMContext* LLVMContext,
                                                             lidParser::ProgramContext* context)
{
    std::unique_ptr<llvm::Module>       Module;
    std::unique_ptr<llvm::IRBuilder<>>  Builder;

    Module = std::make_unique<llvm::Module>(ToLLVM(inFile), *LLVMContext);
    Builder = std::make_unique<llvm::IRBuilder<>>(*LLVMContext);

    AST::GeneratedScope generatedRootScope;
    generatedRootScope.Types.insert(std::make_pair("void", llvm::Type::getVoidTy(*LLVMContext)));
    generatedRootScope.Types.insert(std::make_pair("boolean", llvm::Type::getInt1Ty(*LLVMContext)));
    generatedRootScope.Types.insert(std::make_pair("f16", llvm::Type::getHalfTy(*LLVMContext)));
    generatedRootScope.Types.insert(std::make_pair("f32", llvm::Type::getFloatTy(*LLVMContext)));
    generatedRootScope.Types.insert(std::make_pair("f64", llvm::Type::getDoubleTy(*LLVMContext)));
    generatedRootScope.Types.insert(std::make_pair("f128", llvm::Type::getFP128Ty(*LLVMContext)));
    generatedRootScope.Types.insert(std::make_pair("i8", llvm::Type::getInt8Ty(*LLVMContext)));
    generatedRootScope.Types.insert(std::make_pair("i16", llvm::Type::getInt16Ty(*LLVMContext)));
    generatedRootScope.Types.insert(std::make_pair("i32", llvm::Type::getInt32Ty(*LLVMContext)));
    generatedRootScope.Types.insert(std::make_pair("i64", llvm::Type::getInt64Ty(*LLVMContext)));
    generatedRootScope.Types.insert(std::make_pair("i128", llvm::Type::getInt128Ty(*LLVMContext)));
    generatedRootScope.Types.insert(std::make_pair("u8", llvm::Type::getInt8Ty(*LLVMContext)));
    generatedRootScope.Types.insert(std::make_pair("u16", llvm::Type::getInt16Ty(*LLVMContext)));
    generatedRootScope.Types.insert(std::make_pair("u32", llvm::Type::getInt32Ty(*LLVMContext)));
    generatedRootScope.Types.insert(std::make_pair("u64", llvm::Type::getInt64Ty(*LLVMContext)));
    generatedRootScope.Types.insert(std::make_pair("u128", llvm::Type::getInt128Ty(*LLVMContext)));
    generatedRootScope.RootBlock = llvm::BasicBlock::Create(*LLVMContext, "__module_main");

    visitProgram(context);

    // Debug print body
    //for (auto& expr: RootScope.Bindings) {
    //    expr.second->DebugPrint(0);
    //}
    //std::cerr.flush();

    // Generate code
    AST::CodeGenContext codeGenContext = {
        generatedRootScope,
        Builder.get(),
        Module.get(),
        LLVMContext,
    };

    // Generate root scope
    for (auto& scopeItem: RootScope.Types) {
        scopeItem.second->Generate(codeGenContext);
    }

    for (auto& scopeItem: RootScope.Bindings) {
        assert(generatedRootScope.Bindings.find(scopeItem.first) == generatedRootScope.Bindings.end()
               && "Conflicting binding name in global scope");

        //scopeItem.second->DebugPrint(0);

        AST::CodeGenResult value = scopeItem.second->Generate(codeGenContext);
        generatedRootScope.Bindings.insert(generatedRootScope.Bindings.end(), std::make_pair(scopeItem.first, value));
    }

    return {
        std::move(Module),
        std::move(Builder)
    };
}

antlrcpp::Any ModuleBuilder::visitProgram(lidParser::ProgramContext* context)
{
    for (lidParser::ToplevelContext* toplevel: context->toplevel()) {
        visitToplevel(toplevel);
    }
    return nullptr;
}

antlrcpp::Any ModuleBuilder::visitToplevel(lidParser::ToplevelContext* context)
{
    lidParser::NamedFunctionContext* namedFunctionContext = context->namedFunction();
    lidParser::NamedConstantContext* namedConstantContext = context->namedConstant();
    lidParser::NamedStructContext* namedStructContext = context->namedStruct();

    if (namedFunctionContext != nullptr) {
        return visitNamedFunction(namedFunctionContext);
    } else if (namedConstantContext != nullptr) {
        return visitNamedConstant(namedConstantContext);
    } else if (namedStructContext != nullptr) {
        return visitNamedStruct(namedStructContext);
    }

    assert(false && "Internal parser error");
    return nullptr;
}

antlrcpp::Any ModuleBuilder::visitNamedFunction(lidParser::NamedFunctionContext *context)
{
    AST::SourceParseContext parseContext = { CopyString(context->IDENTIFIER()), context->getStart()->getLine() };

    lidParser::TypeNameContext* returnTypeName = context->typeName();
    AST::ExpressionType functionReturnType;
    if (returnTypeName != nullptr) {
        functionReturnType = visitTypeName(context->typeName()).as<AST::ExpressionType>();
    } else {
        // TODO: Type inference for function return type
        functionReturnType.TypeName = "void";
        functionReturnType.IsPointer = false;
        functionReturnType.IsFunction = false;
    }

    std::vector<std::string_view> functionArgNames;
    std::vector<AST::ExpressionType> functionArgTypes;

    for (lidParser::TypedParameterContext* typedParam: context->typedParameter()) {
        functionArgNames.emplace_back(CopyString(typedParam->IDENTIFIER()));
        functionArgTypes.emplace_back(visitTypeName(typedParam->typeName()).as<AST::ExpressionType>());
    }

    AST::FunctionExpression::FunctionType signature = {
        std::move(functionArgNames), std::move(functionArgTypes),
        functionReturnType
    };

    std::vector<AST::BaseExpressionPtr> functionBody;
    for (lidParser::ExpressionContext* expr: context->expression()) {
        functionBody.emplace_back(std::move(visitExpression(expr).as<AST::BaseExpressionPtr>()));
    }

    AST::BaseExpressionPtr functionDecl = std::make_unique<AST::FunctionExpression>(
                parseContext, std::move(signature), std::move(functionBody));

    // Add global binding (or append to existing one)
    auto functionBinding = std::find_if(RootScope.Bindings.begin(), RootScope.Bindings.end(),
        [&parseContext](auto& item) { return item.first == parseContext.Source; });

    if (functionBinding == RootScope.Bindings.end()) {
        RootScope.Bindings.emplace_back(std::make_pair(parseContext.Source, std::move(functionDecl)));
    } else {
        // TODO: Refactor without dynamic and static casts
        auto* maybeFunction = dynamic_cast<AST::FunctionExpression*>(functionBinding->second.get());
        if (maybeFunction != nullptr) {
            std::unique_ptr<AST::FunctionExpression> functionPtr(static_cast<AST::FunctionExpression*>(functionDecl.release()));
            maybeFunction->AddOverload(std::move(functionPtr));
        } else {
            assert(false && "Trying to overload something that is not a function");
        }
    }
    return AST::BaseExpressionPtr();
}

antlrcpp::Any ModuleBuilder::visitNamedConstant(lidParser::NamedConstantContext *context)
{
    std::string_view symbolName = CopyString(context->IDENTIFIER());
    AST::BaseExpressionPtr symbolValue = std::move(visitExpression(context->expression()).as<AST::BaseExpressionPtr>());

    RootScope.Bindings.emplace_back(std::make_pair(symbolName, std::move(symbolValue)));
    return AST::BaseExpressionPtr();
}

antlrcpp::Any ModuleBuilder::visitNamedStruct(lidParser::NamedStructContext *context)
{
    std::vector<AST::StructExpression::Member> members;
    for (lidParser::StructMemberContext* memberContext: context->structMember()) {
        members.emplace_back(std::move(visitStructMember(memberContext).as<AST::StructExpression::Member>()));
    }
    AST::SourceParseContext parseContext = { CopyString(context->IDENTIFIER()), context->getStart()->getLine() };
    AST::BaseExpressionPtr structExpr = std::make_unique<AST::StructExpression>(parseContext, std::move(members));

    // Add global binding
    RootScope.Types.emplace_back(std::make_pair(parseContext.Source, std::move(structExpr)));
    return AST::BaseExpressionPtr();
}

antlrcpp::Any ModuleBuilder::visitStructMember(lidParser::StructMemberContext* context)
{
    AST::StructExpression::Member structMember = {
        CopyString(context->IDENTIFIER()),
        visitTypeName(context->typeName()),
        (context->expression() != nullptr) ?
        std::move(visitExpression(context->expression()).as<AST::BaseExpressionPtr>()) : nullptr
    };
    return std::move(structMember);
}

antlrcpp::Any ModuleBuilder::visitExpression(lidParser::ExpressionContext* context)
{
    lidParser::CallableContext* callable = context->callable();
    lidParser::SymbolContext* symbol = context->symbol();
    lidParser::LambdaContext* lambda = context->lambda();
    lidParser::LetContext* let = context->let();
    lidParser::SetContext* set = context->set();
    lidParser::BranchContext* branch = context->branch();
    lidParser::LoopContext* loop = context->loop();

    // Parse general stuff
    if (callable != nullptr) {
        return visitCallable(callable);
    } else if (symbol != nullptr) {
        return visitSymbol(symbol);
    } else if (lambda != nullptr) {
        return visitLambda(lambda);
    } else if (let != nullptr) {
        return visitLet(let);
    } else if (set != nullptr) {
        return visitSet(set);
    } else if (branch != nullptr) {
        return visitBranch(branch);
    } else if (loop != nullptr) {
        return visitLoop(loop);
    }

    // Parse binary operator
    if (context->binaryOperator != nullptr) {
        AST::SourceParseContext parseContext = { CopyString(context->binaryOperator), context->binaryOperator->getLine() };

        auto lhs = std::move(visitExpression(context->expression(0)).as<AST::BaseExpressionPtr>());
        auto rhs = std::move(visitExpression(context->expression(1)).as<AST::BaseExpressionPtr>());

        AST::BaseExpressionPtr binaryOperatorExpr = std::make_unique<AST::BinaryOperatorExpression>(
                    parseContext, std::move(lhs), std::move(rhs));
        return std::move(binaryOperatorExpr);
    }

    // Parse unary operator
    if (context->unaryOperator != nullptr) {
        AST::SourceParseContext parseContext = { CopyString(context->unaryOperator), context->unaryOperator->getLine() };

        auto rhs = std::move(visitExpression(context->expression(0)).as<AST::BaseExpressionPtr>());

        AST::BaseExpressionPtr unaryOperatorExpr = std::make_unique<AST::UnaryOperatorExpression>(
                    parseContext, std::move(rhs));
        return std::move(unaryOperatorExpr);
    }

    // Parse nested expression
    if (context->nestedExpression != nullptr) {
        return visitExpression(context->expression(0));
    }

    assert(false && "Internal parser error, unreachable code reached");
    return nullptr;
}

antlrcpp::Any ModuleBuilder::visitSymbol(lidParser::SymbolContext* context)
{
    auto symbol = context->symbolName();
    auto floatLiteral = context->FLOAT_LITERAL();
    auto integerLiteral = context->INTEGER_LITERAL();
    auto stringLiteral = context->STRING_LITERAL();

    AST::BaseExpressionPtr expr;
    if (symbol != nullptr) {
        expr = std::move(visitSymbolName(symbol).as<AST::BaseExpressionPtr>());
    } else if (floatLiteral != nullptr) {
        AST::SourceParseContext parseContext = { CopyString(floatLiteral), context->getStart()->getLine() };
        expr = std::make_unique<AST::LiteralExpression>(parseContext, AST::LiteralExpression::Float);
    } else if (integerLiteral != nullptr) {
        AST::SourceParseContext parseContext = { CopyString(integerLiteral), context->getStart()->getLine() };
        expr = std::make_unique<AST::LiteralExpression>(parseContext, AST::LiteralExpression::Integer);
    } else if (stringLiteral != nullptr) {
        std::string_view literalString = CopyString(stringLiteral);

        // Remove quotes
        if (!literalString.empty()) {
            assert(literalString[0] == '\"' && literalString[literalString.size() - 1] == '\"');
            assert(literalString.size() >= 2);
            literalString.remove_prefix(1);
            literalString.remove_suffix(1);
        }

        AST::SourceParseContext parseContext = { literalString, context->getStart()->getLine() };
        expr = std::make_unique<AST::LiteralExpression>(parseContext, AST::LiteralExpression::String);
    }
    return std::move(expr);
}

antlrcpp::Any ModuleBuilder::visitSymbolName(lidParser::SymbolNameContext* context)
{
    AST::SourceParseContext parseContext = { CopyString(context), context->getStart()->getLine() };
    AST::BaseExpressionPtr expr = std::make_unique<AST::ValueExpression>(parseContext, true);
    return std::move(expr);
}

antlrcpp::Any ModuleBuilder::visitCallable(lidParser::CallableContext* context)
{
    lidParser::SymbolNameContext* functionSymbol = context->symbolName();
    lidParser::ExpressionContext* functionExpression = context->expression();

    AST::SourceParseContext parseContext;

    AST::BaseExpressionPtr functionExpr;
    if (functionSymbol != nullptr) {
        parseContext = {
            CopyString(functionSymbol->getStart()),
            functionSymbol->getStart()->getLine()
        };
        functionExpr = std::move(visitSymbolName(functionSymbol).as<AST::BaseExpressionPtr>());
    } else if (functionExpression != nullptr) {
        parseContext = {
            CopyString(functionExpression->getStart()),
            functionExpression->getStart()->getLine()
        };
        functionExpr = std::move(visitExpression(context->expression()).as<AST::BaseExpressionPtr>());
    } else { assert(false && "Internal parser error"); }

    std::vector<AST::BaseExpressionPtr> functionParameters;
    for (lidParser::ParameterContext* parameter: context->parameter()) {
        functionParameters.emplace_back(std::move(visitParameter(parameter).as<AST::BaseExpressionPtr>()));
    }

    AST::BaseExpressionPtr functionCall = std::make_unique<AST::FunctionCallExpression>(
                parseContext, std::move(functionExpr), std::move(functionParameters));
    return std::move(functionCall);
}

antlrcpp::Any ModuleBuilder::visitParameter(lidParser::ParameterContext* context)
{
    return visitExpression(context->expression());
}

antlrcpp::Any ModuleBuilder::visitLambda(lidParser::LambdaContext* context)
{
    AST::SourceParseContext parseContext = { "lambda", context->getStart()->getLine() };

    // TODO: Remove copy-paste
    AST::ExpressionType functionReturnType = visitTypeName(context->typeName()).as<AST::ExpressionType>();

    std::vector<std::string_view> functionArgNames;
    std::vector<AST::ExpressionType> functionArgTypes;

    for (lidParser::TypedParameterContext* typedParam: context->typedParameter()) {
        functionArgNames.emplace_back(CopyString(typedParam->IDENTIFIER()));
        functionArgTypes.emplace_back(visitTypeName(typedParam->typeName()).as<AST::ExpressionType>());
    }

    AST::FunctionExpression::FunctionType signature = {
        std::move(functionArgNames), std::move(functionArgTypes),
        functionReturnType
    };

    std::vector<AST::BaseExpressionPtr> functionBody;
    for (lidParser::ExpressionContext* expr: context->expression()) {
        functionBody.emplace_back(std::move(visitExpression(expr).as<AST::BaseExpressionPtr>()));
    }

    AST::BaseExpressionPtr functionDecl = std::make_unique<AST::FunctionExpression>(
                parseContext, std::move(signature), std::move(functionBody));

    return std::move(functionDecl);
}

antlrcpp::Any ModuleBuilder::visitTypedParameter(lidParser::TypedParameterContext* context)
{
    (void)(context);
    assert(false && "Should not be called directly"); // TODO: Refactor this
    return nullptr;
}

antlrcpp::Any ModuleBuilder::visitLet(lidParser::LetContext* context)
{
    AST::SourceParseContext parseContext = { CopyString(context->getStart()), context->getStart()->getLine() };

    std::unordered_map<std::string_view, AST::LetExpression::Binding> letBindings;
    for (lidParser::TypedValueBindingContext* bindingContext: context->typedValueBinding()) {
        std::string_view bindingName = CopyString(bindingContext->IDENTIFIER());
        assert(letBindings.find(bindingName) == letBindings.end() && "Conflicting binding");

        lidParser::TypedValueQualifierContext* typedValueQualifier = bindingContext->typedValueQualifier();

        AST::ExpressionQualifiers bindingQualifiers = typedValueQualifier != nullptr ?
                    visitTypedValueQualifier(typedValueQualifier).as<AST::ExpressionQualifiers>() : AST::ExpressionQualifiers();

        AST::BaseExpressionPtr bindingExpr = std::move(visitTypedValueBinding(bindingContext).as<AST::BaseExpressionPtr>());

        AST::LetExpression::Binding binding = { std::move(bindingExpr), bindingQualifiers };
        letBindings.insert(letBindings.end(), std::make_pair(bindingName, std::move(binding)));
    }

    std::vector<AST::BaseExpressionPtr> letBody;
    for (lidParser::ExpressionContext* expr: context->expression()) {
        letBody.emplace_back(std::move(visitExpression(expr).as<AST::BaseExpressionPtr>()));
    }

    AST::BaseExpressionPtr letExpr = std::make_unique<AST::LetExpression>(
                parseContext, std::move(letBindings), std::move(letBody));
    return std::move(letExpr);
}

antlrcpp::Any ModuleBuilder::visitTypedValueBinding(lidParser::TypedValueBindingContext* context)
{
    lidParser::TypeNameContext* typeName = context->typeName();

    AST::BaseExpressionPtr bindingExpr = std::move(visitExpression(context->expression()).as<AST::BaseExpressionPtr>());
    if (typeName != nullptr) {
        AST::ExpressionType bindingType = visitTypeName(typeName).as<AST::ExpressionType>();

        AST::SourceParseContext parseContext = { CopyString(typeName->getStart()), typeName->getStart()->getLine() };
        bindingExpr = std::make_unique<AST::TypeCastExpression>(parseContext, bindingType, std::move(bindingExpr));
    }

    return std::move(bindingExpr);
}

antlrcpp::Any ModuleBuilder::visitTypedValueQualifier(lidParser::TypedValueQualifierContext *context)
{
    (void)(context);
    AST::ExpressionQualifiers qualifiers = {};
    qualifiers.IsMutable = true; // mutable is the only possible qualifier right now

    return qualifiers;
}

antlrcpp::Any ModuleBuilder::visitTypeName(lidParser::TypeNameContext *context)
{
    lidParser::RegularTypeNameContext* regularTypeName = context->regularTypeName();
    lidParser::FunctionTypeNameContext* functionTypeName = context->functionTypeName();

    if (regularTypeName != nullptr) {
        return visitRegularTypeName(regularTypeName);
    } else if (functionTypeName != nullptr) {
        return visitFunctionTypeName(functionTypeName);
    }

    assert(false && "Internal parser error");
    return nullptr;
}

antlrcpp::Any ModuleBuilder::visitRegularTypeName(lidParser::RegularTypeNameContext* context)
{
    AST::ExpressionType exprType;
    exprType.TypeName = CopyString(context->IDENTIFIER());
    exprType.IsPointer = context->POINTER_PREFIX() != nullptr;
    return std::move(exprType);
}

antlrcpp::Any ModuleBuilder::visitFunctionTypeName(lidParser::FunctionTypeNameContext *context)
{
    AST::ExpressionType exprType;
    exprType.IsPointer = true;
    exprType.IsFunction = true;
    exprType.TypeName = "function";

    exprType.ArgumentTypes.emplace_back(visitTypeName(context->typeName()).as<AST::ExpressionType>());
    for (lidParser::TypedParameterContext* typedParameter: context->typedParameter()) {
        exprType.ArgumentTypes.emplace_back(visitTypeName(typedParameter->typeName()).as<AST::ExpressionType>());
    }

    return std::move(exprType);
}

antlrcpp::Any ModuleBuilder::visitSet(lidParser::SetContext *context)
{
    AST::SourceParseContext valueParseContext = { CopyString(context->symbolName()), context->getStart()->getLine() };
    AST::BaseExpressionPtr mutableValue = std::make_unique<AST::ValueExpression>(valueParseContext, false);
    AST::BaseExpressionPtr expression = std::move(visitExpression(context->expression()).as<AST::BaseExpressionPtr>());

    AST::SourceParseContext parseContext =  { CopyString(context), context->getStart()->getLine() };
    AST::BaseExpressionPtr setExpr = std::make_unique<AST::SetExpression>(parseContext, std::move(mutableValue), std::move(expression));

    return std::move(setExpr);
}

antlrcpp::Any ModuleBuilder::visitBranch(lidParser::BranchContext *context)
{
    AST::SourceParseContext parseContext = { CopyString(context->getStart()), context->getStart()->getLine() };

    std::vector<AST::BranchExpression::ConditionAndValue> branchBody;

    branchBody.emplace_back(std::move(visitBranchBegin(context->branchBegin()).as<AST::BranchExpression::ConditionAndValue>()));
    for (lidParser::BranchItemContext* branchItem: context->branchItem()) {
        branchBody.emplace_back(std::move(visitBranchItem(branchItem).as<AST::BranchExpression::ConditionAndValue>()));
    }
    branchBody.emplace_back(std::move(visitBranchEnd(context->branchEnd()).as<AST::BranchExpression::ConditionAndValue>()));

    AST::BaseExpressionPtr branchExpr = std::make_unique<AST::BranchExpression>(
                parseContext, std::move(branchBody));
    return std::move(branchExpr);
}

antlrcpp::Any ModuleBuilder::visitBranchCondition(lidParser::BranchConditionContext *context)
{
    return visitExpression(context->expression());
}

antlrcpp::Any ModuleBuilder::visitBranchBegin(lidParser::BranchBeginContext *context)
{
    AST::BranchExpression::ConditionAndValue value;
    value.Condition = std::move(visitBranchCondition(context->branchCondition()).as<AST::BaseExpressionPtr>());
    for (lidParser::ExpressionContext* expr: context->expression()) {
        value.Values.emplace_back(std::move(visitExpression(expr).as<AST::BaseExpressionPtr>()));
    }
    return std::move(value);
}

antlrcpp::Any ModuleBuilder::visitBranchItem(lidParser::BranchItemContext *context)
{
    AST::BranchExpression::ConditionAndValue value;
    value.Condition = std::move(visitBranchCondition(context->branchCondition()).as<AST::BaseExpressionPtr>());
    for (lidParser::ExpressionContext* expr: context->expression()) {
        value.Values.emplace_back(std::move(visitExpression(expr).as<AST::BaseExpressionPtr>()));
    }
    return std::move(value);
}

antlrcpp::Any ModuleBuilder::visitBranchEnd(lidParser::BranchEndContext *context)
{
    AST::BranchExpression::ConditionAndValue value;
    value.Condition = AST::BaseExpressionPtr();
    for (lidParser::ExpressionContext* expr: context->expression()) {
        value.Values.emplace_back(std::move(visitExpression(expr).as<AST::BaseExpressionPtr>()));
    }
    return std::move(value);
}

antlrcpp::Any ModuleBuilder::visitLoop(lidParser::LoopContext* context)
{
    std::vector<AST::LoopExpression::BindingExpression> bindings;
    for (lidParser::LoopBindingExpressionContext* bindingContext: context->loopBindingExpression()) {
        AST::LoopExpression::BindingExpression bindingExpr = std::move(visitLoopBindingExpression(bindingContext).as<AST::LoopExpression::BindingExpression>());
        //assert(std::find_if(bindings.begin(), bindings.end(), [bindingExpr->Name](AST::LoopExpression::BindingExpression& val) {
        //    return val.Name == bindingExpr->Name;
        //}) == bindings.end() && "Conflicting binding");

        bindings.emplace_back(std::move(bindingExpr));
    }

    std::vector<AST::BaseExpressionPtr> loopBody;
    for (lidParser::ExpressionContext* bodyContext: context->expression()) {
        loopBody.emplace_back(std::move(visitExpression(bodyContext).as<AST::BaseExpressionPtr>()));
    }

    AST::SourceParseContext parseContext = { CopyString(context->getStart()),
                                             context->getStart()->getLine() };
    AST::BaseExpressionPtr loop = std::make_unique<AST::LoopExpression>(parseContext,
                                                                        std::move(bindings), std::move(loopBody));
    return std::move(loop);
}

antlrcpp::Any ModuleBuilder::visitLoopBindingExpression(lidParser::LoopBindingExpressionContext* context)
{
    AST::LoopExpression::BindingExpression bindingExpression = {
        CopyString(context->IDENTIFIER()),                                               // name
        visitTypeName(context->typeName()).as<AST::ExpressionType>(),                    // desired type
        std::move(visitExpression(context->expression(0)).as<AST::BaseExpressionPtr>()), // initial value
        std::move(visitExpression(context->expression(1)).as<AST::BaseExpressionPtr>()), // exit condition
        std::move(visitExpression(context->expression(2)).as<AST::BaseExpressionPtr>())  // body
    };
    return std::move(bindingExpression);
}
