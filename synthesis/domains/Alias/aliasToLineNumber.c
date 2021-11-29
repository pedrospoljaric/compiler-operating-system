#include "../../../globals.h"

int aliasToLineNumber(char *aliasName) {
    Alias *alias = findAliasByName(aliasName);
    return alias->lineNumber;
}