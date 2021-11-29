#include "../../globals.h"

char *handleGREAT_EQ(SyntaxTree *node) {
    char *result = handleLESS(node);

    insertNewQuadruple("NOT", result, result, "-");
    return result;
}