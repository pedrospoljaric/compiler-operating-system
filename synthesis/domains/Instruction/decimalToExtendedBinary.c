#include "../../../globals.h"

char *decimalToExtendedBinary(int decimal, int length) {
    char *binary = (char*) malloc((length + 1) * sizeof(char));
    
    int i;
    for (i = length-1; i >= 0; i--) {
        binary[i] = decimal % 2 ? '1' : '0';
        decimal = decimal / 2;
    }
    binary[length] = '\0';

    return binary;
}
