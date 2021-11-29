#ifndef ANALYSIS_H
#define ANALYSIS_H

#include "domains/domains.h"
#include "parser.tab.h"

Symbol *symbolTable;
SyntaxTree *root;

extern FILE *yyin;
extern char* yytext;
int yylex();
int yyparse();

int line_count;
char sErrorId[100];
int sErrorLine;
char *scope;

#endif
