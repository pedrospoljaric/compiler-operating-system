#include "../../../globals.h"

void dropLastVariable(char *scope) {
    ScopeData *scopeData = findScopeByName(scope);
    scopeData->scopeVariables = realloc(scopeData->scopeVariables, (--scopeData->totalVariables + 1) * sizeof(char*));
}
