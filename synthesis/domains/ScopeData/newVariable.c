#include "../../../globals.h"

char *newVariable(char *scope, char *name) {
    ScopeData *scopeData = findScopeByName(scope);
    strcpy(scopeData->scopeVariables[scopeData->totalVariables], name);
    scopeData->scopeVariables = realloc(scopeData->scopeVariables, (++scopeData->totalVariables + 1) * sizeof(char*));
    scopeData->scopeVariables[scopeData->totalVariables] = (char*) malloc(100 * sizeof(char));
    return lastAddedVar(scopeData->scopeName);
}
