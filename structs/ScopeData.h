#ifndef SCOPEDATA_H
#define SCOPEDATA_H

#include "../globals.h"

typedef struct {
    char *scopeName;
    char **scopeVariables;

    int totalVariables;

    int memoryUsage;
} ScopeData;

#endif
