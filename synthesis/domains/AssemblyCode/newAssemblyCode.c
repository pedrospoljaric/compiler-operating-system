#include "../../../globals.h"

AssemblyCode *newAssemblyCode() {
    AssemblyCode *assemblyCode = (AssemblyCode*) malloc(sizeof(AssemblyCode));

    assemblyCode->firstQuad = NULL;
    assemblyCode->lastQuad = NULL;

    return assemblyCode;
}
