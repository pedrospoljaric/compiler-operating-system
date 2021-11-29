#include "../globals.h"

int sizeBetweenBits(int start, int end) {
    return end - start + 1;
}

void readAssemblyCode(int mode) {
    Quadruple *currentQuad = assemblyCode->firstQuad;

    while (currentQuad) {
        char *command = currentQuad->command;
        char *first = currentQuad->first;
        char *second = currentQuad->second;
        char *third = currentQuad->third;

        int isRegister[4] = {0, strIsRegister(first), strIsRegister(second), strIsRegister(third)};

        if (strIsRegister(first)) first = registerNameToBinary(first, mode); // $1 -> 000001
        if (strIsRegister(second)) second = registerNameToBinary(second, mode);
        if (strIsRegister(third)) third = registerNameToBinary(third, mode);

        if (strIsAlias(first)) first = intToStr(aliasToLineNumber(first)); // #0 -> 23
        if (strIsAlias(second)) second = intToStr(aliasToLineNumber(second));
        if (strIsAlias(third)) third = intToStr(aliasToLineNumber(third));

        char *opcode = commandToOpCode(command);
        char *instruction = (char*) malloc(33 * sizeof(char));
        strcat(instruction, opcode);

        if (strStartsWith(command, "SUM")) {
            strcat(instruction, first);
            strcat(instruction, second);
            if (isRegister[3]) {
                strcat(instruction, third);
                strcat(instruction, decimalToExtendedBinary(0, sizeBetweenBits(22, 30)));
            }
            else strcat(instruction, decimalStringToExtendedBinary(third, sizeBetweenBits(16, 30)));
            if (sameString(command, "SUM0")) strcat(instruction, "0");
            else strcat(instruction, "1");
        }
        if (strStartsWith(command, "SUB")) {
            strcat(instruction, first);
            strcat(instruction, second);
            if (isRegister[3]) {
                strcat(instruction, third);
                strcat(instruction, decimalToExtendedBinary(0, sizeBetweenBits(22, 30)));
            }
            else strcat(instruction, decimalStringToExtendedBinary(third, sizeBetweenBits(16, 30)));
            if (sameString(command, "SUB0")) strcat(instruction, "0");
            else strcat(instruction, "1");
        }
        if (strStartsWith(command, "MULT")) {
            strcat(instruction, first);
            strcat(instruction, second);
            if (isRegister[3]) {
                strcat(instruction, third);
                strcat(instruction, decimalToExtendedBinary(0, sizeBetweenBits(22, 30)));
            }
            else strcat(instruction, decimalStringToExtendedBinary(third, sizeBetweenBits(16, 30)));
            if (sameString(command, "MULT0")) strcat(instruction, "0");
            else strcat(instruction, "1");
        }
        if (strStartsWith(command, "DIV")) {
            strcat(instruction, first);
            strcat(instruction, second);
            if (isRegister[3]) {
                strcat(instruction, third);
                strcat(instruction, decimalToExtendedBinary(0, sizeBetweenBits(22, 30)));
            }
            else strcat(instruction, decimalStringToExtendedBinary(third, sizeBetweenBits(16, 30)));
            if (sameString(command, "DIV0")) strcat(instruction, "0");
            else strcat(instruction, "1");
        }
        if (strStartsWith(command, "LOGIC")) {
            strcat(instruction, first);
            strcat(instruction, second);
            if (sameString(command, "LOGIC0")) strcat(instruction, decimalToExtendedBinary(0, sizeBetweenBits(16, 28)));
            else {
                strcat(instruction, third);
                strcat(instruction, decimalToExtendedBinary(0, sizeBetweenBits(22, 28)));
            }
            if (sameString(command, "LOGIC0")) strcat(instruction, decimalToExtendedBinary(0, 3));
            if (sameString(command, "LOGIC1")) strcat(instruction, decimalToExtendedBinary(1, 3));
            if (sameString(command, "LOGIC2")) strcat(instruction, decimalToExtendedBinary(2, 3));
            if (sameString(command, "LOGIC3")) strcat(instruction, decimalToExtendedBinary(3, 3));
            if (sameString(command, "LOGIC4")) strcat(instruction, decimalToExtendedBinary(4, 3));
            if (sameString(command, "LOGIC5")) strcat(instruction, decimalToExtendedBinary(5, 3));
            if (sameString(command, "LOGIC6")) strcat(instruction, decimalToExtendedBinary(6, 3));
            if (sameString(command, "LOGIC7")) strcat(instruction, decimalToExtendedBinary(7, 3));
        }
        if (strStartsWith(command, "JUMP")) {
            if (sameString(command, "JUMP0") || sameString(command, "JUMP1")) {
                strcat(instruction, decimalStringToExtendedBinary(first, sizeBetweenBits(4, 29)));
                if (sameString(command, "JUMP0")) strcat(instruction, decimalToExtendedBinary(0, 2));
                if (sameString(command, "JUMP1")) strcat(instruction, decimalToExtendedBinary(1, 2));
            }
            if (sameString(command, "JUMP2")) {
                strcat(instruction, first);
                strcat(instruction, decimalToExtendedBinary(0, sizeBetweenBits(10, 29)));
                strcat(instruction, decimalToExtendedBinary(2, 2));
            }
            if (sameString(command, "JUMP3")) {
                strcat(instruction, first);
                strcat(instruction, second);
                strcat(instruction, decimalToExtendedBinary(0, sizeBetweenBits(16, 29)));
                strcat(instruction, decimalToExtendedBinary(3, 2));
            }
        }
        if (strStartsWith(command, "STACK")) {
            strcat(instruction, first);
            strcat(instruction, decimalToExtendedBinary(0, sizeBetweenBits(10, 30)));
            if (sameString(command, "STACK0")) strcat(instruction, "0");
            if (sameString(command, "STACK1")) strcat(instruction, "1");
        }
        if (strStartsWith(command, "WRITE")) {
            strcat(instruction, first);
            strcat(instruction, decimalStringToExtendedBinary(second, sizeBetweenBits(10, 31)));
        }
        if (strStartsWith(command, "COPY")) {
            strcat(instruction, first);
            strcat(instruction, second);
            strcat(instruction, decimalToExtendedBinary(0, sizeBetweenBits(16, 31)));
        }
        if (strStartsWith(command, "LOAD")) {
            strcat(instruction, first);
            strcat(instruction, second);
            strcat(instruction, decimalToExtendedBinary(0, sizeBetweenBits(16, 31)));
        }
        if (strStartsWith(command, "STORE")) {
            strcat(instruction, first);
            strcat(instruction, second);
            strcat(instruction, decimalToExtendedBinary(0, sizeBetweenBits(16, 31)));
        }
        if (strStartsWith(command, "INPUT")) {
            strcat(instruction, first);
            strcat(instruction, decimalStringToExtendedBinary(second, sizeBetweenBits(10, 31)));
        }

        insertNewBinaryInstruction(instruction);

        currentQuad = currentQuad->next;
    }
}

void generateBinaryCode(int mode) {
    readAssemblyCode(mode);
}