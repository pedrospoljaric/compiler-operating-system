#include "../../../globals.h"

char *commandToOpCode(char *command) {
    char *opcode = (char*) malloc(5 * sizeof(char));

    if (strStartsWith(command, "SUM")) strcpy(opcode, "0000");
    if (strStartsWith(command, "SUB")) strcpy(opcode, "0001");
    if (strStartsWith(command, "MULT")) strcpy(opcode, "0010");
    if (strStartsWith(command, "DIV")) strcpy(opcode, "0011");
    if (strStartsWith(command, "SHIFT")) strcpy(opcode, "0100");
    if (strStartsWith(command, "LOGIC")) strcpy(opcode, "0101");
    if (strStartsWith(command, "JUMP")) strcpy(opcode, "0110");
    if (strStartsWith(command, "STACK")) strcpy(opcode, "0111");
    if (strStartsWith(command, "WRITE")) strcpy(opcode, "1000");
    if (strStartsWith(command, "COPY")) strcpy(opcode, "1001");
    if (strStartsWith(command, "LOAD")) strcpy(opcode, "1010");
    if (strStartsWith(command, "STORE")) strcpy(opcode, "1011");
    if (strStartsWith(command, "SLEEP")) strcpy(opcode, "1100");
    if (strStartsWith(command, "INPUT")) strcpy(opcode, "1100");

    return opcode;
}