#include "../../../globals.h"

void insertNewQuadruple(char *command, char *first, char *second, char *third) {
    insertQuadruple(newQuadruple(command, first, second, third));
}
