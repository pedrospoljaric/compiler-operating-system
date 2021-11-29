#include "../../../globals.h"

unsigned long int HexToDec(char hexVal[]) {
    int len = strlen(hexVal);
    int base = 1;
    unsigned long int dec_val = 0;
    int i;

    for (i=len-1; i>=0; i--) {
        if (hexVal[i]>='0' && hexVal[i]<='9') {
            dec_val += (hexVal[i] - 48)*base;
            base = base * 16;
        }
        else if (hexVal[i]>='A' && hexVal[i]<='F') {
            dec_val += (hexVal[i] - 55)*base;
            base = base*16;
        }
    }

    return dec_val;
}
