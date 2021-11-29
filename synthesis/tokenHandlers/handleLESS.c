#include "../../globals.h"

char *handleLESS(SyntaxTree *node) {
    char *tempLeft = readSyntaxTree(node->top);
    char *tempRight = readSyntaxTree(node->mid);
    
    char *left = tempLeft;
    char *right = tempRight;
    if (node->top->tkn == NUM) {
        left = newVariable(node->scope, "");
        insertNewQuadruple("WRITE", left, tempLeft, "-");
    }
    if (node->mid->tkn == NUM) {
        right = newVariable(node->scope, "");
        insertNewQuadruple("WRITE", right, tempRight, "-");
    }

    if (node->top->tkn == NUM) dropLastVariable(node->scope);
    if (node->mid->tkn == NUM) dropLastVariable(node->scope);

    if (canDropVariable(node->mid)) dropLastVariable(node->scope);
    if (canDropVariable(node->top)) dropLastVariable(node->scope);

    char *result = newVariable(node->top->scope, "");

    insertNewQuadruple("LESS", result, left, right);
    return result;
}