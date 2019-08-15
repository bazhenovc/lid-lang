
// Generated from .\lid.g by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "lidVisitor.h"


/**
 * This class provides an empty implementation of lidVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  lidBaseVisitor : public lidVisitor {
public:

  virtual antlrcpp::Any visitProgram(lidParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitToplevel(lidParser::ToplevelContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNamedFunction(lidParser::NamedFunctionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNamedConstant(lidParser::NamedConstantContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNamedStruct(lidParser::NamedStructContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStructMember(lidParser::StructMemberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpression(lidParser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSymbolName(lidParser::SymbolNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCallable(lidParser::CallableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSymbol(lidParser::SymbolContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameter(lidParser::ParameterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLambda(lidParser::LambdaContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypedParameter(lidParser::TypedParameterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLet(lidParser::LetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypedValueBinding(lidParser::TypedValueBindingContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypedValueQualifier(lidParser::TypedValueQualifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeName(lidParser::TypeNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRegularTypeName(lidParser::RegularTypeNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionTypeName(lidParser::FunctionTypeNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSet(lidParser::SetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBranch(lidParser::BranchContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBranchCondition(lidParser::BranchConditionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBranchBegin(lidParser::BranchBeginContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBranchItem(lidParser::BranchItemContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBranchEnd(lidParser::BranchEndContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLoop(lidParser::LoopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLoopBindingExpression(lidParser::LoopBindingExpressionContext *ctx) override {
    return visitChildren(ctx);
  }


};

