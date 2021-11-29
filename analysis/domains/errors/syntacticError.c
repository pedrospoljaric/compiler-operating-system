#include "../../../globals.h"

void syntacticError() {
    printf("ERRO SINTÁTICO: %s LINHA %d\n", yytext, line_count);
    exit(0);
}
