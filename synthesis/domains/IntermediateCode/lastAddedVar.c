#include "../../../globals.h"

char *lastAddedVar(char *scope) {
    int position;
    if (strcmp(scope, "GLOBAL") == 0) {
        position = intermediateCode->globalScope->totalVariables - 1;
    } else {
        position = findScopeByName(scope)->totalVariables - 1;
        position += intermediateCode->globalScope->totalVariables;
    }
    return intToVarName(position);
}
