#ifndef SYNTHESIS_DOMAIN_UTILS_H
#define SYNTHESIS_DOMAIN_UTILS_H

#include "../../../globals.h"

char *getTknName(int tkn);
int getNameTkn(char *name);
char *intToVarName(int position);
char *intToAliasName(int position);
int strToInt(char *str);
char *intToStr(int n);
char *newAllocatedStr(char *str);
int strStartsWith(char *str, char *start);
int sameString(char *str1, char *str2);
int strIsRegister(char *str);
int strIsAlias(char *str);

#endif
