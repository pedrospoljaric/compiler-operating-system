#include "../../../globals.h"

int lexicalError() {    
    printf("ERRO LÉXICO: %s :: LINHA: %d\n", yytext, line_count);
    exit(0);
}
