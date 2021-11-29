#include "../../../globals.h"

void readTreeDiscardReturn(SyntaxTree *node) {
    if (node) {
        SyntaxTree *currentNode = node;
        char *temp = readSyntaxTree(currentNode);
        while (strlen(temp) > 0) {
            dropLastVariable(currentNode->scope);
            currentNode = currentNode->sibling;
            temp = readSyntaxTree(currentNode);
        }
    }
}