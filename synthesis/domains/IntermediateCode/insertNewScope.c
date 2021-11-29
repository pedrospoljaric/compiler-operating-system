#include "../../../globals.h"

void insertNewScope(char *scope) {
    ScopeData *scopeData = newScopeData(scope);
    intermediateCode->scopes[intermediateCode->totalScopes] = scopeData;
    intermediateCode->scopes = realloc(intermediateCode->scopes, (++intermediateCode->totalScopes + 1) * sizeof(ScopeData*));
}
