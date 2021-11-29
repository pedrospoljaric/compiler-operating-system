#include "../../globals.h"

char *handleSUM(SyntaxTree *node) {
    char *left = readSyntaxTree(node->top);
    char *right = readSyntaxTree(node->mid);

    if (canDropVariable(node->mid)) dropLastVariable(node->scope);
    if (canDropVariable(node->top)) dropLastVariable(node->scope);

    char *result = newVariable(node->top->scope, "");

    insertNewQuadruple(getTknName(node->tkn), result, left, right);
    return result;
}