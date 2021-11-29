#ifndef DOMAIN_INTERMEDIATE_CODE_H
#define DOMAIN_INTERMEDIATE_CODE_H

#include "../../../globals.h"

IntermediateCode *newIntermediateCode();
void insertNewScope(char *scope);
ScopeData *findScopeByName(char *scopeName);
void insertQuadruple(Quadruple *quadruple);
char *findVar(char *varName, char *scope);
char *lastAddedVar(char *scope);
void printIntermediateCodeQuadruples();
void pushScopeVariables(char *scope);
void popScopeVariables(char *scope);
Alias *findFunctionAlias(char *functionName);
Alias *findAliasByName(char *aliasName);
void outputIntermediateCode(char *fileName);
void incrementAliasesAfter(int lineNumber);
void insertNewQuadruple(char *command, char *first, char *second, char *third);
int canDropVariable(SyntaxTree *node);
void readTreeDiscardReturn(SyntaxTree *node);

#endif