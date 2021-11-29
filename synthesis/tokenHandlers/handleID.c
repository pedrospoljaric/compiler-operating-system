#include "../../globals.h"

char *handleID(SyntaxTree *node) {
    if (node->isFunction) {
        if (strcmp("input", node->label) == 0) {
            char *var = newVariable(node->scope, "");
            insertNewQuadruple("INPUT", var, "-", "-");
            return var;
        } else if (strcmp("output", node->label) == 0) {
            char *param;
            if (node->top->tkn == NUM) {
                param = newVariable(node->scope, "");
                insertNewQuadruple("WRITE", param, readSyntaxTree(node->top), "-");
                dropLastVariable(node->scope);
            } else {
                param = readSyntaxTree(node->top);
            }
            insertNewQuadruple("OUTPUT", param, "-", "-");
            if (canDropVariable(node->top)) dropLastVariable(node->scope);
        } else { // a = func() ou func()
            pushScopeVariables(node->scope);

            char *aliasVar = newVariable(node->scope, "");
            Quadruple *writeCallLine = newQuadruple("WRITE", aliasVar, "calline", "-");
            insertQuadruple(writeCallLine);
            insertNewQuadruple("PUSH", aliasVar, "-", "-");
            
            int droppableVars = 0;
            SyntaxTree *aux = node->top;
            while (aux != NULL) {
                char *tempParam = readSyntaxTree(aux);
                char *param = tempParam;
                if (aux->tkn == NUM) {
                    param = newVariable(node->scope, "");
                    insertNewQuadruple("WRITE", param, tempParam, "-");
                    dropLastVariable(node->scope);
                }
                insertNewQuadruple("PUSH", param, "-", "-");
                if (canDropVariable(aux)) droppableVars++;
                aux = aux->sibling;
            }
            int i;
            for (i = 0; i < droppableVars; i++) dropLastVariable(node->scope);

            Alias *functionAlias = findFunctionAlias(node->label);
            insertNewQuadruple("JUMP", functionAlias->aliasName, "-", "-");
            Alias *currentLineAlias = newAlias(intermediateCode->lastLine, "");
            writeCallLine->second = currentLineAlias->aliasName;
            dropLastVariable(node->scope); // drop aliasVar

            char *var;
            if (!node->isVoid) {
                var = newVariable(node->scope, "");
                // insertNewQuadruple("POP", var, "-", "-");
            }
            popScopeVariables(node->scope);
            if (!node->isVoid) {
                return var;
            }
        }
    } else {
        if (!node->top) { // var
            return findVar(node->label, node->scope);
        } else { // var[10]
            char *index = readSyntaxTree(node->top);
            if (canDropVariable(node->top)) dropLastVariable(node->scope);
            char *memoryPosition = newVariable(node->scope, "");
            insertNewQuadruple("SUM", memoryPosition, findVar(node->label, node->scope), index);
            dropLastVariable(node->scope);
            
            char *var = newVariable(node->scope, "");
            insertNewQuadruple("LOAD", var, memoryPosition, "-");
            return var;
        }
    }
    return "";
}