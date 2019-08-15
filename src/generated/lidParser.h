
// Generated from .\lid.g by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  lidParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
    T__20 = 21, T__21 = 22, T__22 = 23, T__23 = 24, T__24 = 25, T__25 = 26, 
    T__26 = 27, T__27 = 28, T__28 = 29, T__29 = 30, T__30 = 31, T__31 = 32, 
    T__32 = 33, T__33 = 34, T__34 = 35, WHITESPACE = 36, POINTER_PREFIX = 37, 
    IDENTIFIER = 38, FLOAT_LITERAL = 39, INTEGER_LITERAL = 40, STRING_LITERAL = 41, 
    LINE_COMMENT = 42
  };

  enum {
    RuleProgram = 0, RuleToplevel = 1, RuleNamedFunction = 2, RuleNamedConstant = 3, 
    RuleNamedStruct = 4, RuleStructMember = 5, RuleExpression = 6, RuleSymbolName = 7, 
    RuleCallable = 8, RuleSymbol = 9, RuleParameter = 10, RuleLambda = 11, 
    RuleTypedParameter = 12, RuleLet = 13, RuleTypedValueBinding = 14, RuleTypedValueQualifier = 15, 
    RuleTypeName = 16, RuleRegularTypeName = 17, RuleFunctionTypeName = 18, 
    RuleSet = 19, RuleBranch = 20, RuleBranchCondition = 21, RuleBranchBegin = 22, 
    RuleBranchItem = 23, RuleBranchEnd = 24, RuleLoop = 25, RuleLoopBindingExpression = 26
  };

  lidParser(antlr4::TokenStream *input);
  ~lidParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class ProgramContext;
  class ToplevelContext;
  class NamedFunctionContext;
  class NamedConstantContext;
  class NamedStructContext;
  class StructMemberContext;
  class ExpressionContext;
  class SymbolNameContext;
  class CallableContext;
  class SymbolContext;
  class ParameterContext;
  class LambdaContext;
  class TypedParameterContext;
  class LetContext;
  class TypedValueBindingContext;
  class TypedValueQualifierContext;
  class TypeNameContext;
  class RegularTypeNameContext;
  class FunctionTypeNameContext;
  class SetContext;
  class BranchContext;
  class BranchConditionContext;
  class BranchBeginContext;
  class BranchItemContext;
  class BranchEndContext;
  class LoopContext;
  class LoopBindingExpressionContext; 

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<ToplevelContext *> toplevel();
    ToplevelContext* toplevel(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramContext* program();

  class  ToplevelContext : public antlr4::ParserRuleContext {
  public:
    ToplevelContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NamedFunctionContext *namedFunction();
    NamedConstantContext *namedConstant();
    NamedStructContext *namedStruct();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ToplevelContext* toplevel();

  class  NamedFunctionContext : public antlr4::ParserRuleContext {
  public:
    NamedFunctionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    TypeNameContext *typeName();
    std::vector<TypedParameterContext *> typedParameter();
    TypedParameterContext* typedParameter(size_t i);
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NamedFunctionContext* namedFunction();

  class  NamedConstantContext : public antlr4::ParserRuleContext {
  public:
    NamedConstantContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    ExpressionContext *expression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NamedConstantContext* namedConstant();

  class  NamedStructContext : public antlr4::ParserRuleContext {
  public:
    NamedStructContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    std::vector<StructMemberContext *> structMember();
    StructMemberContext* structMember(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NamedStructContext* namedStruct();

  class  StructMemberContext : public antlr4::ParserRuleContext {
  public:
    StructMemberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    TypeNameContext *typeName();
    ExpressionContext *expression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StructMemberContext* structMember();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *unaryOperator = nullptr;;
    antlr4::Token *nestedExpression = nullptr;;
    antlr4::Token *binaryOperator = nullptr;;
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    CallableContext *callable();
    SymbolContext *symbol();
    LambdaContext *lambda();
    LetContext *let();
    SetContext *set();
    BranchContext *branch();
    LoopContext *loop();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *POINTER_PREFIX();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpressionContext* expression();
  ExpressionContext* expression(int precedence);
  class  SymbolNameContext : public antlr4::ParserRuleContext {
  public:
    SymbolNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SymbolNameContext* symbolName();

  class  CallableContext : public antlr4::ParserRuleContext {
  public:
    CallableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SymbolNameContext *symbolName();
    std::vector<ParameterContext *> parameter();
    ParameterContext* parameter(size_t i);
    ExpressionContext *expression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CallableContext* callable();

  class  SymbolContext : public antlr4::ParserRuleContext {
  public:
    SymbolContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SymbolNameContext *symbolName();
    antlr4::tree::TerminalNode *FLOAT_LITERAL();
    antlr4::tree::TerminalNode *INTEGER_LITERAL();
    antlr4::tree::TerminalNode *STRING_LITERAL();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SymbolContext* symbol();

  class  ParameterContext : public antlr4::ParserRuleContext {
  public:
    ParameterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParameterContext* parameter();

  class  LambdaContext : public antlr4::ParserRuleContext {
  public:
    LambdaContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeNameContext *typeName();
    std::vector<TypedParameterContext *> typedParameter();
    TypedParameterContext* typedParameter(size_t i);
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LambdaContext* lambda();

  class  TypedParameterContext : public antlr4::ParserRuleContext {
  public:
    TypedParameterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    TypeNameContext *typeName();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypedParameterContext* typedParameter();

  class  LetContext : public antlr4::ParserRuleContext {
  public:
    LetContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TypedValueBindingContext *> typedValueBinding();
    TypedValueBindingContext* typedValueBinding(size_t i);
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LetContext* let();

  class  TypedValueBindingContext : public antlr4::ParserRuleContext {
  public:
    TypedValueBindingContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    ExpressionContext *expression();
    TypeNameContext *typeName();
    TypedValueQualifierContext *typedValueQualifier();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypedValueBindingContext* typedValueBinding();

  class  TypedValueQualifierContext : public antlr4::ParserRuleContext {
  public:
    TypedValueQualifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypedValueQualifierContext* typedValueQualifier();

  class  TypeNameContext : public antlr4::ParserRuleContext {
  public:
    TypeNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    RegularTypeNameContext *regularTypeName();
    FunctionTypeNameContext *functionTypeName();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeNameContext* typeName();

  class  RegularTypeNameContext : public antlr4::ParserRuleContext {
  public:
    RegularTypeNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *POINTER_PREFIX();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RegularTypeNameContext* regularTypeName();

  class  FunctionTypeNameContext : public antlr4::ParserRuleContext {
  public:
    FunctionTypeNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeNameContext *typeName();
    std::vector<TypedParameterContext *> typedParameter();
    TypedParameterContext* typedParameter(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionTypeNameContext* functionTypeName();

  class  SetContext : public antlr4::ParserRuleContext {
  public:
    SetContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SymbolNameContext *symbolName();
    ExpressionContext *expression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SetContext* set();

  class  BranchContext : public antlr4::ParserRuleContext {
  public:
    BranchContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BranchBeginContext *branchBegin();
    BranchEndContext *branchEnd();
    std::vector<BranchItemContext *> branchItem();
    BranchItemContext* branchItem(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BranchContext* branch();

  class  BranchConditionContext : public antlr4::ParserRuleContext {
  public:
    BranchConditionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BranchConditionContext* branchCondition();

  class  BranchBeginContext : public antlr4::ParserRuleContext {
  public:
    BranchBeginContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BranchConditionContext *branchCondition();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BranchBeginContext* branchBegin();

  class  BranchItemContext : public antlr4::ParserRuleContext {
  public:
    BranchItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BranchConditionContext *branchCondition();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BranchItemContext* branchItem();

  class  BranchEndContext : public antlr4::ParserRuleContext {
  public:
    BranchEndContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BranchEndContext* branchEnd();

  class  LoopContext : public antlr4::ParserRuleContext {
  public:
    LoopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<LoopBindingExpressionContext *> loopBindingExpression();
    LoopBindingExpressionContext* loopBindingExpression(size_t i);
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LoopContext* loop();

  class  LoopBindingExpressionContext : public antlr4::ParserRuleContext {
  public:
    LoopBindingExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    TypeNameContext *typeName();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LoopBindingExpressionContext* loopBindingExpression();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool expressionSempred(ExpressionContext *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

