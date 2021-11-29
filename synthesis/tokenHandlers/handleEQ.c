#include "../../globals.h"

void handleEQ(SyntaxTree *node) {
    char *tempRight = readSyntaxTree(node->mid);
    if (node->top->top) { // vet[i] = tempRight
        char *index = readSyntaxTree(node->top->top);
        if (canDropVariable(node->top->top)) dropLastVariable(node->scope);
        
        char *memoryPosition = newVariable(node->scope, "");
        insertNewQuadruple("SUM", memoryPosition, findVar(node->top->label, node->scope), index);
        
        char *right = tempRight;
        if (node->mid->tkn == NUM) {
            right = newVariable(node->scope, "");
            insertNewQuadruple("WRITE", right, tempRight, "-");
            dropLastVariable(node->scope);
        }
        
        dropLastVariable(node->scope);
        if (canDropVariable(node->mid)) dropLastVariable(node->scope);
        insertNewQuadruple("STORE", right, memoryPosition, "-");
    } else {
        char *left = readSyntaxTree(node->top);
        
        if (canDropVariable(node->mid)) dropLastVariable(node->scope);
        insertNewQuadruple("EQ", left, tempRight, "-");
    }
}