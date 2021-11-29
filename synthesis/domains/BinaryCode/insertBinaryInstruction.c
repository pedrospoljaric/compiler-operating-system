#include "../../../globals.h"

void insertBinaryInstruction(Instruction *instruction) {
    instruction->next = NULL;

    if (binaryCode->lastInstruction) {
        binaryCode->lastInstruction->next = instruction;
    } else {
        binaryCode->firstInstruction = instruction;
    }
    binaryCode->lastInstruction = instruction;
}