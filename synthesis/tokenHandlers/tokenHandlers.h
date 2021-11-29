#ifndef TOKEN_HANDLERS_H
#define TOKEN_HANDLERS_H

#include "../../globals.h"

char *handleID(SyntaxTree *node);
char *handleNUM(SyntaxTree *node);
void handleINT(SyntaxTree *node);
void handleVOID(SyntaxTree *node);
void handleRETURN(SyntaxTree *node);
void handleIF(SyntaxTree *node);
void handleWHILE(SyntaxTree *node);
void handleEQ(SyntaxTree *node);
char *handleEQ_EQ(SyntaxTree *node);
char *handleLESS_EQ(SyntaxTree *node);
char *handleLESS(SyntaxTree *node);
char *handleGREAT(SyntaxTree *node);
char *handleGREAT_EQ(SyntaxTree *node);
char *handleNOT_EQ(SyntaxTree *node);
char *handleSUM(SyntaxTree *node);
char *handleSUB(SyntaxTree *node);
char *handleMULT(SyntaxTree *node);
char *handleDIV(SyntaxTree *node);

#endif
