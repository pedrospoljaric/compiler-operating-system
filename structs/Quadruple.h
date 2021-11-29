#ifndef QUADRUPLE_H
#define QUADRUPLE_H

#include "../globals.h"

typedef struct Quadruple {
    char *command;
    char *first;
    char *second;
    char *third;
    struct Quadruple *next;
} Quadruple;

#endif
