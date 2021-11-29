#include "../../globals.h"

char *handleSUB(SyntaxTree *node) {
    char *tempLeft = readSyntaxTree(node->top);
    char *right = readSyntaxTree(node->mid);

    char *left = tempLeft;
    if (node->top->tkn == NUM && node->mid->tkn != NUM) {
        left = newVariable(node->scope, "");
        insertNewQuadruple("WRITE", left, tempLeft, "-");
        dropLastVariable(node->scope);
    }

    if (canDropVariable(node->mid)) dropLastVariable(node->scope);
    if (canDropVariable(node->top)) dropLastVariable(node->scope);

    char *result = newVariable(node->scope, "");

    // result = left - right
    // SUB result left right
    insertNewQuadruple("SUB", result, left, right);
    return result;
}