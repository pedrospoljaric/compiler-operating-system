#include "../globals.h"

void readIntermediateCode() {
    Quadruple *currentQuad = intermediateCode->firstQuad;
    int currentIntermediateCodeLine = 1;

    while (currentQuad) {
        char *command = currentQuad->command;
        char *first = currentQuad->first;
        char *second = currentQuad->second;
        char *third = currentQuad->third;

        int isRegister[4] = {0, strIsRegister(first), strIsRegister(second), strIsRegister(third)};
        // if (strIsAlias(first)) first = intToStr(aliasToLineNumber(first)); // #0 -> 23
        // if (strIsAlias(second)) second = intToStr(aliasToLineNumber(second));
        // if (strIsAlias(third)) third = intToStr(aliasToLineNumber(third));

        if (sameString(command, "SUM")) {
            if (isRegister[2] && isRegister[3]) insertNewAssemblyQuad("SUM0", first, second, third);
            else if (isRegister[2] && !isRegister[3]) insertNewAssemblyQuad("SUM1", first, second, third);
            else if (!isRegister[2] && isRegister[3]) insertNewAssemblyQuad("SUM1", first, third, second);
            else if (!isRegister[2] && !isRegister[3]) {
                insertNewAssemblyQuad("WRITE", first, second, "-");
                insertNewAssemblyQuad("SUM1", first, first, third);
                incrementAliasesAfter(currentIntermediateCodeLine);
            }
        }
        else if (sameString(command, "SUB")) {
            if (!isRegister[2] && isRegister[3]) insertNewAssemblyQuad("ERROR", "ERROR", "ERROR", "ERROR");
            else {
                if (isRegister[2] && isRegister[3]) insertNewAssemblyQuad("SUB0", first, second, third);
                else if (isRegister[2] && !isRegister[3]) insertNewAssemblyQuad("SUB1", first, second, third);
                else if (!isRegister[2] && !isRegister[3]) {
                    insertNewAssemblyQuad("WRITE", first, second, "-");
                    insertNewAssemblyQuad("SUB1", first, first, third);
                    incrementAliasesAfter(currentIntermediateCodeLine);
                }
            }
        }
        else if (sameString(command, "MULT")) {
            if (isRegister[2] && isRegister[3]) insertNewAssemblyQuad("MULT0", first, second, third);
            else if (isRegister[2] && !isRegister[3]) insertNewAssemblyQuad("MULT1", first, second, third);
            else if (!isRegister[2] && isRegister[3]) insertNewAssemblyQuad("MULT1", first, third, second);
            else if (!isRegister[2] && !isRegister[3]) {
                insertNewAssemblyQuad("WRITE", first, second, "-");
                insertNewAssemblyQuad("MULT1", first, first, third);
                incrementAliasesAfter(currentIntermediateCodeLine);
            }
        }
        else if (sameString(command, "DIV")) {
            if (!isRegister[2] && isRegister[3]) insertNewAssemblyQuad("ERROR", "ERROR", "ERROR", "ERROR");
            else {
                if (isRegister[2] && isRegister[3]) insertNewAssemblyQuad("DIV0", first, second, third);
                else if (isRegister[2] && !isRegister[3]) insertNewAssemblyQuad("DIV1", first, second, third);
                else if (!isRegister[2] && !isRegister[3]) {
                    insertNewAssemblyQuad("WRITE", first, second, "-");
                    insertNewAssemblyQuad("DIV1", first, first, third);
                    incrementAliasesAfter(currentIntermediateCodeLine);
                }
            }
        }
        else if (sameString(command, "EQ_EQ")) {
            if (isRegister[2] && isRegister[3]) insertNewAssemblyQuad("LOGIC4", first, second, third);
            else insertNewAssemblyQuad("ERROR", "ERROR", "ERROR", "ERROR");
        }
        else if (sameString(command, "NOT_EQ")) {
            if (isRegister[2] && isRegister[3]) insertNewAssemblyQuad("LOGIC5", first, second, third);
            else insertNewAssemblyQuad("ERROR", "ERROR", "ERROR", "ERROR");
        }
        else if (sameString(command, "GREAT")) {
            if (isRegister[2] && isRegister[3]) insertNewAssemblyQuad("LOGIC6", first, second, third);
            else insertNewAssemblyQuad("ERROR", "ERROR", "ERROR", "ERROR");
        }
        else if (sameString(command, "LESS")) {
            if (isRegister[2] && isRegister[3]) insertNewAssemblyQuad("LOGIC7", first, second, third);
            else insertNewAssemblyQuad("ERROR", "ERROR", "ERROR", "ERROR");
        }
        else if (sameString(command, "NOT")) {
            if (isRegister[2]) insertNewAssemblyQuad("LOGIC0", first, second, "-");
            else if (!isRegister[2]) insertNewAssemblyQuad("ERROR", "ERROR", "ERROR", "ERROR");
        }
        else if (sameString(command, "JUMPIF")) {
            if (isRegister[2]) insertNewAssemblyQuad("JUMP3", second, first, "-");
            else if (!isRegister[2]) insertNewAssemblyQuad("ERROR", "ERROR", "ERROR", "ERROR");
        }
        else if (sameString(command, "WRITE")) {
            if (!isRegister[2]) insertNewAssemblyQuad("WRITE", first, second, "-");
            else if (isRegister[2]) insertNewAssemblyQuad("ERROR", "ERROR", "ERROR", "ERROR");
        }
        else if (sameString(command, "LOAD")) {
            if (isRegister[2]) insertNewAssemblyQuad("LOAD", first, second, "-");
            else if (!isRegister[2]) insertNewAssemblyQuad("ERROR", "ERROR", "ERROR", "ERROR");
        }
        else if (sameString(command, "STORE")) {
            if (isRegister[2]) insertNewAssemblyQuad("STORE", first, second, "-");
            else if (!isRegister[2]) insertNewAssemblyQuad("ERROR", "ERROR", "ERROR", "ERROR");
        }
        else if (sameString(command, "EQ")) {
            if (isRegister[2]) insertNewAssemblyQuad("COPY", first, second, "-");
            else if (!isRegister[2]) insertNewAssemblyQuad("WRITE", first, second, "-");
        }
        else if (sameString(command, "JUMP")) {
            if (isRegister[1]) insertNewAssemblyQuad("JUMP2", first, "-", "-");
            else if (!isRegister[1]) insertNewAssemblyQuad("JUMP1", first, "-", "-");
        }
        else if (sameString(command, "JUMP0")) {
            insertNewAssemblyQuad("JUMP0", first, "-", "-");
        }
        else if (sameString(command, "PUSH")) {
            if (isRegister[1]) insertNewAssemblyQuad("STACK0", first, "-", "-");
            else if (!isRegister[1]) insertNewAssemblyQuad("ERROR", "ERROR", "ERROR", "ERROR");
        }
        else if (sameString(command, "POP")) {
            if (isRegister[1]) insertNewAssemblyQuad("STACK1", first, "-", "-");
            else if (!isRegister[1]) insertNewAssemblyQuad("ERROR", "ERROR", "ERROR", "ERROR");
        }
        else if (sameString(command, "INPUT")) {
            if (isRegister[1]) insertNewAssemblyQuad("INPUT", first, "-", "-");
            else if (!isRegister[1]) insertNewAssemblyQuad("ERROR", "ERROR", "ERROR", "ERROR");
        }
        else if (sameString(command, "OUTPUT")) {
            if (isRegister[1]) insertNewAssemblyQuad("COPY", "$63", first, "-");
            else if (!isRegister[1]) insertNewAssemblyQuad("ERROR", "ERROR", "ERROR", "ERROR");
        }

        currentQuad = currentQuad->next;
        currentIntermediateCodeLine++;
    }
}

void generateAssemblyCode() {
    readIntermediateCode();
}