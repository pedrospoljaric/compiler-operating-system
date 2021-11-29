%option noinput nounput
%{

#include "../globals.h"

%}

DIGIT [0-9]
LETTER [a-zA-Z]

%%

[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/] // multi line comment
"//".*                              // single line comment
"if"                return IF;
"else"              return ELSE;
"int"               return INT;
"void"              return VOID;
"while"             return WHILE;
"return"            return RETURN;
"+"			        return SUM;
"-"			        return SUB;
"*"			        return MULT;
"/"			        return DIV;
"<"                 return LESS;
"<="                return LESS_EQ;
">"                 return GREAT;
">="                return GREAT_EQ;
"=="                return EQ_EQ;
"!="                return NOT_EQ;
"="                 return EQ;
";"                 return SEMICOL;
","                 return COMMA;
"("                 return L_PAR;
")"                 return R_PAR;
"["                 return L_BRACK;
"]"                 return R_BRACK;
"{"                 return L_BRACE;
"}"                 return R_BRACE;
"\n"                line_count++;
" "
"\t"
"\r\n"              line_count++;
"<<EOF>>"
{LETTER}+           return ID;
{DIGIT}+            return NUM;
[^\+\-\/<=>!;,\(\)\[\]\{\}\ \t\r\n]+ return lexicalError();

%%
