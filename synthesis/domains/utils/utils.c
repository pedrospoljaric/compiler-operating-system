#include "../../../globals.h"

char *getTknName(int tkn) {
    if (tkn == ID) return "ID";
    if (tkn == NUM) return "NUM";
    if (tkn == INT) return "INT";
    if (tkn == VOID) return "VOID";
    if (tkn == RETURN) return "RETURN";
    if (tkn == IF) return "IF";
    if (tkn == ELSE) return "ELSE";
    if (tkn == WHILE) return "WHILE";
    if (tkn == EQ) return "EQ";
    if (tkn == EQ_EQ) return "EQ_EQ";
    if (tkn == SEMICOL) return "SEMICOL";
    if (tkn == L_BRACK) return "L_BRACK";
    if (tkn == R_BRACK) return "R_BRACK";
    if (tkn == L_BRACE) return "L_BRACE";
    if (tkn == R_BRACE) return "R_BRACE";
    if (tkn == L_PAR) return "L_PAR";
    if (tkn == R_PAR) return "R_PAR";
    if (tkn == LESS_EQ) return "LESS_EQ";
    if (tkn == LESS) return "LESS";
    if (tkn == GREAT) return "GREAT";
    if (tkn == GREAT_EQ) return "GREAT_EQ";
    if (tkn == NOT_EQ) return "NOT_EQ";
    if (tkn == COMMA) return "COMMA";
    if (tkn == SUM) return "SUM";
    if (tkn == SUB) return "SUB";
    if (tkn == MULT) return "MULT";
    if (tkn == DIV) return "DIV";
    if (tkn == ERR) return "ERR";
    return "";
}

int getNameTkn(char *name) {
    if (strcmp(name, "ID") == 0) return ID;
    if (strcmp(name, "NUM") == 0) return NUM;
    if (strcmp(name, "INT") == 0) return INT;
    if (strcmp(name, "VOID") == 0) return VOID;
    if (strcmp(name, "RETURN") == 0) return RETURN;
    if (strcmp(name, "IF") == 0) return IF;
    if (strcmp(name, "ELSE") == 0) return ELSE;
    if (strcmp(name, "WHILE") == 0) return WHILE;
    if (strcmp(name, "EQ") == 0) return EQ;
    if (strcmp(name, "EQ_EQ") == 0) return EQ_EQ;
    if (strcmp(name, "SEMICOL") == 0) return SEMICOL;
    if (strcmp(name, "L_BRACK") == 0) return L_BRACK;
    if (strcmp(name, "R_BRACK") == 0) return R_BRACK;
    if (strcmp(name, "L_BRACE") == 0) return L_BRACE;
    if (strcmp(name, "R_BRACE") == 0) return R_BRACE;
    if (strcmp(name, "L_PAR") == 0) return L_PAR;
    if (strcmp(name, "R_PAR") == 0) return R_PAR;
    if (strcmp(name, "LESS_EQ") == 0) return LESS_EQ;
    if (strcmp(name, "LESS") == 0) return LESS;
    if (strcmp(name, "GREAT") == 0) return GREAT;
    if (strcmp(name, "GREAT_EQ") == 0) return GREAT_EQ;
    if (strcmp(name, "NOT_EQ") == 0) return NOT_EQ;
    if (strcmp(name, "COMMA") == 0) return COMMA;
    if (strcmp(name, "SUM") == 0) return SUM;
    if (strcmp(name, "SUB") == 0) return SUB;
    if (strcmp(name, "MULT") == 0) return MULT;
    if (strcmp(name, "DIV") == 0) return DIV;
    if (strcmp(name, "ERR") == 0) return ERR;
    return -1;
}

char *intToVarName(int position) {
    char *varName = (char*) malloc(100 * sizeof(char));
    char *positionStr = (char*) malloc(100 * sizeof(char));
    sprintf(positionStr, "%d", position);
    strcpy(varName, "$");
    strcat(varName, positionStr);
    return varName;
}

char *intToAliasName(int position) {
    char *varName = (char*) malloc(100 * sizeof(char));
    char *positionStr = (char*) malloc(100 * sizeof(char));
    sprintf(positionStr, "%d", position);
    strcpy(varName, "#");
    strcat(varName, positionStr);
    return varName;
}

int strToInt(char *str) {
    return (int) strtol(str, (char **)NULL, 10);
}

char *intToStr(int n) {
    char *str = (char*) malloc(100 * sizeof(char));
    sprintf(str, "%d", n);
    return str;
}

char *newAllocatedStr(char *str) {
    char *new = (char*) malloc((strlen(str) + 1) * sizeof(char));
    strcpy(new, str);
    return new;
}

int strStartsWith(char *str, char *start) {
    return strncmp(start, str, strlen(start)) == 0;
}

int sameString(char *str1, char *str2) {
    return strcmp(str1, str2) == 0;
}

int strIsRegister(char *str) {
    return str[0] == '$';
}

int strIsAlias(char *str) {
    return str[0] == '#';
}