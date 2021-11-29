#ifndef DOMAIN_SCOPEDATA_H
#define DOMAIN_SCOPEDATA_H

#include "../../../globals.h"

ScopeData *newScopeData(char *scopeName);
char *newVariable(char *scope, char *name);
int findVariableIndex(char *scope, char *name);
void dropLastVariable(char *scope);
void printScope(ScopeData *scopeData);

#endif
