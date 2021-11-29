#ifndef SYNTHESIS_H
#define SYNTHESIS_H

#include "tokenHandlers/tokenHandlers.h"
#include "domains/domains.h"

IntermediateCode *intermediateCode;
AssemblyCode *assemblyCode;
BinaryCode *binaryCode;

char *readSyntaxTree(SyntaxTree *node);
void readTreeDiscardReturn(SyntaxTree *node);
void generateIntermediateCode(SyntaxTree* root);
void generateAssemblyCode();
void generateBinaryCode(int mode);

#endif
