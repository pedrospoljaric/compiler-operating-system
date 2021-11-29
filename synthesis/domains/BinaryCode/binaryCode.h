#ifndef DOMAIN_BINARYCODE_H
#define DOMAIN_BINARYCODE_H

#include "../../../globals.h"

BinaryCode *newBinaryCode();
void insertBinaryInstruction(Instruction *instruction);
void insertNewBinaryInstruction(char *instructionCode);
void outputBinaryCode(char *fileName);

#endif