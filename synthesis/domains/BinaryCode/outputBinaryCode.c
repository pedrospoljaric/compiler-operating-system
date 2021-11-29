#include "../../../globals.h"

void outputBinaryCode(char *fileName) {
    FILE *prog;
    prog = fopen(fileName, "w");

    Instruction *aux = binaryCode->firstInstruction;
    while (aux != NULL) {
        fprintf(prog, "%s\n", aux->instructionCode);
        aux = aux->next;
    }
}
