#include "../../../globals.h"

BinaryCode *newBinaryCode() {
    BinaryCode *binaryCode = (BinaryCode*) malloc(sizeof(BinaryCode));

    binaryCode->firstInstruction = NULL;
    binaryCode->lastInstruction = NULL;

    return binaryCode;
}
