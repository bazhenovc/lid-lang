
// Generated from .\lid.g by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "lidParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by lidParser.
 */
class  lidVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by lidParser.
   */
    virtual antlrcpp::Any visitProgram(lidParser::ProgramContext *context) = 0;

    virtual antlrcpp::Any visitToplevel(lidParser::ToplevelContext *context) = 0;

    virtual antlrcpp::Any visitNamedFunction(lidParser::NamedFunctionContext *context) = 0;

    virtual antlrcpp::Any visitNamedConstant(lidParser::NamedConstantContext *context) = 0;

    virtual antlrcpp::Any visitNamedStruct(lidParser::NamedStructContext *context) = 0;

    virtual antlrcpp::Any visitStructMember(lidParser::StructMemberContext *context) = 0;

    virtual antlrcpp::Any visitExpression(lidParser::ExpressionContext *context) = 0;

    virtual antlrcpp::Any visitConstant(lidParser::ConstantContext *context) = 0;

    virtual antlrcpp::Any visitSymbolReference(lidParser::SymbolReferenceContext *context) = 0;

    virtual antlrcpp::Any visitCallable(lidParser::CallableContext *context) = 0;

    virtual antlrcpp::Any visitParameter(lidParser::ParameterContext *context) = 0;

    virtual antlrcpp::Any visitLambda(lidParser::LambdaContext *context) = 0;

    virtual antlrcpp::Any visitTypedParameter(lidParser::TypedParameterContext *context) = 0;

    virtual antlrcpp::Any visitLet(lidParser::LetContext *context) = 0;

    virtual antlrcpp::Any visitTypedValueBinding(lidParser::TypedValueBindingContext *context) = 0;

    virtual antlrcpp::Any visitTypedValueQualifier(lidParser::TypedValueQualifierContext *context) = 0;

    virtual antlrcpp::Any visitTypeName(lidParser::TypeNameContext *context) = 0;

    virtual antlrcpp::Any visitRegularTypeName(lidParser::RegularTypeNameContext *context) = 0;

    virtual antlrcpp::Any visitFunctionTypeName(lidParser::FunctionTypeNameContext *context) = 0;

    virtual antlrcpp::Any visitSet(lidParser::SetContext *context) = 0;

    virtual antlrcpp::Any visitBranch(lidParser::BranchContext *context) = 0;

    virtual antlrcpp::Any visitBranchCondition(lidParser::BranchConditionContext *context) = 0;

    virtual antlrcpp::Any visitBranchBegin(lidParser::BranchBeginContext *context) = 0;

    virtual antlrcpp::Any visitBranchItem(lidParser::BranchItemContext *context) = 0;

    virtual antlrcpp::Any visitBranchEnd(lidParser::BranchEndContext *context) = 0;

    virtual antlrcpp::Any visitLoop(lidParser::LoopContext *context) = 0;

    virtual antlrcpp::Any visitLoopBindingExpression(lidParser::LoopBindingExpressionContext *context) = 0;

    virtual antlrcpp::Any visitBinary(lidParser::BinaryContext *context) = 0;

    virtual antlrcpp::Any visitBinaryOperator(lidParser::BinaryOperatorContext *context) = 0;


};

