#include "../../globals.h"

void initializeVariables() {
    scope = (char*) malloc(100*sizeof(char));
    symbolTable = (Symbol*) malloc(HASHSIZE*sizeof(Symbol));
    strcpy(scope, "GLOBAL");
    sErrorLine = -1;
    line_count = 1;
}
