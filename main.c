#include "globals.h"

typedef enum{false, true} bool;

int main(int argc, char *argv[]) {
    int mode = argc > 2 ? strToInt(argv[2]) : 1;
    FILE *file = fopen(argv[1], "r");

    if (mode == 1) {
        initializeVariables();

        int i;
        for (i = 0; i < HASHSIZE; i++) {
            symbolTable[i].type = -1;
        }

        yyin = file;
        yyparse();

        char m[] = "mainGLOBAL";

        int h = hash(m);

        if (symbolTable[h].type == -1 || !symbolTable[h].isFunction) semanticError((char*)"main");

        if (sErrorLine != -1) {
            printf("ERRO SEMÂNTICO: %s LINHA: %d\n", sErrorId, sErrorLine);
            exit(0);
        }
    }

    // Fim da etapa de analise

    char folderName[100];
    strcpy(folderName, argv[1]);
    folderName[strlen(folderName) - 4] = '\0';
    struct stat st = {0};
    if (stat(folderName, &st) == -1) mkdir(folderName, 0700);
    
    intermediateCode = newIntermediateCode();
    assemblyCode = newAssemblyCode();
    binaryCode = newBinaryCode();

    if (mode == 1) {
        char treeFileName[100];
        strcpy(treeFileName, folderName);
        strcat(treeFileName, "/ptree.txt");
        printTree(root, treeFileName);

        char symbolFileName[100];
        strcpy(symbolFileName, folderName);
        strcat(symbolFileName, "/stab.txt");
        printSymbolTable(symbolTable, symbolFileName);
        
        generateIntermediateCode(root);

        char intermediateCodeFileName[100];
        strcpy(intermediateCodeFileName, folderName);
        strcat(intermediateCodeFileName, "/intermediateCode.txt");
        outputIntermediateCode(intermediateCodeFileName);
    }
    if (mode == 2) {
        char command[10], first[10], second[10], third[10];
        while (fscanf(file, "%s %s %s %s", command, first, second, third) != EOF) {
            if(!sameString(command, "-")) insertNewQuadruple(command, first, second, third);
        }
    }
    
    if (mode <= 2) {
        generateAssemblyCode();

        char assemblyCodeFileName[100];
        strcpy(assemblyCodeFileName, folderName);
        strcat(assemblyCodeFileName, "/assemblyCode.txt");
        outputAssemblyCode(assemblyCodeFileName);
    }
    if (mode == 3) {
        char command[10], first[10], second[10], third[10];
        while (fscanf(file, "%s %s %s %s", command, first, second, third) != EOF) {
            if(!sameString(command, "-")) insertNewAssemblyQuad(command, first, second, third);
        }
    }

    generateBinaryCode(mode);

    char binaryCodeFileName[100];
    strcpy(binaryCodeFileName, folderName);
    strcat(binaryCodeFileName, "/binaryCode.txt");
    outputBinaryCode(binaryCodeFileName);

    return 0;
}
