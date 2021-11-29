#include "../../globals.h"

void handleINT(SyntaxTree *node) {
    if (node->top->isFunction) { // fun
        char *functionName = node->top->label;
        SyntaxTree *params = node->mid;
        SyntaxTree *body = node->bot;

        // skip function if accessed by regular instruction flow
        Quadruple *jumpEndFunction;
        if (strcmp("main", functionName) != 0) {
            jumpEndFunction = newQuadruple("JUMP", "endFunction", "-", "-");
            insertQuadruple(jumpEndFunction);
        }
        //

        insertNewScope(functionName);
        newAlias(intermediateCode->lastLine, functionName);
        
        if (strcmp("main", functionName) != 0) {
            SyntaxTree *aux = params;
            int totalParams = 0;
            
            for (aux = params; aux != NULL; aux = aux->sibling) totalParams++;

            char **paramsVars = (char**) malloc(totalParams * sizeof(char*));
            aux = params;
            int i;
            for (i = 0; i < totalParams; i++) {
                paramsVars[i] = newVariable(functionName, aux->top->label);
                aux = aux->sibling;
            }
            for (i = totalParams - 1; i >= 0; i--) {
                insertNewQuadruple("POP", paramsVars[i], "-", "-");
            }
        }

        if (strcmp("main", functionName) != 0) {
            char *newVar = newVariable(functionName, "");
            insertNewQuadruple("POP", newVar, "-", "-");
            readTreeDiscardReturn(body); // corpo da funcao
            insertNewQuadruple("JUMP", newVar, "-", "-");
            dropLastVariable(functionName);
            
        } else {
            readTreeDiscardReturn(body);
        }

        ScopeData *functionScope = findScopeByName(functionName);
        intermediateCode->freeMemoryAt -= functionScope->memoryUsage;
        functionScope->memoryUsage = 0;

        //
        if (strcmp("main", functionName) != 0) {
            Alias *endFunctionAlias = newAlias(intermediateCode->lastLine, "");
            jumpEndFunction->first = endFunctionAlias->aliasName;
        }
        //
    } else {
        if (!node->top->top) { // var
            newVariable(node->top->scope, node->top->label);
        } else { // var[]
            int size = strToInt(node->top->top->label);

            char *var = newVariable(node->top->scope, node->top->label);
            insertNewQuadruple("WRITE", var, intToStr(intermediateCode->freeMemoryAt), "-");

            intermediateCode->freeMemoryAt += size;
            findScopeByName(node->top->scope)->memoryUsage += size;
        }
    }
}