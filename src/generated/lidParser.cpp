
// Generated from .\lid.g by ANTLR 4.7.2


#include "lidVisitor.h"

#include "lidParser.h"


using namespace antlrcpp;
using namespace antlr4;

lidParser::lidParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

lidParser::~lidParser() {
  delete _interpreter;
}

std::string lidParser::getGrammarFileName() const {
  return "lid.g";
}

const std::vector<std::string>& lidParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& lidParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

lidParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* lidParser::ProgramContext::EOF() {
  return getToken(lidParser::EOF, 0);
}

std::vector<lidParser::ToplevelContext *> lidParser::ProgramContext::toplevel() {
  return getRuleContexts<lidParser::ToplevelContext>();
}

lidParser::ToplevelContext* lidParser::ProgramContext::toplevel(size_t i) {
  return getRuleContext<lidParser::ToplevelContext>(i);
}


size_t lidParser::ProgramContext::getRuleIndex() const {
  return lidParser::RuleProgram;
}


antlrcpp::Any lidParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lidVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

lidParser::ProgramContext* lidParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, lidParser::RuleProgram);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(65);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << lidParser::T__0)
      | (1ULL << lidParser::T__6)
      | (1ULL << lidParser::T__7)
      | (1ULL << lidParser::T__9))) != 0)) {
      setState(62);
      toplevel();
      setState(67);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(68);
    match(lidParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ToplevelContext ------------------------------------------------------------------

lidParser::ToplevelContext::ToplevelContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

lidParser::NamedFunctionContext* lidParser::ToplevelContext::namedFunction() {
  return getRuleContext<lidParser::NamedFunctionContext>(0);
}

lidParser::NamedConstantContext* lidParser::ToplevelContext::namedConstant() {
  return getRuleContext<lidParser::NamedConstantContext>(0);
}

lidParser::NamedStructContext* lidParser::ToplevelContext::namedStruct() {
  return getRuleContext<lidParser::NamedStructContext>(0);
}


size_t lidParser::ToplevelContext::getRuleIndex() const {
  return lidParser::RuleToplevel;
}


antlrcpp::Any lidParser::ToplevelContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lidVisitor*>(visitor))
    return parserVisitor->visitToplevel(this);
  else
    return visitor->visitChildren(this);
}

lidParser::ToplevelContext* lidParser::toplevel() {
  ToplevelContext *_localctx = _tracker.createInstance<ToplevelContext>(_ctx, getState());
  enterRule(_localctx, 2, lidParser::RuleToplevel);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(73);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case lidParser::T__0:
      case lidParser::T__6: {
        setState(70);
        namedFunction();
        break;
      }

      case lidParser::T__7: {
        setState(71);
        namedConstant();
        break;
      }

      case lidParser::T__9: {
        setState(72);
        namedStruct();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NamedFunctionContext ------------------------------------------------------------------

lidParser::NamedFunctionContext::NamedFunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* lidParser::NamedFunctionContext::IDENTIFIER() {
  return getToken(lidParser::IDENTIFIER, 0);
}

lidParser::TypeNameContext* lidParser::NamedFunctionContext::typeName() {
  return getRuleContext<lidParser::TypeNameContext>(0);
}

std::vector<lidParser::TypedParameterContext *> lidParser::NamedFunctionContext::typedParameter() {
  return getRuleContexts<lidParser::TypedParameterContext>();
}

lidParser::TypedParameterContext* lidParser::NamedFunctionContext::typedParameter(size_t i) {
  return getRuleContext<lidParser::TypedParameterContext>(i);
}

std::vector<lidParser::ExpressionContext *> lidParser::NamedFunctionContext::expression() {
  return getRuleContexts<lidParser::ExpressionContext>();
}

lidParser::ExpressionContext* lidParser::NamedFunctionContext::expression(size_t i) {
  return getRuleContext<lidParser::ExpressionContext>(i);
}


size_t lidParser::NamedFunctionContext::getRuleIndex() const {
  return lidParser::RuleNamedFunction;
}


antlrcpp::Any lidParser::NamedFunctionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lidVisitor*>(visitor))
    return parserVisitor->visitNamedFunction(this);
  else
    return visitor->visitChildren(this);
}

lidParser::NamedFunctionContext* lidParser::namedFunction() {
  NamedFunctionContext *_localctx = _tracker.createInstance<NamedFunctionContext>(_ctx, getState());
  enterRule(_localctx, 4, lidParser::RuleNamedFunction);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(115);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case lidParser::T__0: {
        enterOuterAlt(_localctx, 1);
        setState(75);
        match(lidParser::T__0);
        setState(76);
        match(lidParser::IDENTIFIER);
        setState(77);
        match(lidParser::T__1);
        setState(79);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == lidParser::T__13

        || _la == lidParser::IDENTIFIER) {
          setState(78);
          typedParameter();
        }
        setState(85);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == lidParser::T__2) {
          setState(81);
          match(lidParser::T__2);
          setState(82);
          typedParameter();
          setState(87);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(88);
        match(lidParser::T__3);
        setState(89);
        typeName();
        setState(90);
        match(lidParser::T__4);
        setState(94);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << lidParser::T__0)
          | (1ULL << lidParser::T__1)
          | (1ULL << lidParser::T__11)
          | (1ULL << lidParser::T__14)
          | (1ULL << lidParser::T__16)
          | (1ULL << lidParser::T__18)
          | (1ULL << lidParser::T__19)
          | (1ULL << lidParser::IDENTIFIER)
          | (1ULL << lidParser::FLOAT_LITERAL)
          | (1ULL << lidParser::INTEGER_LITERAL)
          | (1ULL << lidParser::STRING_LITERAL))) != 0)) {
          setState(91);
          expression();
          setState(96);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(97);
        match(lidParser::T__5);
        break;
      }

      case lidParser::T__6: {
        enterOuterAlt(_localctx, 2);
        setState(99);
        match(lidParser::T__6);
        setState(100);
        match(lidParser::T__0);
        setState(101);
        match(lidParser::IDENTIFIER);
        setState(102);
        match(lidParser::T__1);
        setState(104);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == lidParser::T__13

        || _la == lidParser::IDENTIFIER) {
          setState(103);
          typedParameter();
        }
        setState(110);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == lidParser::T__2) {
          setState(106);
          match(lidParser::T__2);
          setState(107);
          typedParameter();
          setState(112);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(113);
        match(lidParser::T__3);
        setState(114);
        typeName();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NamedConstantContext ------------------------------------------------------------------

lidParser::NamedConstantContext::NamedConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* lidParser::NamedConstantContext::IDENTIFIER() {
  return getToken(lidParser::IDENTIFIER, 0);
}

lidParser::ExpressionContext* lidParser::NamedConstantContext::expression() {
  return getRuleContext<lidParser::ExpressionContext>(0);
}


size_t lidParser::NamedConstantContext::getRuleIndex() const {
  return lidParser::RuleNamedConstant;
}


antlrcpp::Any lidParser::NamedConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lidVisitor*>(visitor))
    return parserVisitor->visitNamedConstant(this);
  else
    return visitor->visitChildren(this);
}

lidParser::NamedConstantContext* lidParser::namedConstant() {
  NamedConstantContext *_localctx = _tracker.createInstance<NamedConstantContext>(_ctx, getState());
  enterRule(_localctx, 6, lidParser::RuleNamedConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(117);
    match(lidParser::T__7);
    setState(118);
    match(lidParser::IDENTIFIER);
    setState(119);
    match(lidParser::T__8);
    setState(120);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NamedStructContext ------------------------------------------------------------------

lidParser::NamedStructContext::NamedStructContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* lidParser::NamedStructContext::IDENTIFIER() {
  return getToken(lidParser::IDENTIFIER, 0);
}

std::vector<lidParser::StructMemberContext *> lidParser::NamedStructContext::structMember() {
  return getRuleContexts<lidParser::StructMemberContext>();
}

lidParser::StructMemberContext* lidParser::NamedStructContext::structMember(size_t i) {
  return getRuleContext<lidParser::StructMemberContext>(i);
}


size_t lidParser::NamedStructContext::getRuleIndex() const {
  return lidParser::RuleNamedStruct;
}


antlrcpp::Any lidParser::NamedStructContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lidVisitor*>(visitor))
    return parserVisitor->visitNamedStruct(this);
  else
    return visitor->visitChildren(this);
}

lidParser::NamedStructContext* lidParser::namedStruct() {
  NamedStructContext *_localctx = _tracker.createInstance<NamedStructContext>(_ctx, getState());
  enterRule(_localctx, 8, lidParser::RuleNamedStruct);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(122);
    match(lidParser::T__9);
    setState(123);
    match(lidParser::IDENTIFIER);
    setState(124);
    match(lidParser::T__4);
    setState(126); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(125);
      structMember();
      setState(128); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == lidParser::IDENTIFIER);
    setState(130);
    match(lidParser::T__5);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StructMemberContext ------------------------------------------------------------------

lidParser::StructMemberContext::StructMemberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* lidParser::StructMemberContext::IDENTIFIER() {
  return getToken(lidParser::IDENTIFIER, 0);
}

lidParser::TypeNameContext* lidParser::StructMemberContext::typeName() {
  return getRuleContext<lidParser::TypeNameContext>(0);
}

lidParser::ExpressionContext* lidParser::StructMemberContext::expression() {
  return getRuleContext<lidParser::ExpressionContext>(0);
}


size_t lidParser::StructMemberContext::getRuleIndex() const {
  return lidParser::RuleStructMember;
}


antlrcpp::Any lidParser::StructMemberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lidVisitor*>(visitor))
    return parserVisitor->visitStructMember(this);
  else
    return visitor->visitChildren(this);
}

lidParser::StructMemberContext* lidParser::structMember() {
  StructMemberContext *_localctx = _tracker.createInstance<StructMemberContext>(_ctx, getState());
  enterRule(_localctx, 10, lidParser::RuleStructMember);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(140);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(132);
      match(lidParser::IDENTIFIER);
      setState(133);
      typeName();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(134);
      match(lidParser::IDENTIFIER);
      setState(135);
      typeName();
      setState(136);
      match(lidParser::T__8);
      setState(138);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
      case 1: {
        setState(137);
        expression();
        break;
      }

      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

lidParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

lidParser::ConstantContext* lidParser::ExpressionContext::constant() {
  return getRuleContext<lidParser::ConstantContext>(0);
}

lidParser::CallableContext* lidParser::ExpressionContext::callable() {
  return getRuleContext<lidParser::CallableContext>(0);
}

lidParser::LambdaContext* lidParser::ExpressionContext::lambda() {
  return getRuleContext<lidParser::LambdaContext>(0);
}

lidParser::LetContext* lidParser::ExpressionContext::let() {
  return getRuleContext<lidParser::LetContext>(0);
}

lidParser::SetContext* lidParser::ExpressionContext::set() {
  return getRuleContext<lidParser::SetContext>(0);
}

lidParser::BranchContext* lidParser::ExpressionContext::branch() {
  return getRuleContext<lidParser::BranchContext>(0);
}

lidParser::LoopContext* lidParser::ExpressionContext::loop() {
  return getRuleContext<lidParser::LoopContext>(0);
}

lidParser::BinaryContext* lidParser::ExpressionContext::binary() {
  return getRuleContext<lidParser::BinaryContext>(0);
}

lidParser::UnaryContext* lidParser::ExpressionContext::unary() {
  return getRuleContext<lidParser::UnaryContext>(0);
}


size_t lidParser::ExpressionContext::getRuleIndex() const {
  return lidParser::RuleExpression;
}


antlrcpp::Any lidParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lidVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}

lidParser::ExpressionContext* lidParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 12, lidParser::RuleExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(151);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(142);
      constant();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(143);
      callable();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(144);
      lambda();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(145);
      let();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(146);
      set();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(147);
      branch();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(148);
      loop();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(149);
      binary();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(150);
      unary();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstantContext ------------------------------------------------------------------

lidParser::ConstantContext::ConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

lidParser::SymbolReferenceContext* lidParser::ConstantContext::symbolReference() {
  return getRuleContext<lidParser::SymbolReferenceContext>(0);
}

tree::TerminalNode* lidParser::ConstantContext::FLOAT_LITERAL() {
  return getToken(lidParser::FLOAT_LITERAL, 0);
}

tree::TerminalNode* lidParser::ConstantContext::INTEGER_LITERAL() {
  return getToken(lidParser::INTEGER_LITERAL, 0);
}

tree::TerminalNode* lidParser::ConstantContext::STRING_LITERAL() {
  return getToken(lidParser::STRING_LITERAL, 0);
}


size_t lidParser::ConstantContext::getRuleIndex() const {
  return lidParser::RuleConstant;
}


antlrcpp::Any lidParser::ConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lidVisitor*>(visitor))
    return parserVisitor->visitConstant(this);
  else
    return visitor->visitChildren(this);
}

lidParser::ConstantContext* lidParser::constant() {
  ConstantContext *_localctx = _tracker.createInstance<ConstantContext>(_ctx, getState());
  enterRule(_localctx, 14, lidParser::RuleConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(157);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case lidParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(153);
        symbolReference();
        break;
      }

      case lidParser::FLOAT_LITERAL: {
        enterOuterAlt(_localctx, 2);
        setState(154);
        match(lidParser::FLOAT_LITERAL);
        break;
      }

      case lidParser::INTEGER_LITERAL: {
        enterOuterAlt(_localctx, 3);
        setState(155);
        match(lidParser::INTEGER_LITERAL);
        break;
      }

      case lidParser::STRING_LITERAL: {
        enterOuterAlt(_localctx, 4);
        setState(156);
        match(lidParser::STRING_LITERAL);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SymbolReferenceContext ------------------------------------------------------------------

lidParser::SymbolReferenceContext::SymbolReferenceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> lidParser::SymbolReferenceContext::IDENTIFIER() {
  return getTokens(lidParser::IDENTIFIER);
}

tree::TerminalNode* lidParser::SymbolReferenceContext::IDENTIFIER(size_t i) {
  return getToken(lidParser::IDENTIFIER, i);
}


size_t lidParser::SymbolReferenceContext::getRuleIndex() const {
  return lidParser::RuleSymbolReference;
}


antlrcpp::Any lidParser::SymbolReferenceContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lidVisitor*>(visitor))
    return parserVisitor->visitSymbolReference(this);
  else
    return visitor->visitChildren(this);
}

lidParser::SymbolReferenceContext* lidParser::symbolReference() {
  SymbolReferenceContext *_localctx = _tracker.createInstance<SymbolReferenceContext>(_ctx, getState());
  enterRule(_localctx, 16, lidParser::RuleSymbolReference);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(159);
    match(lidParser::IDENTIFIER);
    setState(164);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == lidParser::T__10) {
      setState(160);
      match(lidParser::T__10);
      setState(161);
      match(lidParser::IDENTIFIER);
      setState(166);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CallableContext ------------------------------------------------------------------

lidParser::CallableContext::CallableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

lidParser::SymbolReferenceContext* lidParser::CallableContext::symbolReference() {
  return getRuleContext<lidParser::SymbolReferenceContext>(0);
}

std::vector<lidParser::ParameterContext *> lidParser::CallableContext::parameter() {
  return getRuleContexts<lidParser::ParameterContext>();
}

lidParser::ParameterContext* lidParser::CallableContext::parameter(size_t i) {
  return getRuleContext<lidParser::ParameterContext>(i);
}

lidParser::ExpressionContext* lidParser::CallableContext::expression() {
  return getRuleContext<lidParser::ExpressionContext>(0);
}


size_t lidParser::CallableContext::getRuleIndex() const {
  return lidParser::RuleCallable;
}


antlrcpp::Any lidParser::CallableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lidVisitor*>(visitor))
    return parserVisitor->visitCallable(this);
  else
    return visitor->visitChildren(this);
}

lidParser::CallableContext* lidParser::callable() {
  CallableContext *_localctx = _tracker.createInstance<CallableContext>(_ctx, getState());
  enterRule(_localctx, 18, lidParser::RuleCallable);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(197);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case lidParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(167);
        symbolReference();
        setState(168);
        match(lidParser::T__1);
        setState(170);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << lidParser::T__0)
          | (1ULL << lidParser::T__1)
          | (1ULL << lidParser::T__11)
          | (1ULL << lidParser::T__14)
          | (1ULL << lidParser::T__16)
          | (1ULL << lidParser::T__18)
          | (1ULL << lidParser::T__19)
          | (1ULL << lidParser::IDENTIFIER)
          | (1ULL << lidParser::FLOAT_LITERAL)
          | (1ULL << lidParser::INTEGER_LITERAL)
          | (1ULL << lidParser::STRING_LITERAL))) != 0)) {
          setState(169);
          parameter();
        }
        setState(176);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == lidParser::T__2) {
          setState(172);
          match(lidParser::T__2);
          setState(173);
          parameter();
          setState(178);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(179);
        match(lidParser::T__3);
        break;
      }

      case lidParser::T__1: {
        enterOuterAlt(_localctx, 2);
        setState(181);
        match(lidParser::T__1);
        setState(182);
        expression();
        setState(183);
        match(lidParser::T__3);
        setState(184);
        match(lidParser::T__1);
        setState(186);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << lidParser::T__0)
          | (1ULL << lidParser::T__1)
          | (1ULL << lidParser::T__11)
          | (1ULL << lidParser::T__14)
          | (1ULL << lidParser::T__16)
          | (1ULL << lidParser::T__18)
          | (1ULL << lidParser::T__19)
          | (1ULL << lidParser::IDENTIFIER)
          | (1ULL << lidParser::FLOAT_LITERAL)
          | (1ULL << lidParser::INTEGER_LITERAL)
          | (1ULL << lidParser::STRING_LITERAL))) != 0)) {
          setState(185);
          parameter();
        }
        setState(192);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == lidParser::T__2) {
          setState(188);
          match(lidParser::T__2);
          setState(189);
          parameter();
          setState(194);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(195);
        match(lidParser::T__3);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterContext ------------------------------------------------------------------

lidParser::ParameterContext::ParameterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

lidParser::ExpressionContext* lidParser::ParameterContext::expression() {
  return getRuleContext<lidParser::ExpressionContext>(0);
}


size_t lidParser::ParameterContext::getRuleIndex() const {
  return lidParser::RuleParameter;
}


antlrcpp::Any lidParser::ParameterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lidVisitor*>(visitor))
    return parserVisitor->visitParameter(this);
  else
    return visitor->visitChildren(this);
}

lidParser::ParameterContext* lidParser::parameter() {
  ParameterContext *_localctx = _tracker.createInstance<ParameterContext>(_ctx, getState());
  enterRule(_localctx, 20, lidParser::RuleParameter);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(199);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LambdaContext ------------------------------------------------------------------

lidParser::LambdaContext::LambdaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

lidParser::TypeNameContext* lidParser::LambdaContext::typeName() {
  return getRuleContext<lidParser::TypeNameContext>(0);
}

std::vector<lidParser::TypedParameterContext *> lidParser::LambdaContext::typedParameter() {
  return getRuleContexts<lidParser::TypedParameterContext>();
}

lidParser::TypedParameterContext* lidParser::LambdaContext::typedParameter(size_t i) {
  return getRuleContext<lidParser::TypedParameterContext>(i);
}

std::vector<lidParser::ExpressionContext *> lidParser::LambdaContext::expression() {
  return getRuleContexts<lidParser::ExpressionContext>();
}

lidParser::ExpressionContext* lidParser::LambdaContext::expression(size_t i) {
  return getRuleContext<lidParser::ExpressionContext>(i);
}


size_t lidParser::LambdaContext::getRuleIndex() const {
  return lidParser::RuleLambda;
}


antlrcpp::Any lidParser::LambdaContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lidVisitor*>(visitor))
    return parserVisitor->visitLambda(this);
  else
    return visitor->visitChildren(this);
}

lidParser::LambdaContext* lidParser::lambda() {
  LambdaContext *_localctx = _tracker.createInstance<LambdaContext>(_ctx, getState());
  enterRule(_localctx, 22, lidParser::RuleLambda);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(201);
    match(lidParser::T__0);
    setState(202);
    match(lidParser::T__1);
    setState(204);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == lidParser::T__13

    || _la == lidParser::IDENTIFIER) {
      setState(203);
      typedParameter();
    }
    setState(210);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == lidParser::T__2) {
      setState(206);
      match(lidParser::T__2);
      setState(207);
      typedParameter();
      setState(212);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(213);
    match(lidParser::T__3);
    setState(214);
    typeName();
    setState(215);
    match(lidParser::T__4);
    setState(219);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << lidParser::T__0)
      | (1ULL << lidParser::T__1)
      | (1ULL << lidParser::T__11)
      | (1ULL << lidParser::T__14)
      | (1ULL << lidParser::T__16)
      | (1ULL << lidParser::T__18)
      | (1ULL << lidParser::T__19)
      | (1ULL << lidParser::IDENTIFIER)
      | (1ULL << lidParser::FLOAT_LITERAL)
      | (1ULL << lidParser::INTEGER_LITERAL)
      | (1ULL << lidParser::STRING_LITERAL))) != 0)) {
      setState(216);
      expression();
      setState(221);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(222);
    match(lidParser::T__5);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypedParameterContext ------------------------------------------------------------------

lidParser::TypedParameterContext::TypedParameterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* lidParser::TypedParameterContext::IDENTIFIER() {
  return getToken(lidParser::IDENTIFIER, 0);
}

lidParser::TypeNameContext* lidParser::TypedParameterContext::typeName() {
  return getRuleContext<lidParser::TypeNameContext>(0);
}


size_t lidParser::TypedParameterContext::getRuleIndex() const {
  return lidParser::RuleTypedParameter;
}


antlrcpp::Any lidParser::TypedParameterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lidVisitor*>(visitor))
    return parserVisitor->visitTypedParameter(this);
  else
    return visitor->visitChildren(this);
}

lidParser::TypedParameterContext* lidParser::typedParameter() {
  TypedParameterContext *_localctx = _tracker.createInstance<TypedParameterContext>(_ctx, getState());
  enterRule(_localctx, 24, lidParser::RuleTypedParameter);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(227);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case lidParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(224);
        match(lidParser::IDENTIFIER);
        setState(225);
        typeName();
        break;
      }

      case lidParser::T__13: {
        enterOuterAlt(_localctx, 2);
        setState(226);
        typeName();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LetContext ------------------------------------------------------------------

lidParser::LetContext::LetContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<lidParser::TypedValueBindingContext *> lidParser::LetContext::typedValueBinding() {
  return getRuleContexts<lidParser::TypedValueBindingContext>();
}

lidParser::TypedValueBindingContext* lidParser::LetContext::typedValueBinding(size_t i) {
  return getRuleContext<lidParser::TypedValueBindingContext>(i);
}

std::vector<lidParser::ExpressionContext *> lidParser::LetContext::expression() {
  return getRuleContexts<lidParser::ExpressionContext>();
}

lidParser::ExpressionContext* lidParser::LetContext::expression(size_t i) {
  return getRuleContext<lidParser::ExpressionContext>(i);
}


size_t lidParser::LetContext::getRuleIndex() const {
  return lidParser::RuleLet;
}


antlrcpp::Any lidParser::LetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lidVisitor*>(visitor))
    return parserVisitor->visitLet(this);
  else
    return visitor->visitChildren(this);
}

lidParser::LetContext* lidParser::let() {
  LetContext *_localctx = _tracker.createInstance<LetContext>(_ctx, getState());
  enterRule(_localctx, 26, lidParser::RuleLet);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(229);
    match(lidParser::T__11);
    setState(233);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == lidParser::IDENTIFIER) {
      setState(230);
      typedValueBinding();
      setState(235);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(236);
    match(lidParser::T__4);
    setState(240);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << lidParser::T__0)
      | (1ULL << lidParser::T__1)
      | (1ULL << lidParser::T__11)
      | (1ULL << lidParser::T__14)
      | (1ULL << lidParser::T__16)
      | (1ULL << lidParser::T__18)
      | (1ULL << lidParser::T__19)
      | (1ULL << lidParser::IDENTIFIER)
      | (1ULL << lidParser::FLOAT_LITERAL)
      | (1ULL << lidParser::INTEGER_LITERAL)
      | (1ULL << lidParser::STRING_LITERAL))) != 0)) {
      setState(237);
      expression();
      setState(242);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(243);
    match(lidParser::T__5);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypedValueBindingContext ------------------------------------------------------------------

lidParser::TypedValueBindingContext::TypedValueBindingContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* lidParser::TypedValueBindingContext::IDENTIFIER() {
  return getToken(lidParser::IDENTIFIER, 0);
}

lidParser::ExpressionContext* lidParser::TypedValueBindingContext::expression() {
  return getRuleContext<lidParser::ExpressionContext>(0);
}

lidParser::TypeNameContext* lidParser::TypedValueBindingContext::typeName() {
  return getRuleContext<lidParser::TypeNameContext>(0);
}

lidParser::TypedValueQualifierContext* lidParser::TypedValueBindingContext::typedValueQualifier() {
  return getRuleContext<lidParser::TypedValueQualifierContext>(0);
}


size_t lidParser::TypedValueBindingContext::getRuleIndex() const {
  return lidParser::RuleTypedValueBinding;
}


antlrcpp::Any lidParser::TypedValueBindingContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lidVisitor*>(visitor))
    return parserVisitor->visitTypedValueBinding(this);
  else
    return visitor->visitChildren(this);
}

lidParser::TypedValueBindingContext* lidParser::typedValueBinding() {
  TypedValueBindingContext *_localctx = _tracker.createInstance<TypedValueBindingContext>(_ctx, getState());
  enterRule(_localctx, 28, lidParser::RuleTypedValueBinding);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(245);
    match(lidParser::IDENTIFIER);
    setState(247);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == lidParser::T__13) {
      setState(246);
      typeName();
    }
    setState(250);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == lidParser::T__12) {
      setState(249);
      typedValueQualifier();
    }
    setState(252);
    match(lidParser::T__8);
    setState(253);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypedValueQualifierContext ------------------------------------------------------------------

lidParser::TypedValueQualifierContext::TypedValueQualifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t lidParser::TypedValueQualifierContext::getRuleIndex() const {
  return lidParser::RuleTypedValueQualifier;
}


antlrcpp::Any lidParser::TypedValueQualifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lidVisitor*>(visitor))
    return parserVisitor->visitTypedValueQualifier(this);
  else
    return visitor->visitChildren(this);
}

lidParser::TypedValueQualifierContext* lidParser::typedValueQualifier() {
  TypedValueQualifierContext *_localctx = _tracker.createInstance<TypedValueQualifierContext>(_ctx, getState());
  enterRule(_localctx, 30, lidParser::RuleTypedValueQualifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(255);
    match(lidParser::T__12);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeNameContext ------------------------------------------------------------------

lidParser::TypeNameContext::TypeNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

lidParser::RegularTypeNameContext* lidParser::TypeNameContext::regularTypeName() {
  return getRuleContext<lidParser::RegularTypeNameContext>(0);
}

lidParser::FunctionTypeNameContext* lidParser::TypeNameContext::functionTypeName() {
  return getRuleContext<lidParser::FunctionTypeNameContext>(0);
}


size_t lidParser::TypeNameContext::getRuleIndex() const {
  return lidParser::RuleTypeName;
}


antlrcpp::Any lidParser::TypeNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lidVisitor*>(visitor))
    return parserVisitor->visitTypeName(this);
  else
    return visitor->visitChildren(this);
}

lidParser::TypeNameContext* lidParser::typeName() {
  TypeNameContext *_localctx = _tracker.createInstance<TypeNameContext>(_ctx, getState());
  enterRule(_localctx, 32, lidParser::RuleTypeName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(259);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(257);
      regularTypeName();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(258);
      functionTypeName();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RegularTypeNameContext ------------------------------------------------------------------

lidParser::RegularTypeNameContext::RegularTypeNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* lidParser::RegularTypeNameContext::IDENTIFIER() {
  return getToken(lidParser::IDENTIFIER, 0);
}

tree::TerminalNode* lidParser::RegularTypeNameContext::POINTER_PREFIX() {
  return getToken(lidParser::POINTER_PREFIX, 0);
}


size_t lidParser::RegularTypeNameContext::getRuleIndex() const {
  return lidParser::RuleRegularTypeName;
}


antlrcpp::Any lidParser::RegularTypeNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lidVisitor*>(visitor))
    return parserVisitor->visitRegularTypeName(this);
  else
    return visitor->visitChildren(this);
}

lidParser::RegularTypeNameContext* lidParser::regularTypeName() {
  RegularTypeNameContext *_localctx = _tracker.createInstance<RegularTypeNameContext>(_ctx, getState());
  enterRule(_localctx, 34, lidParser::RuleRegularTypeName);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(261);
    match(lidParser::T__13);
    setState(263);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == lidParser::POINTER_PREFIX) {
      setState(262);
      match(lidParser::POINTER_PREFIX);
    }
    setState(265);
    match(lidParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionTypeNameContext ------------------------------------------------------------------

lidParser::FunctionTypeNameContext::FunctionTypeNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

lidParser::TypeNameContext* lidParser::FunctionTypeNameContext::typeName() {
  return getRuleContext<lidParser::TypeNameContext>(0);
}

std::vector<lidParser::TypedParameterContext *> lidParser::FunctionTypeNameContext::typedParameter() {
  return getRuleContexts<lidParser::TypedParameterContext>();
}

lidParser::TypedParameterContext* lidParser::FunctionTypeNameContext::typedParameter(size_t i) {
  return getRuleContext<lidParser::TypedParameterContext>(i);
}


size_t lidParser::FunctionTypeNameContext::getRuleIndex() const {
  return lidParser::RuleFunctionTypeName;
}


antlrcpp::Any lidParser::FunctionTypeNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lidVisitor*>(visitor))
    return parserVisitor->visitFunctionTypeName(this);
  else
    return visitor->visitChildren(this);
}

lidParser::FunctionTypeNameContext* lidParser::functionTypeName() {
  FunctionTypeNameContext *_localctx = _tracker.createInstance<FunctionTypeNameContext>(_ctx, getState());
  enterRule(_localctx, 36, lidParser::RuleFunctionTypeName);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(267);
    match(lidParser::T__13);
    setState(268);
    match(lidParser::T__0);
    setState(269);
    match(lidParser::T__1);
    setState(271);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == lidParser::T__13

    || _la == lidParser::IDENTIFIER) {
      setState(270);
      typedParameter();
    }
    setState(277);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == lidParser::T__2) {
      setState(273);
      match(lidParser::T__2);
      setState(274);
      typedParameter();
      setState(279);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(280);
    match(lidParser::T__3);
    setState(281);
    typeName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SetContext ------------------------------------------------------------------

lidParser::SetContext::SetContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

lidParser::SymbolReferenceContext* lidParser::SetContext::symbolReference() {
  return getRuleContext<lidParser::SymbolReferenceContext>(0);
}

lidParser::ExpressionContext* lidParser::SetContext::expression() {
  return getRuleContext<lidParser::ExpressionContext>(0);
}


size_t lidParser::SetContext::getRuleIndex() const {
  return lidParser::RuleSet;
}


antlrcpp::Any lidParser::SetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lidVisitor*>(visitor))
    return parserVisitor->visitSet(this);
  else
    return visitor->visitChildren(this);
}

lidParser::SetContext* lidParser::set() {
  SetContext *_localctx = _tracker.createInstance<SetContext>(_ctx, getState());
  enterRule(_localctx, 38, lidParser::RuleSet);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(283);
    symbolReference();
    setState(284);
    match(lidParser::T__8);
    setState(285);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BranchContext ------------------------------------------------------------------

lidParser::BranchContext::BranchContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

lidParser::BranchBeginContext* lidParser::BranchContext::branchBegin() {
  return getRuleContext<lidParser::BranchBeginContext>(0);
}

lidParser::BranchEndContext* lidParser::BranchContext::branchEnd() {
  return getRuleContext<lidParser::BranchEndContext>(0);
}

std::vector<lidParser::BranchItemContext *> lidParser::BranchContext::branchItem() {
  return getRuleContexts<lidParser::BranchItemContext>();
}

lidParser::BranchItemContext* lidParser::BranchContext::branchItem(size_t i) {
  return getRuleContext<lidParser::BranchItemContext>(i);
}


size_t lidParser::BranchContext::getRuleIndex() const {
  return lidParser::RuleBranch;
}


antlrcpp::Any lidParser::BranchContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lidVisitor*>(visitor))
    return parserVisitor->visitBranch(this);
  else
    return visitor->visitChildren(this);
}

lidParser::BranchContext* lidParser::branch() {
  BranchContext *_localctx = _tracker.createInstance<BranchContext>(_ctx, getState());
  enterRule(_localctx, 40, lidParser::RuleBranch);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(287);
    branchBegin();
    setState(291);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(288);
        branchItem(); 
      }
      setState(293);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
    }
    setState(294);
    branchEnd();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BranchConditionContext ------------------------------------------------------------------

lidParser::BranchConditionContext::BranchConditionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

lidParser::ExpressionContext* lidParser::BranchConditionContext::expression() {
  return getRuleContext<lidParser::ExpressionContext>(0);
}


size_t lidParser::BranchConditionContext::getRuleIndex() const {
  return lidParser::RuleBranchCondition;
}


antlrcpp::Any lidParser::BranchConditionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lidVisitor*>(visitor))
    return parserVisitor->visitBranchCondition(this);
  else
    return visitor->visitChildren(this);
}

lidParser::BranchConditionContext* lidParser::branchCondition() {
  BranchConditionContext *_localctx = _tracker.createInstance<BranchConditionContext>(_ctx, getState());
  enterRule(_localctx, 42, lidParser::RuleBranchCondition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(296);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BranchBeginContext ------------------------------------------------------------------

lidParser::BranchBeginContext::BranchBeginContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

lidParser::BranchConditionContext* lidParser::BranchBeginContext::branchCondition() {
  return getRuleContext<lidParser::BranchConditionContext>(0);
}

std::vector<lidParser::ExpressionContext *> lidParser::BranchBeginContext::expression() {
  return getRuleContexts<lidParser::ExpressionContext>();
}

lidParser::ExpressionContext* lidParser::BranchBeginContext::expression(size_t i) {
  return getRuleContext<lidParser::ExpressionContext>(i);
}


size_t lidParser::BranchBeginContext::getRuleIndex() const {
  return lidParser::RuleBranchBegin;
}


antlrcpp::Any lidParser::BranchBeginContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lidVisitor*>(visitor))
    return parserVisitor->visitBranchBegin(this);
  else
    return visitor->visitChildren(this);
}

lidParser::BranchBeginContext* lidParser::branchBegin() {
  BranchBeginContext *_localctx = _tracker.createInstance<BranchBeginContext>(_ctx, getState());
  enterRule(_localctx, 44, lidParser::RuleBranchBegin);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(298);
    match(lidParser::T__14);
    setState(299);
    branchCondition();
    setState(300);
    match(lidParser::T__4);
    setState(302); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(301);
      expression();
      setState(304); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << lidParser::T__0)
      | (1ULL << lidParser::T__1)
      | (1ULL << lidParser::T__11)
      | (1ULL << lidParser::T__14)
      | (1ULL << lidParser::T__16)
      | (1ULL << lidParser::T__18)
      | (1ULL << lidParser::T__19)
      | (1ULL << lidParser::IDENTIFIER)
      | (1ULL << lidParser::FLOAT_LITERAL)
      | (1ULL << lidParser::INTEGER_LITERAL)
      | (1ULL << lidParser::STRING_LITERAL))) != 0));
    setState(306);
    match(lidParser::T__5);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BranchItemContext ------------------------------------------------------------------

lidParser::BranchItemContext::BranchItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

lidParser::BranchConditionContext* lidParser::BranchItemContext::branchCondition() {
  return getRuleContext<lidParser::BranchConditionContext>(0);
}

std::vector<lidParser::ExpressionContext *> lidParser::BranchItemContext::expression() {
  return getRuleContexts<lidParser::ExpressionContext>();
}

lidParser::ExpressionContext* lidParser::BranchItemContext::expression(size_t i) {
  return getRuleContext<lidParser::ExpressionContext>(i);
}


size_t lidParser::BranchItemContext::getRuleIndex() const {
  return lidParser::RuleBranchItem;
}


antlrcpp::Any lidParser::BranchItemContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lidVisitor*>(visitor))
    return parserVisitor->visitBranchItem(this);
  else
    return visitor->visitChildren(this);
}

lidParser::BranchItemContext* lidParser::branchItem() {
  BranchItemContext *_localctx = _tracker.createInstance<BranchItemContext>(_ctx, getState());
  enterRule(_localctx, 46, lidParser::RuleBranchItem);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(308);
    match(lidParser::T__15);
    setState(309);
    match(lidParser::T__14);
    setState(310);
    branchCondition();
    setState(311);
    match(lidParser::T__4);
    setState(313); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(312);
      expression();
      setState(315); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << lidParser::T__0)
      | (1ULL << lidParser::T__1)
      | (1ULL << lidParser::T__11)
      | (1ULL << lidParser::T__14)
      | (1ULL << lidParser::T__16)
      | (1ULL << lidParser::T__18)
      | (1ULL << lidParser::T__19)
      | (1ULL << lidParser::IDENTIFIER)
      | (1ULL << lidParser::FLOAT_LITERAL)
      | (1ULL << lidParser::INTEGER_LITERAL)
      | (1ULL << lidParser::STRING_LITERAL))) != 0));
    setState(317);
    match(lidParser::T__5);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BranchEndContext ------------------------------------------------------------------

lidParser::BranchEndContext::BranchEndContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<lidParser::ExpressionContext *> lidParser::BranchEndContext::expression() {
  return getRuleContexts<lidParser::ExpressionContext>();
}

lidParser::ExpressionContext* lidParser::BranchEndContext::expression(size_t i) {
  return getRuleContext<lidParser::ExpressionContext>(i);
}


size_t lidParser::BranchEndContext::getRuleIndex() const {
  return lidParser::RuleBranchEnd;
}


antlrcpp::Any lidParser::BranchEndContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lidVisitor*>(visitor))
    return parserVisitor->visitBranchEnd(this);
  else
    return visitor->visitChildren(this);
}

lidParser::BranchEndContext* lidParser::branchEnd() {
  BranchEndContext *_localctx = _tracker.createInstance<BranchEndContext>(_ctx, getState());
  enterRule(_localctx, 48, lidParser::RuleBranchEnd);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(319);
    match(lidParser::T__15);
    setState(320);
    match(lidParser::T__4);
    setState(322); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(321);
      expression();
      setState(324); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << lidParser::T__0)
      | (1ULL << lidParser::T__1)
      | (1ULL << lidParser::T__11)
      | (1ULL << lidParser::T__14)
      | (1ULL << lidParser::T__16)
      | (1ULL << lidParser::T__18)
      | (1ULL << lidParser::T__19)
      | (1ULL << lidParser::IDENTIFIER)
      | (1ULL << lidParser::FLOAT_LITERAL)
      | (1ULL << lidParser::INTEGER_LITERAL)
      | (1ULL << lidParser::STRING_LITERAL))) != 0));
    setState(326);
    match(lidParser::T__5);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LoopContext ------------------------------------------------------------------

lidParser::LoopContext::LoopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<lidParser::LoopBindingExpressionContext *> lidParser::LoopContext::loopBindingExpression() {
  return getRuleContexts<lidParser::LoopBindingExpressionContext>();
}

lidParser::LoopBindingExpressionContext* lidParser::LoopContext::loopBindingExpression(size_t i) {
  return getRuleContext<lidParser::LoopBindingExpressionContext>(i);
}

std::vector<lidParser::ExpressionContext *> lidParser::LoopContext::expression() {
  return getRuleContexts<lidParser::ExpressionContext>();
}

lidParser::ExpressionContext* lidParser::LoopContext::expression(size_t i) {
  return getRuleContext<lidParser::ExpressionContext>(i);
}


size_t lidParser::LoopContext::getRuleIndex() const {
  return lidParser::RuleLoop;
}


antlrcpp::Any lidParser::LoopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lidVisitor*>(visitor))
    return parserVisitor->visitLoop(this);
  else
    return visitor->visitChildren(this);
}

lidParser::LoopContext* lidParser::loop() {
  LoopContext *_localctx = _tracker.createInstance<LoopContext>(_ctx, getState());
  enterRule(_localctx, 50, lidParser::RuleLoop);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(328);
    match(lidParser::T__16);
    setState(332);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == lidParser::T__1) {
      setState(329);
      loopBindingExpression();
      setState(334);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(335);
    match(lidParser::T__4);
    setState(339);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << lidParser::T__0)
      | (1ULL << lidParser::T__1)
      | (1ULL << lidParser::T__11)
      | (1ULL << lidParser::T__14)
      | (1ULL << lidParser::T__16)
      | (1ULL << lidParser::T__18)
      | (1ULL << lidParser::T__19)
      | (1ULL << lidParser::IDENTIFIER)
      | (1ULL << lidParser::FLOAT_LITERAL)
      | (1ULL << lidParser::INTEGER_LITERAL)
      | (1ULL << lidParser::STRING_LITERAL))) != 0)) {
      setState(336);
      expression();
      setState(341);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(342);
    match(lidParser::T__5);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LoopBindingExpressionContext ------------------------------------------------------------------

lidParser::LoopBindingExpressionContext::LoopBindingExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* lidParser::LoopBindingExpressionContext::IDENTIFIER() {
  return getToken(lidParser::IDENTIFIER, 0);
}

std::vector<lidParser::ExpressionContext *> lidParser::LoopBindingExpressionContext::expression() {
  return getRuleContexts<lidParser::ExpressionContext>();
}

lidParser::ExpressionContext* lidParser::LoopBindingExpressionContext::expression(size_t i) {
  return getRuleContext<lidParser::ExpressionContext>(i);
}

lidParser::TypeNameContext* lidParser::LoopBindingExpressionContext::typeName() {
  return getRuleContext<lidParser::TypeNameContext>(0);
}


size_t lidParser::LoopBindingExpressionContext::getRuleIndex() const {
  return lidParser::RuleLoopBindingExpression;
}


antlrcpp::Any lidParser::LoopBindingExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lidVisitor*>(visitor))
    return parserVisitor->visitLoopBindingExpression(this);
  else
    return visitor->visitChildren(this);
}

lidParser::LoopBindingExpressionContext* lidParser::loopBindingExpression() {
  LoopBindingExpressionContext *_localctx = _tracker.createInstance<LoopBindingExpressionContext>(_ctx, getState());
  enterRule(_localctx, 52, lidParser::RuleLoopBindingExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(344);
    match(lidParser::T__1);
    setState(345);
    match(lidParser::IDENTIFIER);
    setState(347);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == lidParser::T__13) {
      setState(346);
      typeName();
    }
    setState(349);
    match(lidParser::T__8);
    setState(350);
    expression();
    setState(351);
    match(lidParser::T__17);
    setState(352);
    expression();
    setState(353);
    match(lidParser::T__17);
    setState(354);
    expression();
    setState(355);
    match(lidParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BinaryContext ------------------------------------------------------------------

lidParser::BinaryContext::BinaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<lidParser::ExpressionContext *> lidParser::BinaryContext::expression() {
  return getRuleContexts<lidParser::ExpressionContext>();
}

lidParser::ExpressionContext* lidParser::BinaryContext::expression(size_t i) {
  return getRuleContext<lidParser::ExpressionContext>(i);
}

lidParser::BinaryOperatorContext* lidParser::BinaryContext::binaryOperator() {
  return getRuleContext<lidParser::BinaryOperatorContext>(0);
}


size_t lidParser::BinaryContext::getRuleIndex() const {
  return lidParser::RuleBinary;
}


antlrcpp::Any lidParser::BinaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lidVisitor*>(visitor))
    return parserVisitor->visitBinary(this);
  else
    return visitor->visitChildren(this);
}

lidParser::BinaryContext* lidParser::binary() {
  BinaryContext *_localctx = _tracker.createInstance<BinaryContext>(_ctx, getState());
  enterRule(_localctx, 54, lidParser::RuleBinary);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(357);
    match(lidParser::T__1);
    setState(358);
    expression();
    setState(359);
    binaryOperator();
    setState(360);
    expression();
    setState(361);
    match(lidParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BinaryOperatorContext ------------------------------------------------------------------

lidParser::BinaryOperatorContext::BinaryOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t lidParser::BinaryOperatorContext::getRuleIndex() const {
  return lidParser::RuleBinaryOperator;
}


antlrcpp::Any lidParser::BinaryOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lidVisitor*>(visitor))
    return parserVisitor->visitBinaryOperator(this);
  else
    return visitor->visitChildren(this);
}

lidParser::BinaryOperatorContext* lidParser::binaryOperator() {
  BinaryOperatorContext *_localctx = _tracker.createInstance<BinaryOperatorContext>(_ctx, getState());
  enterRule(_localctx, 56, lidParser::RuleBinaryOperator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(363);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << lidParser::T__18)
      | (1ULL << lidParser::T__19)
      | (1ULL << lidParser::T__20)
      | (1ULL << lidParser::T__21)
      | (1ULL << lidParser::T__22)
      | (1ULL << lidParser::T__23)
      | (1ULL << lidParser::T__24)
      | (1ULL << lidParser::T__25)
      | (1ULL << lidParser::T__26)
      | (1ULL << lidParser::T__27))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnaryContext ------------------------------------------------------------------

lidParser::UnaryContext::UnaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

lidParser::UnaryOperatorContext* lidParser::UnaryContext::unaryOperator() {
  return getRuleContext<lidParser::UnaryOperatorContext>(0);
}

lidParser::ExpressionContext* lidParser::UnaryContext::expression() {
  return getRuleContext<lidParser::ExpressionContext>(0);
}


size_t lidParser::UnaryContext::getRuleIndex() const {
  return lidParser::RuleUnary;
}


antlrcpp::Any lidParser::UnaryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lidVisitor*>(visitor))
    return parserVisitor->visitUnary(this);
  else
    return visitor->visitChildren(this);
}

lidParser::UnaryContext* lidParser::unary() {
  UnaryContext *_localctx = _tracker.createInstance<UnaryContext>(_ctx, getState());
  enterRule(_localctx, 58, lidParser::RuleUnary);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(365);
    unaryOperator();
    setState(366);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnaryOperatorContext ------------------------------------------------------------------

lidParser::UnaryOperatorContext::UnaryOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t lidParser::UnaryOperatorContext::getRuleIndex() const {
  return lidParser::RuleUnaryOperator;
}


antlrcpp::Any lidParser::UnaryOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lidVisitor*>(visitor))
    return parserVisitor->visitUnaryOperator(this);
  else
    return visitor->visitChildren(this);
}

lidParser::UnaryOperatorContext* lidParser::unaryOperator() {
  UnaryOperatorContext *_localctx = _tracker.createInstance<UnaryOperatorContext>(_ctx, getState());
  enterRule(_localctx, 60, lidParser::RuleUnaryOperator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(368);
    _la = _input->LA(1);
    if (!(_la == lidParser::T__18

    || _la == lidParser::T__19)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> lidParser::_decisionToDFA;
atn::PredictionContextCache lidParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN lidParser::_atn;
std::vector<uint16_t> lidParser::_serializedATN;

std::vector<std::string> lidParser::_ruleNames = {
  "program", "toplevel", "namedFunction", "namedConstant", "namedStruct", 
  "structMember", "expression", "constant", "symbolReference", "callable", 
  "parameter", "lambda", "typedParameter", "let", "typedValueBinding", "typedValueQualifier", 
  "typeName", "regularTypeName", "functionTypeName", "set", "branch", "branchCondition", 
  "branchBegin", "branchItem", "branchEnd", "loop", "loopBindingExpression", 
  "binary", "binaryOperator", "unary", "unaryOperator"
};

std::vector<std::string> lidParser::_literalNames = {
  "", "'function'", "'('", "','", "')'", "'{'", "'}'", "'extern'", "'const'", 
  "'='", "'struct'", "'.'", "'let'", "'#mutable'", "':'", "'if'", "'else'", 
  "'for'", "';'", "'+'", "'-'", "'*'", "'/'", "'=='", "'>'", "'<'", "'~='", 
  "'>='", "'<='", "", "'&'"
};

std::vector<std::string> lidParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "WHITESPACE", "POINTER_PREFIX", 
  "IDENTIFIER", "FLOAT_LITERAL", "INTEGER_LITERAL", "STRING_LITERAL", "LINE_COMMENT"
};

dfa::Vocabulary lidParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> lidParser::_tokenNames;

lidParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x25, 0x175, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x3, 0x2, 0x7, 0x2, 0x42, 0xa, 
    0x2, 0xc, 0x2, 0xe, 0x2, 0x45, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x4c, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x5, 0x4, 0x52, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 
    0x56, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x59, 0xb, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x5f, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x62, 
    0xb, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x5, 0x4, 0x6b, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x6f, 
    0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x72, 0xb, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 
    0x4, 0x76, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x6, 0x6, 0x81, 0xa, 0x6, 0xd, 
    0x6, 0xe, 0x6, 0x82, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x8d, 0xa, 0x7, 0x5, 0x7, 0x8f, 
    0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x9a, 0xa, 0x8, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0xa0, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x7, 0xa, 0xa5, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0xa8, 0xb, 0xa, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0xad, 0xa, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x7, 0xb, 0xb1, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0xb4, 0xb, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 
    0xb, 0xbd, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0xc1, 0xa, 0xb, 0xc, 
    0xb, 0xe, 0xb, 0xc4, 0xb, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0xc8, 0xa, 
    0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0xcf, 
    0xa, 0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 0xd3, 0xa, 0xd, 0xc, 0xd, 0xe, 
    0xd, 0xd6, 0xb, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 
    0xdc, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0xdf, 0xb, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0xe6, 0xa, 0xe, 0x3, 0xf, 0x3, 
    0xf, 0x7, 0xf, 0xea, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0xed, 0xb, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x7, 0xf, 0xf1, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0xf4, 0xb, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0xfa, 0xa, 
    0x10, 0x3, 0x10, 0x5, 0x10, 0xfd, 0xa, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 
    0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0x106, 
    0xa, 0x12, 0x3, 0x13, 0x3, 0x13, 0x5, 0x13, 0x10a, 0xa, 0x13, 0x3, 0x13, 
    0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0x112, 
    0xa, 0x14, 0x3, 0x14, 0x3, 0x14, 0x7, 0x14, 0x116, 0xa, 0x14, 0xc, 0x14, 
    0xe, 0x14, 0x119, 0xb, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 0x7, 0x16, 0x124, 
    0xa, 0x16, 0xc, 0x16, 0xe, 0x16, 0x127, 0xb, 0x16, 0x3, 0x16, 0x3, 0x16, 
    0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x6, 
    0x18, 0x131, 0xa, 0x18, 0xd, 0x18, 0xe, 0x18, 0x132, 0x3, 0x18, 0x3, 
    0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x6, 0x19, 
    0x13c, 0xa, 0x19, 0xd, 0x19, 0xe, 0x19, 0x13d, 0x3, 0x19, 0x3, 0x19, 
    0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x6, 0x1a, 0x145, 0xa, 0x1a, 0xd, 0x1a, 
    0xe, 0x1a, 0x146, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x7, 0x1b, 
    0x14d, 0xa, 0x1b, 0xc, 0x1b, 0xe, 0x1b, 0x150, 0xb, 0x1b, 0x3, 0x1b, 
    0x3, 0x1b, 0x7, 0x1b, 0x154, 0xa, 0x1b, 0xc, 0x1b, 0xe, 0x1b, 0x157, 
    0xb, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x5, 
    0x1c, 0x15e, 0xa, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 
    0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 
    0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1f, 
    0x3, 0x1f, 0x3, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x2, 0x2, 0x21, 
    0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 
    0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 
    0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x2, 0x4, 0x3, 0x2, 0x15, 0x1e, 
    0x3, 0x2, 0x15, 0x16, 0x2, 0x185, 0x2, 0x43, 0x3, 0x2, 0x2, 0x2, 0x4, 
    0x4b, 0x3, 0x2, 0x2, 0x2, 0x6, 0x75, 0x3, 0x2, 0x2, 0x2, 0x8, 0x77, 
    0x3, 0x2, 0x2, 0x2, 0xa, 0x7c, 0x3, 0x2, 0x2, 0x2, 0xc, 0x8e, 0x3, 0x2, 
    0x2, 0x2, 0xe, 0x99, 0x3, 0x2, 0x2, 0x2, 0x10, 0x9f, 0x3, 0x2, 0x2, 
    0x2, 0x12, 0xa1, 0x3, 0x2, 0x2, 0x2, 0x14, 0xc7, 0x3, 0x2, 0x2, 0x2, 
    0x16, 0xc9, 0x3, 0x2, 0x2, 0x2, 0x18, 0xcb, 0x3, 0x2, 0x2, 0x2, 0x1a, 
    0xe5, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xe7, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xf7, 
    0x3, 0x2, 0x2, 0x2, 0x20, 0x101, 0x3, 0x2, 0x2, 0x2, 0x22, 0x105, 0x3, 
    0x2, 0x2, 0x2, 0x24, 0x107, 0x3, 0x2, 0x2, 0x2, 0x26, 0x10d, 0x3, 0x2, 
    0x2, 0x2, 0x28, 0x11d, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x121, 0x3, 0x2, 0x2, 
    0x2, 0x2c, 0x12a, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x12c, 0x3, 0x2, 0x2, 0x2, 
    0x30, 0x136, 0x3, 0x2, 0x2, 0x2, 0x32, 0x141, 0x3, 0x2, 0x2, 0x2, 0x34, 
    0x14a, 0x3, 0x2, 0x2, 0x2, 0x36, 0x15a, 0x3, 0x2, 0x2, 0x2, 0x38, 0x167, 
    0x3, 0x2, 0x2, 0x2, 0x3a, 0x16d, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x16f, 0x3, 
    0x2, 0x2, 0x2, 0x3e, 0x172, 0x3, 0x2, 0x2, 0x2, 0x40, 0x42, 0x5, 0x4, 
    0x3, 0x2, 0x41, 0x40, 0x3, 0x2, 0x2, 0x2, 0x42, 0x45, 0x3, 0x2, 0x2, 
    0x2, 0x43, 0x41, 0x3, 0x2, 0x2, 0x2, 0x43, 0x44, 0x3, 0x2, 0x2, 0x2, 
    0x44, 0x46, 0x3, 0x2, 0x2, 0x2, 0x45, 0x43, 0x3, 0x2, 0x2, 0x2, 0x46, 
    0x47, 0x7, 0x2, 0x2, 0x3, 0x47, 0x3, 0x3, 0x2, 0x2, 0x2, 0x48, 0x4c, 
    0x5, 0x6, 0x4, 0x2, 0x49, 0x4c, 0x5, 0x8, 0x5, 0x2, 0x4a, 0x4c, 0x5, 
    0xa, 0x6, 0x2, 0x4b, 0x48, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x49, 0x3, 0x2, 
    0x2, 0x2, 0x4b, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x5, 0x3, 0x2, 0x2, 
    0x2, 0x4d, 0x4e, 0x7, 0x3, 0x2, 0x2, 0x4e, 0x4f, 0x7, 0x21, 0x2, 0x2, 
    0x4f, 0x51, 0x7, 0x4, 0x2, 0x2, 0x50, 0x52, 0x5, 0x1a, 0xe, 0x2, 0x51, 
    0x50, 0x3, 0x2, 0x2, 0x2, 0x51, 0x52, 0x3, 0x2, 0x2, 0x2, 0x52, 0x57, 
    0x3, 0x2, 0x2, 0x2, 0x53, 0x54, 0x7, 0x5, 0x2, 0x2, 0x54, 0x56, 0x5, 
    0x1a, 0xe, 0x2, 0x55, 0x53, 0x3, 0x2, 0x2, 0x2, 0x56, 0x59, 0x3, 0x2, 
    0x2, 0x2, 0x57, 0x55, 0x3, 0x2, 0x2, 0x2, 0x57, 0x58, 0x3, 0x2, 0x2, 
    0x2, 0x58, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x59, 0x57, 0x3, 0x2, 0x2, 0x2, 
    0x5a, 0x5b, 0x7, 0x6, 0x2, 0x2, 0x5b, 0x5c, 0x5, 0x22, 0x12, 0x2, 0x5c, 
    0x60, 0x7, 0x7, 0x2, 0x2, 0x5d, 0x5f, 0x5, 0xe, 0x8, 0x2, 0x5e, 0x5d, 
    0x3, 0x2, 0x2, 0x2, 0x5f, 0x62, 0x3, 0x2, 0x2, 0x2, 0x60, 0x5e, 0x3, 
    0x2, 0x2, 0x2, 0x60, 0x61, 0x3, 0x2, 0x2, 0x2, 0x61, 0x63, 0x3, 0x2, 
    0x2, 0x2, 0x62, 0x60, 0x3, 0x2, 0x2, 0x2, 0x63, 0x64, 0x7, 0x8, 0x2, 
    0x2, 0x64, 0x76, 0x3, 0x2, 0x2, 0x2, 0x65, 0x66, 0x7, 0x9, 0x2, 0x2, 
    0x66, 0x67, 0x7, 0x3, 0x2, 0x2, 0x67, 0x68, 0x7, 0x21, 0x2, 0x2, 0x68, 
    0x6a, 0x7, 0x4, 0x2, 0x2, 0x69, 0x6b, 0x5, 0x1a, 0xe, 0x2, 0x6a, 0x69, 
    0x3, 0x2, 0x2, 0x2, 0x6a, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x70, 0x3, 
    0x2, 0x2, 0x2, 0x6c, 0x6d, 0x7, 0x5, 0x2, 0x2, 0x6d, 0x6f, 0x5, 0x1a, 
    0xe, 0x2, 0x6e, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x72, 0x3, 0x2, 0x2, 
    0x2, 0x70, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x70, 0x71, 0x3, 0x2, 0x2, 0x2, 
    0x71, 0x73, 0x3, 0x2, 0x2, 0x2, 0x72, 0x70, 0x3, 0x2, 0x2, 0x2, 0x73, 
    0x74, 0x7, 0x6, 0x2, 0x2, 0x74, 0x76, 0x5, 0x22, 0x12, 0x2, 0x75, 0x4d, 
    0x3, 0x2, 0x2, 0x2, 0x75, 0x65, 0x3, 0x2, 0x2, 0x2, 0x76, 0x7, 0x3, 
    0x2, 0x2, 0x2, 0x77, 0x78, 0x7, 0xa, 0x2, 0x2, 0x78, 0x79, 0x7, 0x21, 
    0x2, 0x2, 0x79, 0x7a, 0x7, 0xb, 0x2, 0x2, 0x7a, 0x7b, 0x5, 0xe, 0x8, 
    0x2, 0x7b, 0x9, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x7d, 0x7, 0xc, 0x2, 0x2, 
    0x7d, 0x7e, 0x7, 0x21, 0x2, 0x2, 0x7e, 0x80, 0x7, 0x7, 0x2, 0x2, 0x7f, 
    0x81, 0x5, 0xc, 0x7, 0x2, 0x80, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x81, 0x82, 
    0x3, 0x2, 0x2, 0x2, 0x82, 0x80, 0x3, 0x2, 0x2, 0x2, 0x82, 0x83, 0x3, 
    0x2, 0x2, 0x2, 0x83, 0x84, 0x3, 0x2, 0x2, 0x2, 0x84, 0x85, 0x7, 0x8, 
    0x2, 0x2, 0x85, 0xb, 0x3, 0x2, 0x2, 0x2, 0x86, 0x87, 0x7, 0x21, 0x2, 
    0x2, 0x87, 0x8f, 0x5, 0x22, 0x12, 0x2, 0x88, 0x89, 0x7, 0x21, 0x2, 0x2, 
    0x89, 0x8a, 0x5, 0x22, 0x12, 0x2, 0x8a, 0x8c, 0x7, 0xb, 0x2, 0x2, 0x8b, 
    0x8d, 0x5, 0xe, 0x8, 0x2, 0x8c, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x8d, 
    0x3, 0x2, 0x2, 0x2, 0x8d, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x86, 0x3, 
    0x2, 0x2, 0x2, 0x8e, 0x88, 0x3, 0x2, 0x2, 0x2, 0x8f, 0xd, 0x3, 0x2, 
    0x2, 0x2, 0x90, 0x9a, 0x5, 0x10, 0x9, 0x2, 0x91, 0x9a, 0x5, 0x14, 0xb, 
    0x2, 0x92, 0x9a, 0x5, 0x18, 0xd, 0x2, 0x93, 0x9a, 0x5, 0x1c, 0xf, 0x2, 
    0x94, 0x9a, 0x5, 0x28, 0x15, 0x2, 0x95, 0x9a, 0x5, 0x2a, 0x16, 0x2, 
    0x96, 0x9a, 0x5, 0x34, 0x1b, 0x2, 0x97, 0x9a, 0x5, 0x38, 0x1d, 0x2, 
    0x98, 0x9a, 0x5, 0x3c, 0x1f, 0x2, 0x99, 0x90, 0x3, 0x2, 0x2, 0x2, 0x99, 
    0x91, 0x3, 0x2, 0x2, 0x2, 0x99, 0x92, 0x3, 0x2, 0x2, 0x2, 0x99, 0x93, 
    0x3, 0x2, 0x2, 0x2, 0x99, 0x94, 0x3, 0x2, 0x2, 0x2, 0x99, 0x95, 0x3, 
    0x2, 0x2, 0x2, 0x99, 0x96, 0x3, 0x2, 0x2, 0x2, 0x99, 0x97, 0x3, 0x2, 
    0x2, 0x2, 0x99, 0x98, 0x3, 0x2, 0x2, 0x2, 0x9a, 0xf, 0x3, 0x2, 0x2, 
    0x2, 0x9b, 0xa0, 0x5, 0x12, 0xa, 0x2, 0x9c, 0xa0, 0x7, 0x22, 0x2, 0x2, 
    0x9d, 0xa0, 0x7, 0x23, 0x2, 0x2, 0x9e, 0xa0, 0x7, 0x24, 0x2, 0x2, 0x9f, 
    0x9b, 0x3, 0x2, 0x2, 0x2, 0x9f, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x9f, 0x9d, 
    0x3, 0x2, 0x2, 0x2, 0x9f, 0x9e, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x11, 0x3, 
    0x2, 0x2, 0x2, 0xa1, 0xa6, 0x7, 0x21, 0x2, 0x2, 0xa2, 0xa3, 0x7, 0xd, 
    0x2, 0x2, 0xa3, 0xa5, 0x7, 0x21, 0x2, 0x2, 0xa4, 0xa2, 0x3, 0x2, 0x2, 
    0x2, 0xa5, 0xa8, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa4, 0x3, 0x2, 0x2, 0x2, 
    0xa6, 0xa7, 0x3, 0x2, 0x2, 0x2, 0xa7, 0x13, 0x3, 0x2, 0x2, 0x2, 0xa8, 
    0xa6, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xaa, 0x5, 0x12, 0xa, 0x2, 0xaa, 0xac, 
    0x7, 0x4, 0x2, 0x2, 0xab, 0xad, 0x5, 0x16, 0xc, 0x2, 0xac, 0xab, 0x3, 
    0x2, 0x2, 0x2, 0xac, 0xad, 0x3, 0x2, 0x2, 0x2, 0xad, 0xb2, 0x3, 0x2, 
    0x2, 0x2, 0xae, 0xaf, 0x7, 0x5, 0x2, 0x2, 0xaf, 0xb1, 0x5, 0x16, 0xc, 
    0x2, 0xb0, 0xae, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xb4, 0x3, 0x2, 0x2, 0x2, 
    0xb2, 0xb0, 0x3, 0x2, 0x2, 0x2, 0xb2, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xb3, 
    0xb5, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xb6, 
    0x7, 0x6, 0x2, 0x2, 0xb6, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb8, 0x7, 
    0x4, 0x2, 0x2, 0xb8, 0xb9, 0x5, 0xe, 0x8, 0x2, 0xb9, 0xba, 0x7, 0x6, 
    0x2, 0x2, 0xba, 0xbc, 0x7, 0x4, 0x2, 0x2, 0xbb, 0xbd, 0x5, 0x16, 0xc, 
    0x2, 0xbc, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xbd, 0x3, 0x2, 0x2, 0x2, 
    0xbd, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xbf, 0x7, 0x5, 0x2, 0x2, 0xbf, 
    0xc1, 0x5, 0x16, 0xc, 0x2, 0xc0, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xc4, 
    0x3, 0x2, 0x2, 0x2, 0xc2, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc3, 0x3, 
    0x2, 0x2, 0x2, 0xc3, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xc4, 0xc2, 0x3, 0x2, 
    0x2, 0x2, 0xc5, 0xc6, 0x7, 0x6, 0x2, 0x2, 0xc6, 0xc8, 0x3, 0x2, 0x2, 
    0x2, 0xc7, 0xa9, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xb7, 0x3, 0x2, 0x2, 0x2, 
    0xc8, 0x15, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xca, 0x5, 0xe, 0x8, 0x2, 0xca, 
    0x17, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xcc, 0x7, 0x3, 0x2, 0x2, 0xcc, 0xce, 
    0x7, 0x4, 0x2, 0x2, 0xcd, 0xcf, 0x5, 0x1a, 0xe, 0x2, 0xce, 0xcd, 0x3, 
    0x2, 0x2, 0x2, 0xce, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xd4, 0x3, 0x2, 
    0x2, 0x2, 0xd0, 0xd1, 0x7, 0x5, 0x2, 0x2, 0xd1, 0xd3, 0x5, 0x1a, 0xe, 
    0x2, 0xd2, 0xd0, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd6, 0x3, 0x2, 0x2, 0x2, 
    0xd4, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xd5, 0x3, 0x2, 0x2, 0x2, 0xd5, 
    0xd7, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xd4, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xd8, 
    0x7, 0x6, 0x2, 0x2, 0xd8, 0xd9, 0x5, 0x22, 0x12, 0x2, 0xd9, 0xdd, 0x7, 
    0x7, 0x2, 0x2, 0xda, 0xdc, 0x5, 0xe, 0x8, 0x2, 0xdb, 0xda, 0x3, 0x2, 
    0x2, 0x2, 0xdc, 0xdf, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xdb, 0x3, 0x2, 0x2, 
    0x2, 0xdd, 0xde, 0x3, 0x2, 0x2, 0x2, 0xde, 0xe0, 0x3, 0x2, 0x2, 0x2, 
    0xdf, 0xdd, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xe1, 0x7, 0x8, 0x2, 0x2, 0xe1, 
    0x19, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xe3, 0x7, 0x21, 0x2, 0x2, 0xe3, 0xe6, 
    0x5, 0x22, 0x12, 0x2, 0xe4, 0xe6, 0x5, 0x22, 0x12, 0x2, 0xe5, 0xe2, 
    0x3, 0x2, 0x2, 0x2, 0xe5, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xe6, 0x1b, 0x3, 
    0x2, 0x2, 0x2, 0xe7, 0xeb, 0x7, 0xe, 0x2, 0x2, 0xe8, 0xea, 0x5, 0x1e, 
    0x10, 0x2, 0xe9, 0xe8, 0x3, 0x2, 0x2, 0x2, 0xea, 0xed, 0x3, 0x2, 0x2, 
    0x2, 0xeb, 0xe9, 0x3, 0x2, 0x2, 0x2, 0xeb, 0xec, 0x3, 0x2, 0x2, 0x2, 
    0xec, 0xee, 0x3, 0x2, 0x2, 0x2, 0xed, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xee, 
    0xf2, 0x7, 0x7, 0x2, 0x2, 0xef, 0xf1, 0x5, 0xe, 0x8, 0x2, 0xf0, 0xef, 
    0x3, 0x2, 0x2, 0x2, 0xf1, 0xf4, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xf0, 0x3, 
    0x2, 0x2, 0x2, 0xf2, 0xf3, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xf5, 0x3, 0x2, 
    0x2, 0x2, 0xf4, 0xf2, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xf6, 0x7, 0x8, 0x2, 
    0x2, 0xf6, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xf9, 0x7, 0x21, 0x2, 0x2, 
    0xf8, 0xfa, 0x5, 0x22, 0x12, 0x2, 0xf9, 0xf8, 0x3, 0x2, 0x2, 0x2, 0xf9, 
    0xfa, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xfc, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xfd, 
    0x5, 0x20, 0x11, 0x2, 0xfc, 0xfb, 0x3, 0x2, 0x2, 0x2, 0xfc, 0xfd, 0x3, 
    0x2, 0x2, 0x2, 0xfd, 0xfe, 0x3, 0x2, 0x2, 0x2, 0xfe, 0xff, 0x7, 0xb, 
    0x2, 0x2, 0xff, 0x100, 0x5, 0xe, 0x8, 0x2, 0x100, 0x1f, 0x3, 0x2, 0x2, 
    0x2, 0x101, 0x102, 0x7, 0xf, 0x2, 0x2, 0x102, 0x21, 0x3, 0x2, 0x2, 0x2, 
    0x103, 0x106, 0x5, 0x24, 0x13, 0x2, 0x104, 0x106, 0x5, 0x26, 0x14, 0x2, 
    0x105, 0x103, 0x3, 0x2, 0x2, 0x2, 0x105, 0x104, 0x3, 0x2, 0x2, 0x2, 
    0x106, 0x23, 0x3, 0x2, 0x2, 0x2, 0x107, 0x109, 0x7, 0x10, 0x2, 0x2, 
    0x108, 0x10a, 0x7, 0x20, 0x2, 0x2, 0x109, 0x108, 0x3, 0x2, 0x2, 0x2, 
    0x109, 0x10a, 0x3, 0x2, 0x2, 0x2, 0x10a, 0x10b, 0x3, 0x2, 0x2, 0x2, 
    0x10b, 0x10c, 0x7, 0x21, 0x2, 0x2, 0x10c, 0x25, 0x3, 0x2, 0x2, 0x2, 
    0x10d, 0x10e, 0x7, 0x10, 0x2, 0x2, 0x10e, 0x10f, 0x7, 0x3, 0x2, 0x2, 
    0x10f, 0x111, 0x7, 0x4, 0x2, 0x2, 0x110, 0x112, 0x5, 0x1a, 0xe, 0x2, 
    0x111, 0x110, 0x3, 0x2, 0x2, 0x2, 0x111, 0x112, 0x3, 0x2, 0x2, 0x2, 
    0x112, 0x117, 0x3, 0x2, 0x2, 0x2, 0x113, 0x114, 0x7, 0x5, 0x2, 0x2, 
    0x114, 0x116, 0x5, 0x1a, 0xe, 0x2, 0x115, 0x113, 0x3, 0x2, 0x2, 0x2, 
    0x116, 0x119, 0x3, 0x2, 0x2, 0x2, 0x117, 0x115, 0x3, 0x2, 0x2, 0x2, 
    0x117, 0x118, 0x3, 0x2, 0x2, 0x2, 0x118, 0x11a, 0x3, 0x2, 0x2, 0x2, 
    0x119, 0x117, 0x3, 0x2, 0x2, 0x2, 0x11a, 0x11b, 0x7, 0x6, 0x2, 0x2, 
    0x11b, 0x11c, 0x5, 0x22, 0x12, 0x2, 0x11c, 0x27, 0x3, 0x2, 0x2, 0x2, 
    0x11d, 0x11e, 0x5, 0x12, 0xa, 0x2, 0x11e, 0x11f, 0x7, 0xb, 0x2, 0x2, 
    0x11f, 0x120, 0x5, 0xe, 0x8, 0x2, 0x120, 0x29, 0x3, 0x2, 0x2, 0x2, 0x121, 
    0x125, 0x5, 0x2e, 0x18, 0x2, 0x122, 0x124, 0x5, 0x30, 0x19, 0x2, 0x123, 
    0x122, 0x3, 0x2, 0x2, 0x2, 0x124, 0x127, 0x3, 0x2, 0x2, 0x2, 0x125, 
    0x123, 0x3, 0x2, 0x2, 0x2, 0x125, 0x126, 0x3, 0x2, 0x2, 0x2, 0x126, 
    0x128, 0x3, 0x2, 0x2, 0x2, 0x127, 0x125, 0x3, 0x2, 0x2, 0x2, 0x128, 
    0x129, 0x5, 0x32, 0x1a, 0x2, 0x129, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x12a, 
    0x12b, 0x5, 0xe, 0x8, 0x2, 0x12b, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x12c, 0x12d, 
    0x7, 0x11, 0x2, 0x2, 0x12d, 0x12e, 0x5, 0x2c, 0x17, 0x2, 0x12e, 0x130, 
    0x7, 0x7, 0x2, 0x2, 0x12f, 0x131, 0x5, 0xe, 0x8, 0x2, 0x130, 0x12f, 
    0x3, 0x2, 0x2, 0x2, 0x131, 0x132, 0x3, 0x2, 0x2, 0x2, 0x132, 0x130, 
    0x3, 0x2, 0x2, 0x2, 0x132, 0x133, 0x3, 0x2, 0x2, 0x2, 0x133, 0x134, 
    0x3, 0x2, 0x2, 0x2, 0x134, 0x135, 0x7, 0x8, 0x2, 0x2, 0x135, 0x2f, 0x3, 
    0x2, 0x2, 0x2, 0x136, 0x137, 0x7, 0x12, 0x2, 0x2, 0x137, 0x138, 0x7, 
    0x11, 0x2, 0x2, 0x138, 0x139, 0x5, 0x2c, 0x17, 0x2, 0x139, 0x13b, 0x7, 
    0x7, 0x2, 0x2, 0x13a, 0x13c, 0x5, 0xe, 0x8, 0x2, 0x13b, 0x13a, 0x3, 
    0x2, 0x2, 0x2, 0x13c, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x13d, 0x13b, 0x3, 
    0x2, 0x2, 0x2, 0x13d, 0x13e, 0x3, 0x2, 0x2, 0x2, 0x13e, 0x13f, 0x3, 
    0x2, 0x2, 0x2, 0x13f, 0x140, 0x7, 0x8, 0x2, 0x2, 0x140, 0x31, 0x3, 0x2, 
    0x2, 0x2, 0x141, 0x142, 0x7, 0x12, 0x2, 0x2, 0x142, 0x144, 0x7, 0x7, 
    0x2, 0x2, 0x143, 0x145, 0x5, 0xe, 0x8, 0x2, 0x144, 0x143, 0x3, 0x2, 
    0x2, 0x2, 0x145, 0x146, 0x3, 0x2, 0x2, 0x2, 0x146, 0x144, 0x3, 0x2, 
    0x2, 0x2, 0x146, 0x147, 0x3, 0x2, 0x2, 0x2, 0x147, 0x148, 0x3, 0x2, 
    0x2, 0x2, 0x148, 0x149, 0x7, 0x8, 0x2, 0x2, 0x149, 0x33, 0x3, 0x2, 0x2, 
    0x2, 0x14a, 0x14e, 0x7, 0x13, 0x2, 0x2, 0x14b, 0x14d, 0x5, 0x36, 0x1c, 
    0x2, 0x14c, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x14d, 0x150, 0x3, 0x2, 0x2, 
    0x2, 0x14e, 0x14c, 0x3, 0x2, 0x2, 0x2, 0x14e, 0x14f, 0x3, 0x2, 0x2, 
    0x2, 0x14f, 0x151, 0x3, 0x2, 0x2, 0x2, 0x150, 0x14e, 0x3, 0x2, 0x2, 
    0x2, 0x151, 0x155, 0x7, 0x7, 0x2, 0x2, 0x152, 0x154, 0x5, 0xe, 0x8, 
    0x2, 0x153, 0x152, 0x3, 0x2, 0x2, 0x2, 0x154, 0x157, 0x3, 0x2, 0x2, 
    0x2, 0x155, 0x153, 0x3, 0x2, 0x2, 0x2, 0x155, 0x156, 0x3, 0x2, 0x2, 
    0x2, 0x156, 0x158, 0x3, 0x2, 0x2, 0x2, 0x157, 0x155, 0x3, 0x2, 0x2, 
    0x2, 0x158, 0x159, 0x7, 0x8, 0x2, 0x2, 0x159, 0x35, 0x3, 0x2, 0x2, 0x2, 
    0x15a, 0x15b, 0x7, 0x4, 0x2, 0x2, 0x15b, 0x15d, 0x7, 0x21, 0x2, 0x2, 
    0x15c, 0x15e, 0x5, 0x22, 0x12, 0x2, 0x15d, 0x15c, 0x3, 0x2, 0x2, 0x2, 
    0x15d, 0x15e, 0x3, 0x2, 0x2, 0x2, 0x15e, 0x15f, 0x3, 0x2, 0x2, 0x2, 
    0x15f, 0x160, 0x7, 0xb, 0x2, 0x2, 0x160, 0x161, 0x5, 0xe, 0x8, 0x2, 
    0x161, 0x162, 0x7, 0x14, 0x2, 0x2, 0x162, 0x163, 0x5, 0xe, 0x8, 0x2, 
    0x163, 0x164, 0x7, 0x14, 0x2, 0x2, 0x164, 0x165, 0x5, 0xe, 0x8, 0x2, 
    0x165, 0x166, 0x7, 0x6, 0x2, 0x2, 0x166, 0x37, 0x3, 0x2, 0x2, 0x2, 0x167, 
    0x168, 0x7, 0x4, 0x2, 0x2, 0x168, 0x169, 0x5, 0xe, 0x8, 0x2, 0x169, 
    0x16a, 0x5, 0x3a, 0x1e, 0x2, 0x16a, 0x16b, 0x5, 0xe, 0x8, 0x2, 0x16b, 
    0x16c, 0x7, 0x6, 0x2, 0x2, 0x16c, 0x39, 0x3, 0x2, 0x2, 0x2, 0x16d, 0x16e, 
    0x9, 0x2, 0x2, 0x2, 0x16e, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x16f, 0x170, 0x5, 
    0x3e, 0x20, 0x2, 0x170, 0x171, 0x5, 0xe, 0x8, 0x2, 0x171, 0x3d, 0x3, 
    0x2, 0x2, 0x2, 0x172, 0x173, 0x9, 0x3, 0x2, 0x2, 0x173, 0x3f, 0x3, 0x2, 
    0x2, 0x2, 0x28, 0x43, 0x4b, 0x51, 0x57, 0x60, 0x6a, 0x70, 0x75, 0x82, 
    0x8c, 0x8e, 0x99, 0x9f, 0xa6, 0xac, 0xb2, 0xbc, 0xc2, 0xc7, 0xce, 0xd4, 
    0xdd, 0xe5, 0xeb, 0xf2, 0xf9, 0xfc, 0x105, 0x109, 0x111, 0x117, 0x125, 
    0x132, 0x13d, 0x146, 0x14e, 0x155, 0x15d, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

lidParser::Initializer lidParser::_init;
