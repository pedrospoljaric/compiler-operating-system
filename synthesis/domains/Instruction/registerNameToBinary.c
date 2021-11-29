#include "../../../globals.h"

char *registerNameToBinary(char *registerName, int mode) {
    char registerNumberStr[strlen(registerName)];
    
    int i;
    for (i = 0; i < strlen(registerName); i++) {
        if (i > 0) registerNumberStr[i-1] = registerName[i];
    }
    registerNumberStr[i-1] = '\0';

    int registerNumber = strToInt(registerNumberStr);

    if (mode != 3 && registerNumber >= 50 && registerNumber <= 60) printf("Região restrita de registradores (51-60) acessada: $%d\n", registerNumber);
    return decimalToExtendedBinary(registerNumber, 6);
}
