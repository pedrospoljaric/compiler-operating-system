#include "../../globals.h"

void handleWHILE(SyntaxTree *node) {
    Alias *whileAlias = newAlias(intermediateCode->lastLine, "");

    char *tempCondition = readSyntaxTree(node->top);
    char *condition = tempCondition;
    if (node->top->tkn == NUM) {
        condition = newVariable(node->scope, "");
        insertNewQuadruple("WRITE", condition, tempCondition, "-");
        dropLastVariable(node->scope);
    }

    char *aliasVar = newVariable(node->scope, "");
    Quadruple *writeWhileCommand = newQuadruple("WRITE", aliasVar, "whileline", "-");
    insertQuadruple(writeWhileCommand);
    insertNewQuadruple("JUMPIF", condition, aliasVar, "-");
    if (canDropVariable(node->top)) dropLastVariable(node->scope);

    Quadruple *gotoAfterWhile = newQuadruple("JUMP", "afterWhile", "-", "-");
    insertQuadruple(gotoAfterWhile);
    Alias *whileBodyAlias = newAlias(intermediateCode->lastLine, "");
    writeWhileCommand->second = whileBodyAlias->aliasName;
    dropLastVariable(node->scope); // drop aliasVar

    readTreeDiscardReturn(node->mid);
    Quadruple *endWhile = newQuadruple("JUMP", whileAlias->aliasName, "-", "-");
    insertQuadruple(endWhile);
    Alias *aferWhileAlias = newAlias(intermediateCode->lastLine, "");
    gotoAfterWhile->first = aferWhileAlias->aliasName;
}