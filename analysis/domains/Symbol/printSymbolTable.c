#include "../../../globals.h"

void printSymbolTable(Symbol *symbolTable, char *fileName) {

    FILE *stab = fopen(fileName, "w");
    fprintf(stab, "%*s | %*s | %*s | %*s | %*s | %s\n", 10, "Index", 15, "Identifier", 15, "Scope", 15, "ID Type", 15, "Data Type", "Lines");

    int i;
    for (i = 0; i < 100; i++) fprintf(stab, "-");
    fprintf(stab, "\n");

    for (i = 0; i < HASHSIZE; i++) {
        if (symbolTable[i].type != -1) {
            fprintf(stab, "%*d | %*s | %*s | %*s | %*s | ", 10, i, 15, symbolTable[i].name, 15, symbolTable[i].scope, 15, symbolTable[i].isFunction ? "FUN" : "VAR", 15, symbolTable[i].type == VOID ? "VOID" : "INT");
            
            Line *aux = symbolTable[i].firstLine;
            
            while(aux != NULL) {
                fprintf(stab, "%d ", aux->number);
                aux = aux->next;
            }
            
            fprintf(stab, "\n");
        }
    }

    fclose(stab);
}
