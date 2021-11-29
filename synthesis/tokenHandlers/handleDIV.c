#include "../../globals.h"

char *handleDIV(SyntaxTree *node) {
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

    insertNewQuadruple(getTknName(node->tkn), result, left, right);
    return result;
}