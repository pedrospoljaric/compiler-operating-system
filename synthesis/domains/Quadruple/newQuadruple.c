#include "../../../globals.h"

Quadruple *newQuadruple(char *command, char *first, char *second, char *third) {
    Quadruple *quadruple = (Quadruple*) malloc(sizeof(Quadruple));

    quadruple->command = (char*) malloc((strlen(command) + 1) * sizeof(char));
    strcpy(quadruple->command, command);
    quadruple->first = (char*) malloc((strlen(first) + 1) * sizeof(char));
    strcpy(quadruple->first, first);
    quadruple->second = (char*) malloc((strlen(second) + 1) * sizeof(char));
    strcpy(quadruple->second, second);
    quadruple->third = (char*) malloc((strlen(third) + 1) * sizeof(char));
    strcpy(quadruple->third, third);

    return quadruple;
}