#include "../../../globals.h"

void pushScopeVariables(char *scope) {
    ScopeData *scopeData = findScopeByName(scope);
    int i;
    for (i = 0; i < scopeData->totalVariables; i++) {
        insertNewQuadruple("PUSH", findVar(scopeData->scopeVariables[i], scopeData->scopeName), "-", "-");
    }
}
