#ifndef SYNTAX_TREE_H
#define SYNTAX_TREE_H

#include "../globals.h"

typedef struct SyntaxTree {
    int tkn;
    char *label;
    char *scope;
    int isFunction;
    int isVoid;

    struct SyntaxTree* sibling;
    struct SyntaxTree* top;
    struct SyntaxTree* mid;
    struct SyntaxTree* bot;
} SyntaxTree;

#endif
