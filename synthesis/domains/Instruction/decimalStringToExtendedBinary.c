#include "../../../globals.h"

char *decimalStringToExtendedBinary(char *decimalStr, int length) {
    int number = strToInt(decimalStr);

    return decimalToExtendedBinary(number, length);
}