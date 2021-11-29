#include "../../../globals.h"

int hash(char *palavra) {
    char hashHex[21];
    char hexresult[41];

    SHA1(hashHex, palavra, strlen(palavra));

    int offset;
    for(offset = 0; offset < 20; offset++)
        sprintf( ( hexresult + (2*offset)), "%02x", hashHex[offset]&0xff);

    unsigned long int hashLong = HexToDec(hexresult);

    return hashLong%HASHSIZE;
}
