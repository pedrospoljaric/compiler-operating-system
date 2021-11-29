#include "../../../globals.h"

char *findVar(char *varName, char *scope) {
    int position;
    if (strcmp(scope, "GLOBAL") == 0) {
        position = findVariableIndex("GLOBAL", varName);
    } else {
        position = findVariableIndex(scope, varName);
        if (position == -1) return findVar(varName, "GLOBAL");
        position += intermediateCode->globalScope->totalVariables;
    }
    return intToVarName(position);
}
