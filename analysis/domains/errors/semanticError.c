#include "../../../globals.h"

void semanticError(char *id) {
    if (sErrorLine == -1) {
        strcpy(sErrorId, id);
        sErrorLine = line_count;
    }
}
