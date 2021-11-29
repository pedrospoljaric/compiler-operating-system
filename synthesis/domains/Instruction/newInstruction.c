#include "../../../globals.h"

Instruction *newInstruction(char *instructionCode) {
    Instruction *instruction = (Instruction*) malloc(sizeof(Instruction));

    instruction->instructionCode = (char*) malloc(33 * sizeof(char));
    strcpy(instruction->instructionCode, instructionCode);
    return instruction;
}