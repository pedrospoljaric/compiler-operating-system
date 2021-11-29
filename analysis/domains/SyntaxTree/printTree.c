#include "../../../globals.h"

int indentno = 0;

void printSpaces(FILE *ptree, int nodeType) {
    int i;
    for (i = 0; i < indentno; i++)
        fprintf(ptree, "%s", i == indentno-1 ?
            nodeType == ROOT ? "" :
            nodeType == TOP ? "" :
            nodeType == MID ? "" :
            nodeType == BOT ? "" :
            " " :
            "    "
        );
}

void printTree2(SyntaxTree* r, FILE *ptree, int nodeType) {
    int nType = nodeType;
    INDENT;
    while (r != NULL) {
        printSpaces(ptree, nType);
        fprintf(ptree, "%s\n", r->label);
        printTree2(r->top, ptree, TOP);
        printTree2(r->mid, ptree, MID);
        printTree2(r->bot, ptree, BOT);
        r = r->sibling;
        nType = SIBLING;
    }
    UNINDENT;
}

void printTree(SyntaxTree* r, char *fileName) {
    FILE *ptree;
    ptree = fopen(fileName, "w");

    printTree2(r, ptree, ROOT);
}
