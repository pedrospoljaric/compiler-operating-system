#ifndef SYMBOL_H
#define SYMBOL_H

#include "../globals.h"

typedef struct Line {
    int number;
    struct Line* next;
} Line;

typedef struct Symbol {
    char name[100];
    char scope[100];
    Line* firstLine;
    Line* lastLine;
    int isFunction;
    int type;
} Symbol;

#endif
