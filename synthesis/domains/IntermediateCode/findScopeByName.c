#include "../../../globals.h"

ScopeData *findScopeByName(char *scopeName) {
    if (strcmp(scopeName, "GLOBAL") == 0) return intermediateCode->globalScope;
    int i = 0;
    while (strcmp(intermediateCode->scopes[i]->scopeName, scopeName) != 0) i++;
    return intermediateCode->scopes[i];
}
