#include "../../../globals.h"

void incrementAliasesAfter(int lineNumber) {
    int i;
    for (i = 0; i < intermediateCode->totalAliases; i++) {
        if (intermediateCode->aliases[i]->lineNumber > lineNumber)
            intermediateCode->aliases[i]->lineNumber++;
    }
}
