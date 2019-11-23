%{

/* Declarations section */
#include <stdio.h>
#include "output.hpp"
#include "source.tab.hpp"
%}

%option yylineno
%option noyywrap
digit   		([0-9])
digitExZiro     ([1-9])
letter  		([a-zA-Z])
whitespace		([\t\n\r ]|\n)
reltionalOp     (==|!=|<|>|<=|>=)
binarOp         ([\+\-\*\/])
number ({digitExZiro}{digit}*)

%%
void                        return VOID;
int                         return INT;
byte                        return BYTE;
b 							return B;
bool                        return BOOL;
enum                        return ENUM;
and                         return AND;
or                          return OR;
not                         return NOT;
true                        return TRUE;
false                       return FALSE;
return                      return RETURN;
if                          return IF;
else                        return ELSE;
while                       return WHILE;
break                       return BREAK;
continue                    return CONTINUE;
;                           return SC;
,                           return COMMA;
\(                          return LPAREN;
\)                          return RPAREN;
\{                          return LBRACE;
\}                          return RBRACE;
=                           return ASSIGN;
{reltionalOp}               return RELOP;
{binarOp}                   return BINOP;
\/\/(.)*                    return COMMENT;
{letter}({letter}|{digit})* return ID;
{number}|0    				return NUM;
"([^\n\r\"\\]|\\[rnt"\\])+" return STRING;
{whitespace}				;
//[^\r\n]*[\r|\n|\r\n]?     ;
.							errorLex(yylineno);
%%
