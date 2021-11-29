#include "../../../globals.h"

IntermediateCode *newIntermediateCode() {
    IntermediateCode *intermediateCode = (IntermediateCode*) malloc(sizeof(IntermediateCode));

    intermediateCode->firstQuad = NULL;
    intermediateCode->lastQuad = NULL;
    intermediateCode->lastLine = 0;

    intermediateCode->scopes = (ScopeData**) malloc(sizeof(ScopeData*));
    intermediateCode->totalScopes = 0;

    intermediateCode->globalScope = newScopeData("GLOBAL");

    intermediateCode->aliases = (Alias**) malloc(sizeof(Alias*));
    intermediateCode->totalAliases = 0;

    intermediateCode->freeMemoryAt = 0;

    return intermediateCode;
}
