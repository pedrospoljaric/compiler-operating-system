#include "../../globals.h"

void handleRETURN(SyntaxTree *node) {
    char *tempReturnValue = readSyntaxTree(node->top);
    char *returnValue = tempReturnValue;
    if (node->top->tkn == NUM) {
        returnValue = newVariable(node->scope, "");
        insertNewQuadruple("WRITE", returnValue, tempReturnValue, "-");
        dropLastVariable(node->scope);
    }

    insertNewQuadruple("PUSH", returnValue, "-", "-");
    if (node->top->tkn != NUM) dropLastVariable(node->scope);
}