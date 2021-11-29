#include "../../../globals.h"

Alias *findFunctionAlias(char *functionName) {
    int i;
    for (i = 0; i < intermediateCode->totalAliases; i++) {
        Alias *current = intermediateCode->aliases[i];
        if (strcmp(current->functionName, functionName) == 0) return current;
    }
    return NULL;
}
