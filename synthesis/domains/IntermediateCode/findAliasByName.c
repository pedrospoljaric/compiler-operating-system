#include "../../../globals.h"

Alias *findAliasByName(char *aliasName) {
    int i;
    for (i = 0; i < intermediateCode->totalAliases; i++) {
        Alias *current = intermediateCode->aliases[i];
        if (strcmp(current->aliasName, aliasName) == 0) return current;
    }
    return NULL;
}
