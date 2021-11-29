#include "../../globals.h"

void handleIF(SyntaxTree *node) {
    char *tempCondition = readSyntaxTree(node->top);
    
    char *condition = tempCondition;
    if (node->top->tkn == NUM) {
        condition = newVariable(node->scope, "");
        insertNewQuadruple("WRITE", condition, tempCondition, "-");
        dropLastVariable(node->scope);
    }

    char *aliasVar = newVariable(node->scope, "");
    Quadruple *writeifCommand = newQuadruple("WRITE", aliasVar, "ifline", "-");
    insertQuadruple(writeifCommand);
    insertNewQuadruple("JUMPIF", condition, aliasVar, "-");
    if (canDropVariable(node->top)) dropLastVariable(node->scope);

    readTreeDiscardReturn(node->bot); // <else>

    Quadruple *endElse = newQuadruple("JUMP", "endif", "-", "-");
    insertQuadruple(endElse);
    Alias *thenLineAlias = newAlias(intermediateCode->lastLine, "");
    
    readTreeDiscardReturn(node->mid); // <then>

    Alias *endLineAlias = newAlias(intermediateCode->lastLine, "");
    writeifCommand->second = thenLineAlias->aliasName;
    endElse->first = endLineAlias->aliasName;
    dropLastVariable(node->scope); // drop aliasVar
}
