#ifndef DOMAIN_SYMBOL_H
#define DOMAIN_SYMBOL_H

#include "../../../globals.h"

#define T_FUN 1
#define T_VAR 2

#define HASHSIZE 9999999

unsigned long int HexToDec(char hexVal[]);
int hash(char *palavra);
void printSymbolTable(Symbol *symbolTable, char *fileName);

#endif
