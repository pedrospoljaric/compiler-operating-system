#ifndef DOMAIN_ALIAS_H
#define DOMAIN_ALIAS_H

#include "../../../globals.h"

Alias *newAlias(int lineNumber, char *functionName);
int aliasToLineNumber(char *aliasName);

#endif