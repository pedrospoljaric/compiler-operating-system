#ifndef BINARYCODE_H
#define BINARYCODE_H

#include "../globals.h"

typedef struct Instruction {
    char *instructionCode;
    struct Instruction *next;
} Instruction;

typedef struct {
    Instruction *firstInstruction;
    Instruction *lastInstruction;
} BinaryCode;

#endif