
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
    setState(57);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << lidParser::T__0)
      | (1ULL << lidParser::T__6)
      | (1ULL << lidParser::T__7)
      | (1ULL << lidParser::T__9))) != 0)) {
      setState(54);
      toplevel();
      setState(59);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(60);
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
    setState(65);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case lidParser::T__0:
      case lidParser::T__6: {
        setState(62);
        namedFunction();
        break;
      }

      case lidParser::T__7: {
        setState(63);
        namedConstant();
        break;
      }

      case lidParser::T__9: {
        setState(64);
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
    setState(107);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case lidParser::T__0: {
        enterOuterAlt(_localctx, 1);
        setState(67);
        match(lidParser::T__0);
        setState(68);
        match(lidParser::IDENTIFIER);
        setState(69);
        match(lidParser::T__1);
        setState(71);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == lidParser::T__30

        || _la == lidParser::IDENTIFIER) {
          setState(70);
          typedParameter();
        }
        setState(77);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == lidParser::T__2) {
          setState(73);
          match(lidParser::T__2);
          setState(74);
          typedParameter();
          setState(79);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(80);
        match(lidParser::T__3);
        setState(81);
        typeName();
        setState(82);
        match(lidParser::T__4);
        setState(86);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << lidParser::T__0)
          | (1ULL << lidParser::T__1)
          | (1ULL << lidParser::T__10)
          | (1ULL << lidParser::T__11)
          | (1ULL << lidParser::T__12)
          | (1ULL << lidParser::T__13)
          | (1ULL << lidParser::T__28)
          | (1ULL << lidParser::T__31)
          | (1ULL << lidParser::T__33)
          | (1ULL << lidParser::IDENTIFIER)
          | (1ULL << lidParser::FLOAT_LITERAL)
          | (1ULL << lidParser::INTEGER_LITERAL)
          | (1ULL << lidParser::STRING_LITERAL))) != 0)) {
          setState(83);
          expression(0);
          setState(88);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(89);
        match(lidParser::T__5);
        break;
      }

      case lidParser::T__6: {
        enterOuterAlt(_localctx, 2);
        setState(91);
        match(lidParser::T__6);
        setState(92);
        match(lidParser::T__0);
        setState(93);
        match(lidParser::IDENTIFIER);
        setState(94);
        match(lidParser::T__1);
        setState(96);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == lidParser::T__30

        || _la == lidParser::IDENTIFIER) {
          setState(95);
          typedParameter();
        }
        setState(102);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == lidParser::T__2) {
          setState(98);
          match(lidParser::T__2);
          setState(99);
          typedParameter();
          setState(104);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(105);
        match(lidParser::T__3);
        setState(106);
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
    setState(109);
    match(lidParser::T__7);
    setState(110);
    match(lidParser::IDENTIFIER);
    setState(111);
    match(lidParser::T__8);
    setState(112);
    expression(0);
   
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
    setState(114);
    match(lidParser::T__9);
    setState(115);
    match(lidParser::IDENTIFIER);
    setState(116);
    match(lidParser::T__4);
    setState(118); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(117);
      structMember();
      setState(120); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == lidParser::IDENTIFIER);
    setState(122);
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
    setState(132);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(124);
      match(lidParser::IDENTIFIER);
      setState(125);
      typeName();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(126);
      match(lidParser::IDENTIFIER);
      setState(127);
      typeName();
      setState(128);
      match(lidParser::T__8);
      setState(130);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
      case 1: {
        setState(129);
        expression(0);
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

lidParser::CallableContext* lidParser::ExpressionContext::callable() {
  return getRuleContext<lidParser::CallableContext>(0);
}

lidParser::SymbolContext* lidParser::ExpressionContext::symbol() {
  return getRuleContext<lidParser::SymbolContext>(0);
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

std::vector<lidParser::ExpressionContext *> lidParser::ExpressionContext::expression() {
  return getRuleContexts<lidParser::ExpressionContext>();
}

lidParser::ExpressionContext* lidParser::ExpressionContext::expression(size_t i) {
  return getRuleContext<lidParser::ExpressionContext>(i);
}

tree::TerminalNode* lidParser::ExpressionContext::POINTER_PREFIX() {
  return getToken(lidParser::POINTER_PREFIX, 0);
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
   return expression(0);
}

lidParser::ExpressionContext* lidParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  lidParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  lidParser::ExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 12;
  enterRecursionRule(_localctx, 12, lidParser::RuleExpression, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(150);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      setState(135);
      callable();
      break;
    }

    case 2: {
      setState(136);
      symbol();
      break;
    }

    case 3: {
      setState(137);
      lambda();
      break;
    }

    case 4: {
      setState(138);
      let();
      break;
    }

    case 5: {
      setState(139);
      set();
      break;
    }

    case 6: {
      setState(140);
      branch();
      break;
    }

    case 7: {
      setState(141);
      loop();
      break;
    }

    case 8: {
      setState(142);
      dynamic_cast<ExpressionContext *>(_localctx)->unaryOperator = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == lidParser::T__10

      || _la == lidParser::T__11)) {
        dynamic_cast<ExpressionContext *>(_localctx)->unaryOperator = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(143);
      expression(12);
      break;
    }

    case 9: {
      setState(144);
      dynamic_cast<ExpressionContext *>(_localctx)->unaryOperator = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == lidParser::T__12

      || _la == lidParser::T__13)) {
        dynamic_cast<ExpressionContext *>(_localctx)->unaryOperator = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(145);
      expression(11);
      break;
    }

    case 10: {
      setState(146);
      dynamic_cast<ExpressionContext *>(_localctx)->nestedExpression = match(lidParser::T__1);
      setState(147);
      expression(0);
      setState(148);
      match(lidParser::T__3);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(181);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(179);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(152);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(153);
          dynamic_cast<ExpressionContext *>(_localctx)->binaryOperator = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << lidParser::T__14)
            | (1ULL << lidParser::T__15)
            | (1ULL << lidParser::T__16))) != 0))) {
            dynamic_cast<ExpressionContext *>(_localctx)->binaryOperator = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(154);
          expression(11);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(155);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(156);
          dynamic_cast<ExpressionContext *>(_localctx)->binaryOperator = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == lidParser::T__10

          || _la == lidParser::T__11)) {
            dynamic_cast<ExpressionContext *>(_localctx)->binaryOperator = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(157);
          expression(10);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(158);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(159);
          dynamic_cast<ExpressionContext *>(_localctx)->binaryOperator = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << lidParser::T__17)
            | (1ULL << lidParser::T__18)
            | (1ULL << lidParser::T__19)
            | (1ULL << lidParser::T__20))) != 0))) {
            dynamic_cast<ExpressionContext *>(_localctx)->binaryOperator = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(160);
          expression(9);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(161);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(162);
          dynamic_cast<ExpressionContext *>(_localctx)->binaryOperator = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == lidParser::T__21

          || _la == lidParser::T__22)) {
            dynamic_cast<ExpressionContext *>(_localctx)->binaryOperator = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(163);
          expression(8);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(164);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(165);
          dynamic_cast<ExpressionContext *>(_localctx)->binaryOperator = match(lidParser::POINTER_PREFIX);
          setState(166);
          expression(7);
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(167);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(168);
          dynamic_cast<ExpressionContext *>(_localctx)->binaryOperator = match(lidParser::T__23);
          setState(169);
          expression(6);
          break;
        }

        case 7: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(170);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(171);
          dynamic_cast<ExpressionContext *>(_localctx)->binaryOperator = match(lidParser::T__24);
          setState(172);
          expression(5);
          break;
        }

        case 8: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(173);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(174);
          dynamic_cast<ExpressionContext *>(_localctx)->binaryOperator = match(lidParser::T__25);
          setState(175);
          expression(4);
          break;
        }

        case 9: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(176);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(177);
          dynamic_cast<ExpressionContext *>(_localctx)->binaryOperator = match(lidParser::T__26);
          setState(178);
          expression(3);
          break;
        }

        } 
      }
      setState(183);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- SymbolNameContext ------------------------------------------------------------------

lidParser::SymbolNameContext::SymbolNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> lidParser::SymbolNameContext::IDENTIFIER() {
  return getTokens(lidParser::IDENTIFIER);
}

tree::TerminalNode* lidParser::SymbolNameContext::IDENTIFIER(size_t i) {
  return getToken(lidParser::IDENTIFIER, i);
}


size_t lidParser::SymbolNameContext::getRuleIndex() const {
  return lidParser::RuleSymbolName;
}


antlrcpp::Any lidParser::SymbolNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lidVisitor*>(visitor))
    return parserVisitor->visitSymbolName(this);
  else
    return visitor->visitChildren(this);
}

lidParser::SymbolNameContext* lidParser::symbolName() {
  SymbolNameContext *_localctx = _tracker.createInstance<SymbolNameContext>(_ctx, getState());
  enterRule(_localctx, 14, lidParser::RuleSymbolName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(184);
    match(lidParser::IDENTIFIER);
    setState(189);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(185);
        match(lidParser::T__27);
        setState(186);
        match(lidParser::IDENTIFIER); 
      }
      setState(191);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
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

lidParser::SymbolNameContext* lidParser::CallableContext::symbolName() {
  return getRuleContext<lidParser::SymbolNameContext>(0);
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
  enterRule(_localctx, 16, lidParser::RuleCallable);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(222);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case lidParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(192);
        symbolName();
        setState(193);
        match(lidParser::T__1);
        setState(195);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << lidParser::T__0)
          | (1ULL << lidParser::T__1)
          | (1ULL << lidParser::T__10)
          | (1ULL << lidParser::T__11)
          | (1ULL << lidParser::T__12)
          | (1ULL << lidParser::T__13)
          | (1ULL << lidParser::T__28)
          | (1ULL << lidParser::T__31)
          | (1ULL << lidParser::T__33)
          | (1ULL << lidParser::IDENTIFIER)
          | (1ULL << lidParser::FLOAT_LITERAL)
          | (1ULL << lidParser::INTEGER_LITERAL)
          | (1ULL << lidParser::STRING_LITERAL))) != 0)) {
          setState(194);
          parameter();
        }
        setState(201);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == lidParser::T__2) {
          setState(197);
          match(lidParser::T__2);
          setState(198);
          parameter();
          setState(203);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(204);
        match(lidParser::T__3);
        break;
      }

      case lidParser::T__1: {
        enterOuterAlt(_localctx, 2);
        setState(206);
        match(lidParser::T__1);
        setState(207);
        expression(0);
        setState(208);
        match(lidParser::T__3);
        setState(209);
        match(lidParser::T__1);
        setState(211);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << lidParser::T__0)
          | (1ULL << lidParser::T__1)
          | (1ULL << lidParser::T__10)
          | (1ULL << lidParser::T__11)
          | (1ULL << lidParser::T__12)
          | (1ULL << lidParser::T__13)
          | (1ULL << lidParser::T__28)
          | (1ULL << lidParser::T__31)
          | (1ULL << lidParser::T__33)
          | (1ULL << lidParser::IDENTIFIER)
          | (1ULL << lidParser::FLOAT_LITERAL)
          | (1ULL << lidParser::INTEGER_LITERAL)
          | (1ULL << lidParser::STRING_LITERAL))) != 0)) {
          setState(210);
          parameter();
        }
        setState(217);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == lidParser::T__2) {
          setState(213);
          match(lidParser::T__2);
          setState(214);
          parameter();
          setState(219);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(220);
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

//----------------- SymbolContext ------------------------------------------------------------------

lidParser::SymbolContext::SymbolContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

lidParser::SymbolNameContext* lidParser::SymbolContext::symbolName() {
  return getRuleContext<lidParser::SymbolNameContext>(0);
}

tree::TerminalNode* lidParser::SymbolContext::FLOAT_LITERAL() {
  return getToken(lidParser::FLOAT_LITERAL, 0);
}

tree::TerminalNode* lidParser::SymbolContext::INTEGER_LITERAL() {
  return getToken(lidParser::INTEGER_LITERAL, 0);
}

tree::TerminalNode* lidParser::SymbolContext::STRING_LITERAL() {
  return getToken(lidParser::STRING_LITERAL, 0);
}


size_t lidParser::SymbolContext::getRuleIndex() const {
  return lidParser::RuleSymbol;
}


antlrcpp::Any lidParser::SymbolContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<lidVisitor*>(visitor))
    return parserVisitor->visitSymbol(this);
  else
    return visitor->visitChildren(this);
}

lidParser::SymbolContext* lidParser::symbol() {
  SymbolContext *_localctx = _tracker.createInstance<SymbolContext>(_ctx, getState());
  enterRule(_localctx, 18, lidParser::RuleSymbol);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(228);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case lidParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(224);
        symbolName();
        break;
      }

      case lidParser::FLOAT_LITERAL: {
        enterOuterAlt(_localctx, 2);
        setState(225);
        match(lidParser::FLOAT_LITERAL);
        break;
      }

      case lidParser::INTEGER_LITERAL: {
        enterOuterAlt(_localctx, 3);
        setState(226);
        match(lidParser::INTEGER_LITERAL);
        break;
      }

      case lidParser::STRING_LITERAL: {
        enterOuterAlt(_localctx, 4);
        setState(227);
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
    setState(230);
    expression(0);
   
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
    setState(232);
    match(lidParser::T__0);
    setState(233);
    match(lidParser::T__1);
    setState(235);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == lidParser::T__30

    || _la == lidParser::IDENTIFIER) {
      setState(234);
      typedParameter();
    }
    setState(241);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == lidParser::T__2) {
      setState(237);
      match(lidParser::T__2);
      setState(238);
      typedParameter();
      setState(243);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(244);
    match(lidParser::T__3);
    setState(245);
    typeName();
    setState(246);
    match(lidParser::T__4);
    setState(250);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << lidParser::T__0)
      | (1ULL << lidParser::T__1)
      | (1ULL << lidParser::T__10)
      | (1ULL << lidParser::T__11)
      | (1ULL << lidParser::T__12)
      | (1ULL << lidParser::T__13)
      | (1ULL << lidParser::T__28)
      | (1ULL << lidParser::T__31)
      | (1ULL << lidParser::T__33)
      | (1ULL << lidParser::IDENTIFIER)
      | (1ULL << lidParser::FLOAT_LITERAL)
      | (1ULL << lidParser::INTEGER_LITERAL)
      | (1ULL << lidParser::STRING_LITERAL))) != 0)) {
      setState(247);
      expression(0);
      setState(252);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(253);
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
    setState(258);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case lidParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(255);
        match(lidParser::IDENTIFIER);
        setState(256);
        typeName();
        break;
      }

      case lidParser::T__30: {
        enterOuterAlt(_localctx, 2);
        setState(257);
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
    setState(260);
    match(lidParser::T__28);
    setState(264);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == lidParser::IDENTIFIER) {
      setState(261);
      typedValueBinding();
      setState(266);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(267);
    match(lidParser::T__4);
    setState(271);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << lidParser::T__0)
      | (1ULL << lidParser::T__1)
      | (1ULL << lidParser::T__10)
      | (1ULL << lidParser::T__11)
      | (1ULL << lidParser::T__12)
      | (1ULL << lidParser::T__13)
      | (1ULL << lidParser::T__28)
      | (1ULL << lidParser::T__31)
      | (1ULL << lidParser::T__33)
      | (1ULL << lidParser::IDENTIFIER)
      | (1ULL << lidParser::FLOAT_LITERAL)
      | (1ULL << lidParser::INTEGER_LITERAL)
      | (1ULL << lidParser::STRING_LITERAL))) != 0)) {
      setState(268);
      expression(0);
      setState(273);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(274);
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
    setState(276);
    match(lidParser::IDENTIFIER);
    setState(278);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == lidParser::T__30) {
      setState(277);
      typeName();
    }
    setState(281);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == lidParser::T__29) {
      setState(280);
      typedValueQualifier();
    }
    setState(283);
    match(lidParser::T__8);
    setState(284);
    expression(0);
   
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
    setState(286);
    match(lidParser::T__29);
   
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
    setState(290);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(288);
      regularTypeName();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(289);
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
    setState(292);
    match(lidParser::T__30);
    setState(294);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == lidParser::POINTER_PREFIX) {
      setState(293);
      match(lidParser::POINTER_PREFIX);
    }
    setState(296);
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
    setState(298);
    match(lidParser::T__30);
    setState(299);
    match(lidParser::T__0);
    setState(300);
    match(lidParser::T__1);
    setState(302);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == lidParser::T__30

    || _la == lidParser::IDENTIFIER) {
      setState(301);
      typedParameter();
    }
    setState(308);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == lidParser::T__2) {
      setState(304);
      match(lidParser::T__2);
      setState(305);
      typedParameter();
      setState(310);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(311);
    match(lidParser::T__3);
    setState(312);
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

lidParser::SymbolNameContext* lidParser::SetContext::symbolName() {
  return getRuleContext<lidParser::SymbolNameContext>(0);
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
    setState(314);
    symbolName();
    setState(315);
    match(lidParser::T__8);
    setState(316);
    expression(0);
   
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
    setState(318);
    branchBegin();
    setState(322);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(319);
        branchItem(); 
      }
      setState(324);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
    }
    setState(325);
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
    setState(327);
    expression(0);
   
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
    setState(329);
    match(lidParser::T__31);
    setState(330);
    branchCondition();
    setState(331);
    match(lidParser::T__4);
    setState(333); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(332);
      expression(0);
      setState(335); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << lidParser::T__0)
      | (1ULL << lidParser::T__1)
      | (1ULL << lidParser::T__10)
      | (1ULL << lidParser::T__11)
      | (1ULL << lidParser::T__12)
      | (1ULL << lidParser::T__13)
      | (1ULL << lidParser::T__28)
      | (1ULL << lidParser::T__31)
      | (1ULL << lidParser::T__33)
      | (1ULL << lidParser::IDENTIFIER)
      | (1ULL << lidParser::FLOAT_LITERAL)
      | (1ULL << lidParser::INTEGER_LITERAL)
      | (1ULL << lidParser::STRING_LITERAL))) != 0));
    setState(337);
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
    setState(339);
    match(lidParser::T__32);
    setState(340);
    match(lidParser::T__31);
    setState(341);
    branchCondition();
    setState(342);
    match(lidParser::T__4);
    setState(344); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(343);
      expression(0);
      setState(346); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << lidParser::T__0)
      | (1ULL << lidParser::T__1)
      | (1ULL << lidParser::T__10)
      | (1ULL << lidParser::T__11)
      | (1ULL << lidParser::T__12)
      | (1ULL << lidParser::T__13)
      | (1ULL << lidParser::T__28)
      | (1ULL << lidParser::T__31)
      | (1ULL << lidParser::T__33)
      | (1ULL << lidParser::IDENTIFIER)
      | (1ULL << lidParser::FLOAT_LITERAL)
      | (1ULL << lidParser::INTEGER_LITERAL)
      | (1ULL << lidParser::STRING_LITERAL))) != 0));
    setState(348);
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
    setState(350);
    match(lidParser::T__32);
    setState(351);
    match(lidParser::T__4);
    setState(353); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(352);
      expression(0);
      setState(355); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << lidParser::T__0)
      | (1ULL << lidParser::T__1)
      | (1ULL << lidParser::T__10)
      | (1ULL << lidParser::T__11)
      | (1ULL << lidParser::T__12)
      | (1ULL << lidParser::T__13)
      | (1ULL << lidParser::T__28)
      | (1ULL << lidParser::T__31)
      | (1ULL << lidParser::T__33)
      | (1ULL << lidParser::IDENTIFIER)
      | (1ULL << lidParser::FLOAT_LITERAL)
      | (1ULL << lidParser::INTEGER_LITERAL)
      | (1ULL << lidParser::STRING_LITERAL))) != 0));
    setState(357);
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
    setState(359);
    match(lidParser::T__33);
    setState(363);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == lidParser::T__1) {
      setState(360);
      loopBindingExpression();
      setState(365);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(366);
    match(lidParser::T__4);
    setState(370);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << lidParser::T__0)
      | (1ULL << lidParser::T__1)
      | (1ULL << lidParser::T__10)
      | (1ULL << lidParser::T__11)
      | (1ULL << lidParser::T__12)
      | (1ULL << lidParser::T__13)
      | (1ULL << lidParser::T__28)
      | (1ULL << lidParser::T__31)
      | (1ULL << lidParser::T__33)
      | (1ULL << lidParser::IDENTIFIER)
      | (1ULL << lidParser::FLOAT_LITERAL)
      | (1ULL << lidParser::INTEGER_LITERAL)
      | (1ULL << lidParser::STRING_LITERAL))) != 0)) {
      setState(367);
      expression(0);
      setState(372);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(373);
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
    setState(375);
    match(lidParser::T__1);
    setState(376);
    match(lidParser::IDENTIFIER);
    setState(378);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == lidParser::T__30) {
      setState(377);
      typeName();
    }
    setState(380);
    match(lidParser::T__8);
    setState(381);
    expression(0);
    setState(382);
    match(lidParser::T__34);
    setState(383);
    expression(0);
    setState(384);
    match(lidParser::T__34);
    setState(385);
    expression(0);
    setState(386);
    match(lidParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool lidParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 6: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool lidParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 10);
    case 1: return precpred(_ctx, 9);
    case 2: return precpred(_ctx, 8);
    case 3: return precpred(_ctx, 7);
    case 4: return precpred(_ctx, 6);
    case 5: return precpred(_ctx, 5);
    case 6: return precpred(_ctx, 4);
    case 7: return precpred(_ctx, 3);
    case 8: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> lidParser::_decisionToDFA;
atn::PredictionContextCache lidParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN lidParser::_atn;
std::vector<uint16_t> lidParser::_serializedATN;

std::vector<std::string> lidParser::_ruleNames = {
  "program", "toplevel", "namedFunction", "namedConstant", "namedStruct", 
  "structMember", "expression", "symbolName", "callable", "symbol", "parameter", 
  "lambda", "typedParameter", "let", "typedValueBinding", "typedValueQualifier", 
  "typeName", "regularTypeName", "functionTypeName", "set", "branch", "branchCondition", 
  "branchBegin", "branchItem", "branchEnd", "loop", "loopBindingExpression"
};

std::vector<std::string> lidParser::_literalNames = {
  "", "'function'", "'('", "','", "')'", "'{'", "'}'", "'extern'", "'const'", 
  "'='", "'struct'", "'+'", "'-'", "'~'", "'!'", "'*'", "'/'", "'%'", "'<='", 
  "'>='", "'>'", "'<'", "'=='", "'!='", "'^'", "'|'", "'&&'", "'||'", "'.'", 
  "'let'", "'#mutable'", "':'", "'if'", "'else'", "'for'", "';'", "", "'&'"
};

std::vector<std::string> lidParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "WHITESPACE", "POINTER_PREFIX", "IDENTIFIER", "FLOAT_LITERAL", "INTEGER_LITERAL", 
  "STRING_LITERAL", "LINE_COMMENT"
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
    0x3, 0x2c, 0x187, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x3, 0x2, 0x7, 0x2, 0x3a, 0xa, 0x2, 0xc, 0x2, 
    0xe, 0x2, 0x3d, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x5, 0x3, 0x44, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x5, 0x4, 0x4a, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x4e, 0xa, 0x4, 
    0xc, 0x4, 0xe, 0x4, 0x51, 0xb, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x7, 0x4, 0x57, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x5a, 0xb, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 
    0x4, 0x63, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x67, 0xa, 0x4, 0xc, 
    0x4, 0xe, 0x4, 0x6a, 0xb, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x6e, 0xa, 
    0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x6, 0x6, 0x79, 0xa, 0x6, 0xd, 0x6, 0xe, 0x6, 
    0x7a, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x5, 0x7, 0x85, 0xa, 0x7, 0x5, 0x7, 0x87, 0xa, 0x7, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x5, 0x8, 0x99, 0xa, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x7, 0x8, 0xb6, 0xa, 0x8, 0xc, 0x8, 0xe, 
    0x8, 0xb9, 0xb, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x7, 0x9, 0xbe, 0xa, 
    0x9, 0xc, 0x9, 0xe, 0x9, 0xc1, 0xb, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x5, 0xa, 0xc6, 0xa, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0xca, 0xa, 0xa, 
    0xc, 0xa, 0xe, 0xa, 0xcd, 0xb, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0xd6, 0xa, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x7, 0xa, 0xda, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0xdd, 0xb, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0xe1, 0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x5, 0xb, 0xe7, 0xa, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0xee, 0xa, 0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 
    0xd, 0xf2, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0xf5, 0xb, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 0xfb, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 
    0xfe, 0xb, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 
    0xe, 0x105, 0xa, 0xe, 0x3, 0xf, 0x3, 0xf, 0x7, 0xf, 0x109, 0xa, 0xf, 
    0xc, 0xf, 0xe, 0xf, 0x10c, 0xb, 0xf, 0x3, 0xf, 0x3, 0xf, 0x7, 0xf, 0x110, 
    0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0x113, 0xb, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0x10, 0x3, 0x10, 0x5, 0x10, 0x119, 0xa, 0x10, 0x3, 0x10, 0x5, 0x10, 
    0x11c, 0xa, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0x125, 0xa, 0x12, 0x3, 0x13, 0x3, 0x13, 
    0x5, 0x13, 0x129, 0xa, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0x131, 0xa, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x7, 0x14, 0x135, 0xa, 0x14, 0xc, 0x14, 0xe, 0x14, 0x138, 0xb, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 
    0x15, 0x3, 0x16, 0x3, 0x16, 0x7, 0x16, 0x143, 0xa, 0x16, 0xc, 0x16, 
    0xe, 0x16, 0x146, 0xb, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 
    0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x6, 0x18, 0x150, 0xa, 0x18, 
    0xd, 0x18, 0xe, 0x18, 0x151, 0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 0x3, 0x19, 
    0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x6, 0x19, 0x15b, 0xa, 0x19, 0xd, 0x19, 
    0xe, 0x19, 0x15c, 0x3, 0x19, 0x3, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 
    0x6, 0x1a, 0x164, 0xa, 0x1a, 0xd, 0x1a, 0xe, 0x1a, 0x165, 0x3, 0x1a, 
    0x3, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x7, 0x1b, 0x16c, 0xa, 0x1b, 0xc, 0x1b, 
    0xe, 0x1b, 0x16f, 0xb, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x7, 0x1b, 0x173, 
    0xa, 0x1b, 0xc, 0x1b, 0xe, 0x1b, 0x176, 0xb, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 
    0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x17d, 0xa, 0x1c, 0x3, 0x1c, 
    0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 
    0x1c, 0x3, 0x1c, 0x2, 0x3, 0xe, 0x1d, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 
    0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 
    0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x2, 0x7, 0x3, 
    0x2, 0xd, 0xe, 0x3, 0x2, 0xf, 0x10, 0x3, 0x2, 0x11, 0x13, 0x3, 0x2, 
    0x14, 0x17, 0x3, 0x2, 0x18, 0x19, 0x2, 0x1a5, 0x2, 0x3b, 0x3, 0x2, 0x2, 
    0x2, 0x4, 0x43, 0x3, 0x2, 0x2, 0x2, 0x6, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x8, 
    0x6f, 0x3, 0x2, 0x2, 0x2, 0xa, 0x74, 0x3, 0x2, 0x2, 0x2, 0xc, 0x86, 
    0x3, 0x2, 0x2, 0x2, 0xe, 0x98, 0x3, 0x2, 0x2, 0x2, 0x10, 0xba, 0x3, 
    0x2, 0x2, 0x2, 0x12, 0xe0, 0x3, 0x2, 0x2, 0x2, 0x14, 0xe6, 0x3, 0x2, 
    0x2, 0x2, 0x16, 0xe8, 0x3, 0x2, 0x2, 0x2, 0x18, 0xea, 0x3, 0x2, 0x2, 
    0x2, 0x1a, 0x104, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x106, 0x3, 0x2, 0x2, 0x2, 
    0x1e, 0x116, 0x3, 0x2, 0x2, 0x2, 0x20, 0x120, 0x3, 0x2, 0x2, 0x2, 0x22, 
    0x124, 0x3, 0x2, 0x2, 0x2, 0x24, 0x126, 0x3, 0x2, 0x2, 0x2, 0x26, 0x12c, 
    0x3, 0x2, 0x2, 0x2, 0x28, 0x13c, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x140, 0x3, 
    0x2, 0x2, 0x2, 0x2c, 0x149, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x14b, 0x3, 0x2, 
    0x2, 0x2, 0x30, 0x155, 0x3, 0x2, 0x2, 0x2, 0x32, 0x160, 0x3, 0x2, 0x2, 
    0x2, 0x34, 0x169, 0x3, 0x2, 0x2, 0x2, 0x36, 0x179, 0x3, 0x2, 0x2, 0x2, 
    0x38, 0x3a, 0x5, 0x4, 0x3, 0x2, 0x39, 0x38, 0x3, 0x2, 0x2, 0x2, 0x3a, 
    0x3d, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x39, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x3c, 
    0x3, 0x2, 0x2, 0x2, 0x3c, 0x3e, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x3b, 0x3, 
    0x2, 0x2, 0x2, 0x3e, 0x3f, 0x7, 0x2, 0x2, 0x3, 0x3f, 0x3, 0x3, 0x2, 
    0x2, 0x2, 0x40, 0x44, 0x5, 0x6, 0x4, 0x2, 0x41, 0x44, 0x5, 0x8, 0x5, 
    0x2, 0x42, 0x44, 0x5, 0xa, 0x6, 0x2, 0x43, 0x40, 0x3, 0x2, 0x2, 0x2, 
    0x43, 0x41, 0x3, 0x2, 0x2, 0x2, 0x43, 0x42, 0x3, 0x2, 0x2, 0x2, 0x44, 
    0x5, 0x3, 0x2, 0x2, 0x2, 0x45, 0x46, 0x7, 0x3, 0x2, 0x2, 0x46, 0x47, 
    0x7, 0x28, 0x2, 0x2, 0x47, 0x49, 0x7, 0x4, 0x2, 0x2, 0x48, 0x4a, 0x5, 
    0x1a, 0xe, 0x2, 0x49, 0x48, 0x3, 0x2, 0x2, 0x2, 0x49, 0x4a, 0x3, 0x2, 
    0x2, 0x2, 0x4a, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x4c, 0x7, 0x5, 0x2, 
    0x2, 0x4c, 0x4e, 0x5, 0x1a, 0xe, 0x2, 0x4d, 0x4b, 0x3, 0x2, 0x2, 0x2, 
    0x4e, 0x51, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x4f, 
    0x50, 0x3, 0x2, 0x2, 0x2, 0x50, 0x52, 0x3, 0x2, 0x2, 0x2, 0x51, 0x4f, 
    0x3, 0x2, 0x2, 0x2, 0x52, 0x53, 0x7, 0x6, 0x2, 0x2, 0x53, 0x54, 0x5, 
    0x22, 0x12, 0x2, 0x54, 0x58, 0x7, 0x7, 0x2, 0x2, 0x55, 0x57, 0x5, 0xe, 
    0x8, 0x2, 0x56, 0x55, 0x3, 0x2, 0x2, 0x2, 0x57, 0x5a, 0x3, 0x2, 0x2, 
    0x2, 0x58, 0x56, 0x3, 0x2, 0x2, 0x2, 0x58, 0x59, 0x3, 0x2, 0x2, 0x2, 
    0x59, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x58, 0x3, 0x2, 0x2, 0x2, 0x5b, 
    0x5c, 0x7, 0x8, 0x2, 0x2, 0x5c, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x5e, 
    0x7, 0x9, 0x2, 0x2, 0x5e, 0x5f, 0x7, 0x3, 0x2, 0x2, 0x5f, 0x60, 0x7, 
    0x28, 0x2, 0x2, 0x60, 0x62, 0x7, 0x4, 0x2, 0x2, 0x61, 0x63, 0x5, 0x1a, 
    0xe, 0x2, 0x62, 0x61, 0x3, 0x2, 0x2, 0x2, 0x62, 0x63, 0x3, 0x2, 0x2, 
    0x2, 0x63, 0x68, 0x3, 0x2, 0x2, 0x2, 0x64, 0x65, 0x7, 0x5, 0x2, 0x2, 
    0x65, 0x67, 0x5, 0x1a, 0xe, 0x2, 0x66, 0x64, 0x3, 0x2, 0x2, 0x2, 0x67, 
    0x6a, 0x3, 0x2, 0x2, 0x2, 0x68, 0x66, 0x3, 0x2, 0x2, 0x2, 0x68, 0x69, 
    0x3, 0x2, 0x2, 0x2, 0x69, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x68, 0x3, 
    0x2, 0x2, 0x2, 0x6b, 0x6c, 0x7, 0x6, 0x2, 0x2, 0x6c, 0x6e, 0x5, 0x22, 
    0x12, 0x2, 0x6d, 0x45, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x5d, 0x3, 0x2, 0x2, 
    0x2, 0x6e, 0x7, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x70, 0x7, 0xa, 0x2, 0x2, 
    0x70, 0x71, 0x7, 0x28, 0x2, 0x2, 0x71, 0x72, 0x7, 0xb, 0x2, 0x2, 0x72, 
    0x73, 0x5, 0xe, 0x8, 0x2, 0x73, 0x9, 0x3, 0x2, 0x2, 0x2, 0x74, 0x75, 
    0x7, 0xc, 0x2, 0x2, 0x75, 0x76, 0x7, 0x28, 0x2, 0x2, 0x76, 0x78, 0x7, 
    0x7, 0x2, 0x2, 0x77, 0x79, 0x5, 0xc, 0x7, 0x2, 0x78, 0x77, 0x3, 0x2, 
    0x2, 0x2, 0x79, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x78, 0x3, 0x2, 0x2, 
    0x2, 0x7a, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x7c, 0x3, 0x2, 0x2, 0x2, 
    0x7c, 0x7d, 0x7, 0x8, 0x2, 0x2, 0x7d, 0xb, 0x3, 0x2, 0x2, 0x2, 0x7e, 
    0x7f, 0x7, 0x28, 0x2, 0x2, 0x7f, 0x87, 0x5, 0x22, 0x12, 0x2, 0x80, 0x81, 
    0x7, 0x28, 0x2, 0x2, 0x81, 0x82, 0x5, 0x22, 0x12, 0x2, 0x82, 0x84, 0x7, 
    0xb, 0x2, 0x2, 0x83, 0x85, 0x5, 0xe, 0x8, 0x2, 0x84, 0x83, 0x3, 0x2, 
    0x2, 0x2, 0x84, 0x85, 0x3, 0x2, 0x2, 0x2, 0x85, 0x87, 0x3, 0x2, 0x2, 
    0x2, 0x86, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x86, 0x80, 0x3, 0x2, 0x2, 0x2, 
    0x87, 0xd, 0x3, 0x2, 0x2, 0x2, 0x88, 0x89, 0x8, 0x8, 0x1, 0x2, 0x89, 
    0x99, 0x5, 0x12, 0xa, 0x2, 0x8a, 0x99, 0x5, 0x14, 0xb, 0x2, 0x8b, 0x99, 
    0x5, 0x18, 0xd, 0x2, 0x8c, 0x99, 0x5, 0x1c, 0xf, 0x2, 0x8d, 0x99, 0x5, 
    0x28, 0x15, 0x2, 0x8e, 0x99, 0x5, 0x2a, 0x16, 0x2, 0x8f, 0x99, 0x5, 
    0x34, 0x1b, 0x2, 0x90, 0x91, 0x9, 0x2, 0x2, 0x2, 0x91, 0x99, 0x5, 0xe, 
    0x8, 0xe, 0x92, 0x93, 0x9, 0x3, 0x2, 0x2, 0x93, 0x99, 0x5, 0xe, 0x8, 
    0xd, 0x94, 0x95, 0x7, 0x4, 0x2, 0x2, 0x95, 0x96, 0x5, 0xe, 0x8, 0x2, 
    0x96, 0x97, 0x7, 0x6, 0x2, 0x2, 0x97, 0x99, 0x3, 0x2, 0x2, 0x2, 0x98, 
    0x88, 0x3, 0x2, 0x2, 0x2, 0x98, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x98, 0x8b, 
    0x3, 0x2, 0x2, 0x2, 0x98, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x98, 0x8d, 0x3, 
    0x2, 0x2, 0x2, 0x98, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x98, 0x8f, 0x3, 0x2, 
    0x2, 0x2, 0x98, 0x90, 0x3, 0x2, 0x2, 0x2, 0x98, 0x92, 0x3, 0x2, 0x2, 
    0x2, 0x98, 0x94, 0x3, 0x2, 0x2, 0x2, 0x99, 0xb7, 0x3, 0x2, 0x2, 0x2, 
    0x9a, 0x9b, 0xc, 0xc, 0x2, 0x2, 0x9b, 0x9c, 0x9, 0x4, 0x2, 0x2, 0x9c, 
    0xb6, 0x5, 0xe, 0x8, 0xd, 0x9d, 0x9e, 0xc, 0xb, 0x2, 0x2, 0x9e, 0x9f, 
    0x9, 0x2, 0x2, 0x2, 0x9f, 0xb6, 0x5, 0xe, 0x8, 0xc, 0xa0, 0xa1, 0xc, 
    0xa, 0x2, 0x2, 0xa1, 0xa2, 0x9, 0x5, 0x2, 0x2, 0xa2, 0xb6, 0x5, 0xe, 
    0x8, 0xb, 0xa3, 0xa4, 0xc, 0x9, 0x2, 0x2, 0xa4, 0xa5, 0x9, 0x6, 0x2, 
    0x2, 0xa5, 0xb6, 0x5, 0xe, 0x8, 0xa, 0xa6, 0xa7, 0xc, 0x8, 0x2, 0x2, 
    0xa7, 0xa8, 0x7, 0x27, 0x2, 0x2, 0xa8, 0xb6, 0x5, 0xe, 0x8, 0x9, 0xa9, 
    0xaa, 0xc, 0x7, 0x2, 0x2, 0xaa, 0xab, 0x7, 0x1a, 0x2, 0x2, 0xab, 0xb6, 
    0x5, 0xe, 0x8, 0x8, 0xac, 0xad, 0xc, 0x6, 0x2, 0x2, 0xad, 0xae, 0x7, 
    0x1b, 0x2, 0x2, 0xae, 0xb6, 0x5, 0xe, 0x8, 0x7, 0xaf, 0xb0, 0xc, 0x5, 
    0x2, 0x2, 0xb0, 0xb1, 0x7, 0x1c, 0x2, 0x2, 0xb1, 0xb6, 0x5, 0xe, 0x8, 
    0x6, 0xb2, 0xb3, 0xc, 0x4, 0x2, 0x2, 0xb3, 0xb4, 0x7, 0x1d, 0x2, 0x2, 
    0xb4, 0xb6, 0x5, 0xe, 0x8, 0x5, 0xb5, 0x9a, 0x3, 0x2, 0x2, 0x2, 0xb5, 
    0x9d, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xa0, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xa3, 
    0x3, 0x2, 0x2, 0x2, 0xb5, 0xa6, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xa9, 0x3, 
    0x2, 0x2, 0x2, 0xb5, 0xac, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xaf, 0x3, 0x2, 
    0x2, 0x2, 0xb5, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xb6, 0xb9, 0x3, 0x2, 0x2, 
    0x2, 0xb7, 0xb5, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb8, 0x3, 0x2, 0x2, 0x2, 
    0xb8, 0xf, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xb7, 0x3, 0x2, 0x2, 0x2, 0xba, 
    0xbf, 0x7, 0x28, 0x2, 0x2, 0xbb, 0xbc, 0x7, 0x1e, 0x2, 0x2, 0xbc, 0xbe, 
    0x7, 0x28, 0x2, 0x2, 0xbd, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xc1, 0x3, 
    0x2, 0x2, 0x2, 0xbf, 0xbd, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xc0, 0x3, 0x2, 
    0x2, 0x2, 0xc0, 0x11, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xbf, 0x3, 0x2, 0x2, 
    0x2, 0xc2, 0xc3, 0x5, 0x10, 0x9, 0x2, 0xc3, 0xc5, 0x7, 0x4, 0x2, 0x2, 
    0xc4, 0xc6, 0x5, 0x16, 0xc, 0x2, 0xc5, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xc5, 
    0xc6, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xcb, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xc8, 
    0x7, 0x5, 0x2, 0x2, 0xc8, 0xca, 0x5, 0x16, 0xc, 0x2, 0xc9, 0xc7, 0x3, 
    0x2, 0x2, 0x2, 0xca, 0xcd, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xc9, 0x3, 0x2, 
    0x2, 0x2, 0xcb, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xce, 0x3, 0x2, 0x2, 
    0x2, 0xcd, 0xcb, 0x3, 0x2, 0x2, 0x2, 0xce, 0xcf, 0x7, 0x6, 0x2, 0x2, 
    0xcf, 0xe1, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xd1, 0x7, 0x4, 0x2, 0x2, 0xd1, 
    0xd2, 0x5, 0xe, 0x8, 0x2, 0xd2, 0xd3, 0x7, 0x6, 0x2, 0x2, 0xd3, 0xd5, 
    0x7, 0x4, 0x2, 0x2, 0xd4, 0xd6, 0x5, 0x16, 0xc, 0x2, 0xd5, 0xd4, 0x3, 
    0x2, 0x2, 0x2, 0xd5, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xdb, 0x3, 0x2, 
    0x2, 0x2, 0xd7, 0xd8, 0x7, 0x5, 0x2, 0x2, 0xd8, 0xda, 0x5, 0x16, 0xc, 
    0x2, 0xd9, 0xd7, 0x3, 0x2, 0x2, 0x2, 0xda, 0xdd, 0x3, 0x2, 0x2, 0x2, 
    0xdb, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xdc, 0x3, 0x2, 0x2, 0x2, 0xdc, 
    0xde, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xde, 0xdf, 
    0x7, 0x6, 0x2, 0x2, 0xdf, 0xe1, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xc2, 0x3, 
    0x2, 0x2, 0x2, 0xe0, 0xd0, 0x3, 0x2, 0x2, 0x2, 0xe1, 0x13, 0x3, 0x2, 
    0x2, 0x2, 0xe2, 0xe7, 0x5, 0x10, 0x9, 0x2, 0xe3, 0xe7, 0x7, 0x29, 0x2, 
    0x2, 0xe4, 0xe7, 0x7, 0x2a, 0x2, 0x2, 0xe5, 0xe7, 0x7, 0x2b, 0x2, 0x2, 
    0xe6, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xe6, 0xe3, 0x3, 0x2, 0x2, 0x2, 0xe6, 
    0xe4, 0x3, 0x2, 0x2, 0x2, 0xe6, 0xe5, 0x3, 0x2, 0x2, 0x2, 0xe7, 0x15, 
    0x3, 0x2, 0x2, 0x2, 0xe8, 0xe9, 0x5, 0xe, 0x8, 0x2, 0xe9, 0x17, 0x3, 
    0x2, 0x2, 0x2, 0xea, 0xeb, 0x7, 0x3, 0x2, 0x2, 0xeb, 0xed, 0x7, 0x4, 
    0x2, 0x2, 0xec, 0xee, 0x5, 0x1a, 0xe, 0x2, 0xed, 0xec, 0x3, 0x2, 0x2, 
    0x2, 0xed, 0xee, 0x3, 0x2, 0x2, 0x2, 0xee, 0xf3, 0x3, 0x2, 0x2, 0x2, 
    0xef, 0xf0, 0x7, 0x5, 0x2, 0x2, 0xf0, 0xf2, 0x5, 0x1a, 0xe, 0x2, 0xf1, 
    0xef, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xf5, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xf1, 
    0x3, 0x2, 0x2, 0x2, 0xf3, 0xf4, 0x3, 0x2, 0x2, 0x2, 0xf4, 0xf6, 0x3, 
    0x2, 0x2, 0x2, 0xf5, 0xf3, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xf7, 0x7, 0x6, 
    0x2, 0x2, 0xf7, 0xf8, 0x5, 0x22, 0x12, 0x2, 0xf8, 0xfc, 0x7, 0x7, 0x2, 
    0x2, 0xf9, 0xfb, 0x5, 0xe, 0x8, 0x2, 0xfa, 0xf9, 0x3, 0x2, 0x2, 0x2, 
    0xfb, 0xfe, 0x3, 0x2, 0x2, 0x2, 0xfc, 0xfa, 0x3, 0x2, 0x2, 0x2, 0xfc, 
    0xfd, 0x3, 0x2, 0x2, 0x2, 0xfd, 0xff, 0x3, 0x2, 0x2, 0x2, 0xfe, 0xfc, 
    0x3, 0x2, 0x2, 0x2, 0xff, 0x100, 0x7, 0x8, 0x2, 0x2, 0x100, 0x19, 0x3, 
    0x2, 0x2, 0x2, 0x101, 0x102, 0x7, 0x28, 0x2, 0x2, 0x102, 0x105, 0x5, 
    0x22, 0x12, 0x2, 0x103, 0x105, 0x5, 0x22, 0x12, 0x2, 0x104, 0x101, 0x3, 
    0x2, 0x2, 0x2, 0x104, 0x103, 0x3, 0x2, 0x2, 0x2, 0x105, 0x1b, 0x3, 0x2, 
    0x2, 0x2, 0x106, 0x10a, 0x7, 0x1f, 0x2, 0x2, 0x107, 0x109, 0x5, 0x1e, 
    0x10, 0x2, 0x108, 0x107, 0x3, 0x2, 0x2, 0x2, 0x109, 0x10c, 0x3, 0x2, 
    0x2, 0x2, 0x10a, 0x108, 0x3, 0x2, 0x2, 0x2, 0x10a, 0x10b, 0x3, 0x2, 
    0x2, 0x2, 0x10b, 0x10d, 0x3, 0x2, 0x2, 0x2, 0x10c, 0x10a, 0x3, 0x2, 
    0x2, 0x2, 0x10d, 0x111, 0x7, 0x7, 0x2, 0x2, 0x10e, 0x110, 0x5, 0xe, 
    0x8, 0x2, 0x10f, 0x10e, 0x3, 0x2, 0x2, 0x2, 0x110, 0x113, 0x3, 0x2, 
    0x2, 0x2, 0x111, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x111, 0x112, 0x3, 0x2, 
    0x2, 0x2, 0x112, 0x114, 0x3, 0x2, 0x2, 0x2, 0x113, 0x111, 0x3, 0x2, 
    0x2, 0x2, 0x114, 0x115, 0x7, 0x8, 0x2, 0x2, 0x115, 0x1d, 0x3, 0x2, 0x2, 
    0x2, 0x116, 0x118, 0x7, 0x28, 0x2, 0x2, 0x117, 0x119, 0x5, 0x22, 0x12, 
    0x2, 0x118, 0x117, 0x3, 0x2, 0x2, 0x2, 0x118, 0x119, 0x3, 0x2, 0x2, 
    0x2, 0x119, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x11a, 0x11c, 0x5, 0x20, 0x11, 
    0x2, 0x11b, 0x11a, 0x3, 0x2, 0x2, 0x2, 0x11b, 0x11c, 0x3, 0x2, 0x2, 
    0x2, 0x11c, 0x11d, 0x3, 0x2, 0x2, 0x2, 0x11d, 0x11e, 0x7, 0xb, 0x2, 
    0x2, 0x11e, 0x11f, 0x5, 0xe, 0x8, 0x2, 0x11f, 0x1f, 0x3, 0x2, 0x2, 0x2, 
    0x120, 0x121, 0x7, 0x20, 0x2, 0x2, 0x121, 0x21, 0x3, 0x2, 0x2, 0x2, 
    0x122, 0x125, 0x5, 0x24, 0x13, 0x2, 0x123, 0x125, 0x5, 0x26, 0x14, 0x2, 
    0x124, 0x122, 0x3, 0x2, 0x2, 0x2, 0x124, 0x123, 0x3, 0x2, 0x2, 0x2, 
    0x125, 0x23, 0x3, 0x2, 0x2, 0x2, 0x126, 0x128, 0x7, 0x21, 0x2, 0x2, 
    0x127, 0x129, 0x7, 0x27, 0x2, 0x2, 0x128, 0x127, 0x3, 0x2, 0x2, 0x2, 
    0x128, 0x129, 0x3, 0x2, 0x2, 0x2, 0x129, 0x12a, 0x3, 0x2, 0x2, 0x2, 
    0x12a, 0x12b, 0x7, 0x28, 0x2, 0x2, 0x12b, 0x25, 0x3, 0x2, 0x2, 0x2, 
    0x12c, 0x12d, 0x7, 0x21, 0x2, 0x2, 0x12d, 0x12e, 0x7, 0x3, 0x2, 0x2, 
    0x12e, 0x130, 0x7, 0x4, 0x2, 0x2, 0x12f, 0x131, 0x5, 0x1a, 0xe, 0x2, 
    0x130, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x130, 0x131, 0x3, 0x2, 0x2, 0x2, 
    0x131, 0x136, 0x3, 0x2, 0x2, 0x2, 0x132, 0x133, 0x7, 0x5, 0x2, 0x2, 
    0x133, 0x135, 0x5, 0x1a, 0xe, 0x2, 0x134, 0x132, 0x3, 0x2, 0x2, 0x2, 
    0x135, 0x138, 0x3, 0x2, 0x2, 0x2, 0x136, 0x134, 0x3, 0x2, 0x2, 0x2, 
    0x136, 0x137, 0x3, 0x2, 0x2, 0x2, 0x137, 0x139, 0x3, 0x2, 0x2, 0x2, 
    0x138, 0x136, 0x3, 0x2, 0x2, 0x2, 0x139, 0x13a, 0x7, 0x6, 0x2, 0x2, 
    0x13a, 0x13b, 0x5, 0x22, 0x12, 0x2, 0x13b, 0x27, 0x3, 0x2, 0x2, 0x2, 
    0x13c, 0x13d, 0x5, 0x10, 0x9, 0x2, 0x13d, 0x13e, 0x7, 0xb, 0x2, 0x2, 
    0x13e, 0x13f, 0x5, 0xe, 0x8, 0x2, 0x13f, 0x29, 0x3, 0x2, 0x2, 0x2, 0x140, 
    0x144, 0x5, 0x2e, 0x18, 0x2, 0x141, 0x143, 0x5, 0x30, 0x19, 0x2, 0x142, 
    0x141, 0x3, 0x2, 0x2, 0x2, 0x143, 0x146, 0x3, 0x2, 0x2, 0x2, 0x144, 
    0x142, 0x3, 0x2, 0x2, 0x2, 0x144, 0x145, 0x3, 0x2, 0x2, 0x2, 0x145, 
    0x147, 0x3, 0x2, 0x2, 0x2, 0x146, 0x144, 0x3, 0x2, 0x2, 0x2, 0x147, 
    0x148, 0x5, 0x32, 0x1a, 0x2, 0x148, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x149, 
    0x14a, 0x5, 0xe, 0x8, 0x2, 0x14a, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x14b, 0x14c, 
    0x7, 0x22, 0x2, 0x2, 0x14c, 0x14d, 0x5, 0x2c, 0x17, 0x2, 0x14d, 0x14f, 
    0x7, 0x7, 0x2, 0x2, 0x14e, 0x150, 0x5, 0xe, 0x8, 0x2, 0x14f, 0x14e, 
    0x3, 0x2, 0x2, 0x2, 0x150, 0x151, 0x3, 0x2, 0x2, 0x2, 0x151, 0x14f, 
    0x3, 0x2, 0x2, 0x2, 0x151, 0x152, 0x3, 0x2, 0x2, 0x2, 0x152, 0x153, 
    0x3, 0x2, 0x2, 0x2, 0x153, 0x154, 0x7, 0x8, 0x2, 0x2, 0x154, 0x2f, 0x3, 
    0x2, 0x2, 0x2, 0x155, 0x156, 0x7, 0x23, 0x2, 0x2, 0x156, 0x157, 0x7, 
    0x22, 0x2, 0x2, 0x157, 0x158, 0x5, 0x2c, 0x17, 0x2, 0x158, 0x15a, 0x7, 
    0x7, 0x2, 0x2, 0x159, 0x15b, 0x5, 0xe, 0x8, 0x2, 0x15a, 0x159, 0x3, 
    0x2, 0x2, 0x2, 0x15b, 0x15c, 0x3, 0x2, 0x2, 0x2, 0x15c, 0x15a, 0x3, 
    0x2, 0x2, 0x2, 0x15c, 0x15d, 0x3, 0x2, 0x2, 0x2, 0x15d, 0x15e, 0x3, 
    0x2, 0x2, 0x2, 0x15e, 0x15f, 0x7, 0x8, 0x2, 0x2, 0x15f, 0x31, 0x3, 0x2, 
    0x2, 0x2, 0x160, 0x161, 0x7, 0x23, 0x2, 0x2, 0x161, 0x163, 0x7, 0x7, 
    0x2, 0x2, 0x162, 0x164, 0x5, 0xe, 0x8, 0x2, 0x163, 0x162, 0x3, 0x2, 
    0x2, 0x2, 0x164, 0x165, 0x3, 0x2, 0x2, 0x2, 0x165, 0x163, 0x3, 0x2, 
    0x2, 0x2, 0x165, 0x166, 0x3, 0x2, 0x2, 0x2, 0x166, 0x167, 0x3, 0x2, 
    0x2, 0x2, 0x167, 0x168, 0x7, 0x8, 0x2, 0x2, 0x168, 0x33, 0x3, 0x2, 0x2, 
    0x2, 0x169, 0x16d, 0x7, 0x24, 0x2, 0x2, 0x16a, 0x16c, 0x5, 0x36, 0x1c, 
    0x2, 0x16b, 0x16a, 0x3, 0x2, 0x2, 0x2, 0x16c, 0x16f, 0x3, 0x2, 0x2, 
    0x2, 0x16d, 0x16b, 0x3, 0x2, 0x2, 0x2, 0x16d, 0x16e, 0x3, 0x2, 0x2, 
    0x2, 0x16e, 0x170, 0x3, 0x2, 0x2, 0x2, 0x16f, 0x16d, 0x3, 0x2, 0x2, 
    0x2, 0x170, 0x174, 0x7, 0x7, 0x2, 0x2, 0x171, 0x173, 0x5, 0xe, 0x8, 
    0x2, 0x172, 0x171, 0x3, 0x2, 0x2, 0x2, 0x173, 0x176, 0x3, 0x2, 0x2, 
    0x2, 0x174, 0x172, 0x3, 0x2, 0x2, 0x2, 0x174, 0x175, 0x3, 0x2, 0x2, 
    0x2, 0x175, 0x177, 0x3, 0x2, 0x2, 0x2, 0x176, 0x174, 0x3, 0x2, 0x2, 
    0x2, 0x177, 0x178, 0x7, 0x8, 0x2, 0x2, 0x178, 0x35, 0x3, 0x2, 0x2, 0x2, 
    0x179, 0x17a, 0x7, 0x4, 0x2, 0x2, 0x17a, 0x17c, 0x7, 0x28, 0x2, 0x2, 
    0x17b, 0x17d, 0x5, 0x22, 0x12, 0x2, 0x17c, 0x17b, 0x3, 0x2, 0x2, 0x2, 
    0x17c, 0x17d, 0x3, 0x2, 0x2, 0x2, 0x17d, 0x17e, 0x3, 0x2, 0x2, 0x2, 
    0x17e, 0x17f, 0x7, 0xb, 0x2, 0x2, 0x17f, 0x180, 0x5, 0xe, 0x8, 0x2, 
    0x180, 0x181, 0x7, 0x25, 0x2, 0x2, 0x181, 0x182, 0x5, 0xe, 0x8, 0x2, 
    0x182, 0x183, 0x7, 0x25, 0x2, 0x2, 0x183, 0x184, 0x5, 0xe, 0x8, 0x2, 
    0x184, 0x185, 0x7, 0x6, 0x2, 0x2, 0x185, 0x37, 0x3, 0x2, 0x2, 0x2, 0x2a, 
    0x3b, 0x43, 0x49, 0x4f, 0x58, 0x62, 0x68, 0x6d, 0x7a, 0x84, 0x86, 0x98, 
    0xb5, 0xb7, 0xbf, 0xc5, 0xcb, 0xd5, 0xdb, 0xe0, 0xe6, 0xed, 0xf3, 0xfc, 
    0x104, 0x10a, 0x111, 0x118, 0x11b, 0x124, 0x128, 0x130, 0x136, 0x144, 
    0x151, 0x15c, 0x165, 0x16d, 0x174, 0x17c, 
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
