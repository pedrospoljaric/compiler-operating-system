#include "../../../globals.h"

void insertNewAssemblyQuad(char *command, char *first, char *second, char *third) {
    insertAssemblyQuad(newQuadruple(command, first, second, third));
}
