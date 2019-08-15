
// java -jar .\external\antlr-4.7.2-complete.jar -no-listener -visitor -Dlanguage=Cpp .\src\lid.g -o .\src\generated\

grammar lid;

program
    : toplevel* EOF;

toplevel
    : (namedFunction|namedConstant|namedStruct)
    ;

namedFunction
    : 'function' IDENTIFIER '(' typedParameter? (',' typedParameter)* ')' typeName '{' expression* '}'
    | 'extern' 'function' IDENTIFIER '(' typedParameter? (',' typedParameter)* ')' typeName
    ;

namedConstant
    : 'const' IDENTIFIER '=' expression
    ;

namedStruct
    : 'struct' IDENTIFIER '{' structMember+ '}'
    ;

structMember
    : IDENTIFIER typeName
    | IDENTIFIER typeName '=' expression?
    ;

expression
    : callable
    | symbol
    | lambda
    | let
    | set
    | branch
    | loop

    | unaryOperator=('+'|'-') expression
    | unaryOperator=('~'|'!') expression
    //| expression postfix=('++' | '--')

    | expression binaryOperator=('*'|'/'|'%') expression
    | expression binaryOperator=('+'|'-') expression
    | expression binaryOperator=('<='|'>='|'>'|'<') expression
    | expression binaryOperator=('=='|'!=') expression
    | expression binaryOperator='&' expression
    | expression binaryOperator='^' expression
    | expression binaryOperator='|' expression
    | expression binaryOperator='&&' expression
    | expression binaryOperator='||' expression

    //| expression ternaryOperator='?' expression ':' expression

    | nestedExpression='(' expression ')'
    ;

symbolName
    : IDENTIFIER ('.' IDENTIFIER)*
    ;

callable
    : symbolName '(' parameter? (',' parameter)* ')'
    | '(' expression ')' '(' parameter? (',' parameter)* ')'
    ;

symbol
    : symbolName | FLOAT_LITERAL | INTEGER_LITERAL | STRING_LITERAL
    ;

parameter
    : expression
    ;

lambda
    : 'function' '(' typedParameter? (',' typedParameter)* ')' typeName '{' expression* '}'
    ;

typedParameter
    : IDENTIFIER typeName
    | typeName
    ;

let
    : 'let' typedValueBinding* '{' expression* '}'
    ;

typedValueBinding
    : IDENTIFIER typeName? typedValueQualifier? '=' expression
    ;

typedValueQualifier
    : '#mutable'
    ;

typeName
    : regularTypeName
    | functionTypeName
    ;

regularTypeName
    : ':' POINTER_PREFIX? IDENTIFIER
    ;

functionTypeName
    : ':' 'function' '(' typedParameter? (',' typedParameter)* ')' typeName
    ;

set
    : symbolName '=' expression
    ;

branch
    : branchBegin branchItem* branchEnd
    ;

branchCondition
    : expression
    ;

branchBegin
    : 'if' branchCondition '{' expression+ '}'
    ;

branchItem
    : 'else' 'if' branchCondition '{' expression+ '}'
    ;

branchEnd
    : 'else' '{' expression+ '}'
    ;

loop
    : 'for' loopBindingExpression* '{' expression* '}'
    ;

loopBindingExpression
    : '(' IDENTIFIER typeName? '=' expression ';' expression ';' expression ')'
    ;

WHITESPACE
    : [ \t\u000C\r\n]+ -> skip
    ;

POINTER_PREFIX
    : '&'
    ;

IDENTIFIER
    : IdSymbol (Digit|IdSymbol)*
    ;

FLOAT_LITERAL
    : ('+'|'-')? Digit+ '.' Digit+
    ;

INTEGER_LITERAL
    : ('+'|'-')? Digit+
    ;

STRING_LITERAL
    : '"' (~('"' | '\\' | '\r' | '\n') | '\\' ('"' | '\\'))* '"'
    ;

LINE_COMMENT
    : '//' ~('\r'|'\n')* -> channel(HIDDEN)
    ;

fragment Digit
    : [0-9]
    ;

fragment Nondigit
    : [a-zA-Z]
    ;

fragment IdSymbol
    : Nondigit('_'|Nondigit)*
    ;
