#include "../../../globals.h"

void outputIntermediateCode(char *fileName) {
    FILE *prog;
    prog = fopen(fileName, "w");

    Quadruple *aux = intermediateCode->firstQuad;
    while (aux != NULL) {
        fprintf(prog, "%s %s %s %s\n", aux->command, aux->first, aux->second, aux->third);
        aux = aux->next;
    }
}
