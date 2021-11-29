#include "../../../globals.h"

ScopeData *newScopeData(char *scopeName) {
    ScopeData *scopeData = (ScopeData*) malloc(sizeof(ScopeData));

    scopeData->scopeName = (char*) malloc(100 * sizeof(char));
    strcpy(scopeData->scopeName, scopeName);
    scopeData->scopeVariables = (char**) malloc(sizeof(char*));
    scopeData->scopeVariables[0] = (char*) malloc(100 * sizeof(char));

    scopeData->totalVariables = 0;
    scopeData->memoryUsage = 0;

    return scopeData;
}
