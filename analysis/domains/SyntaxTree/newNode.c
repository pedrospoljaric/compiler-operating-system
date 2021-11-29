#include "../../../globals.h"

SyntaxTree* newNode(int tkn, char *label, char *scope, int function, int isVoid) {
    SyntaxTree *aux = (SyntaxTree*) malloc(sizeof(SyntaxTree));
    aux->tkn = tkn;
    aux->label = (char*) malloc((strlen(label) + 1) * sizeof(char));
    strcpy(aux->label, label);
    aux->scope = (char*) malloc((strlen(scope) + 1) * sizeof(char));
    strcpy(aux->scope, scope);
    aux->isFunction = function;
    aux->isVoid = isVoid;

    aux->sibling = NULL;
    aux->top = NULL;
    aux->mid = NULL;
    aux->bot = NULL;
    return aux;
}
