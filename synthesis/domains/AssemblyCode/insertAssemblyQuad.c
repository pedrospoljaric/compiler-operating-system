#include "../../../globals.h"

void insertAssemblyQuad(Quadruple *quadruple) {
    quadruple->next = NULL;

    if (assemblyCode->lastQuad) {
        assemblyCode->lastQuad->next = quadruple;
    } else {
        assemblyCode->firstQuad = quadruple;
    }
    assemblyCode->lastQuad = quadruple;
}