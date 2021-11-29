#include "../../../globals.h"

Alias *newAlias(int lineNumber, char *functionName) {
    Alias *aux = (Alias*) malloc(sizeof(Alias));
    aux->functionName = functionName;
    aux->lineNumber = lineNumber;
    intermediateCode->aliases[intermediateCode->totalAliases++] = aux;
    intermediateCode->aliases = realloc(intermediateCode->aliases, (intermediateCode->totalAliases + 1) * sizeof(Alias));
    aux->aliasName = intToAliasName(intermediateCode->totalAliases-1);
    // insertQuadruple(newQuadruple("ALIAS", aux->aliasName, functionName, intToStr(lineNumber)));

    return aux;
}