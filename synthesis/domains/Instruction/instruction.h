#ifndef DOMAIN_INSTRUCTION_H
#define DOMAIN_INSTRUCTION_H

#include "../../../globals.h"

Instruction *newInstruction(char *instructionCode);
char *decimalToExtendedBinary(int decimal, int length);
char *registerNameToBinary(char *registerName, int mode);
char *commandToOpCode(char *command);
char *decimalStringToExtendedBinary(char *decimalStr, int length);

#endif
