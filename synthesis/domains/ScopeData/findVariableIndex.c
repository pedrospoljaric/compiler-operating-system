#include "../../../globals.h"

int findVariableIndex(char *scope, char *name) {
    ScopeData *scopeData = findScopeByName(scope);
    int i = 0;
    while (i < scopeData->totalVariables && strcmp(scopeData->scopeVariables[i], name) != 0) i++;
    if (i == scopeData->totalVariables) return -1;
    return i;
}
