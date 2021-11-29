#ifndef DOMAIN_ASSEMBLYCODE_H
#define DOMAIN_ASSEMBLYCODE_H

#include "../../../globals.h"

AssemblyCode *newAssemblyCode();
void insertAssemblyQuad(Quadruple *quadruple);
void insertNewAssemblyQuad(char *command, char *first, char *second, char *third);
void outputAssemblyCode(char *fileName);

#endif