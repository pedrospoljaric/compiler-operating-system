#include "../../../globals.h"

void printScope(ScopeData *scopeData) {
    printf("  %s\n    - %d variables: ", scopeData->scopeName, scopeData->totalVariables);
    int j;
    for (j = 0; j < scopeData->totalVariables; j++) {
        printf("%s ", scopeData->scopeVariables[j]);
    }
    printf("\n");
}
