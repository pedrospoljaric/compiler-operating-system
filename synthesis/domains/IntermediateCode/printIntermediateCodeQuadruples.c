#include "../../../globals.h"
void printIntermediateCodeQuadruples() {
    int i = 0;
    Quadruple *aux = intermediateCode->firstQuad;
    while (aux != NULL) {
        printf("%d: %s %s %s %s\n", i++, aux->command, aux->first, aux->second, aux->third);
        aux = aux->next;
    }
}
