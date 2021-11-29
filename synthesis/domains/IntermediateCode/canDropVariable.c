#include "../../../globals.h"

int canDropVariable(SyntaxTree *node) {
    return
        (node->tkn == ID && !!node->top && !node->isFunction) ||
        (node->tkn == ID && node->isFunction && !node->isVoid) ||
        (node->tkn != ID && node->tkn != NUM);
}
