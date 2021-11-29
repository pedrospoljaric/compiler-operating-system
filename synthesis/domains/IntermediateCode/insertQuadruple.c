#include "../../../globals.h"

void insertQuadruple(Quadruple *quadruple) {
    // printf("%d: %s %s %s %s\n", intermediateCode->lastLine, quadruple->command, quadruple->first, quadruple->second, quadruple->third);
    quadruple->next = NULL;
    intermediateCode->lastLine++;

    if (intermediateCode->lastQuad) {
        intermediateCode->lastQuad->next = quadruple;
    } else {
        intermediateCode->firstQuad = quadruple;
    }
    intermediateCode->lastQuad = quadruple;
}