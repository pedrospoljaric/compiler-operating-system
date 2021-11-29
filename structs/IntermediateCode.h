#ifndef INTERMEDIATE_H
#define INTERMEDIATE_H

#include "../globals.h"

// $ variable
// # alias

typedef struct {
    int lineNumber;
    char *functionName;
    char *aliasName;
} Alias;

typedef struct {
    Quadruple *firstQuad;
    Quadruple *lastQuad;
    int lastLine;

    ScopeData **scopes;
    int totalScopes;

    ScopeData *globalScope;

    Alias **aliases;
    int totalAliases;

    int freeMemoryAt;
} IntermediateCode;

#endif