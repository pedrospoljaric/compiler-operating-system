#include "../../../globals.h"

void popScopeVariables(char *scope) {
    ScopeData *scopeData = findScopeByName(scope);
    int i;
    for (i = scopeData->totalVariables - 1; i >= 0; i--) {
        insertNewQuadruple("POP", findVar(scopeData->scopeVariables[i], scopeData->scopeName), "-", "-");
    }
}
