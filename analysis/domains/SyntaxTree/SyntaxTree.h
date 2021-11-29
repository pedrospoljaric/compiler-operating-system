#ifndef DOMAIN_SYNTAX_TREE_H
#define DOMAIN_SYNTAX_TREE_H

#include "../../../globals.h"

#define YYSTYPE SyntaxTree*

#define INDENT indentno += 1
#define UNINDENT indentno -= 1

#define ROOT 0
#define TOP 1
#define MID 2
#define BOT 3
#define SIBLING 4

void printSpaces(FILE *ptree, int nodeType);
void printTree2(SyntaxTree* r, FILE *ptree, int nodeType);
void printTree(SyntaxTree* r, char *fileName);
SyntaxTree* newNode(int tkn, char* label, char *scope, int function, int isVoid);

#endif
