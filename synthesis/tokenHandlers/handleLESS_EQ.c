#include "../../globals.h"

char *handleLESS_EQ(SyntaxTree *node) {
    char *result = handleGREAT(node);

    insertNewQuadruple("NOT", result, result, "-");
    return result;
}