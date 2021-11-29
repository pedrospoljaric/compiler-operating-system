#include "../globals.h"

char *readSyntaxTree(SyntaxTree *node) {
    if (node) {
        switch (node->tkn) {
            case ID: {
                char *result = handleID(node);
                if (strlen(result) > 0) return result;
            } break;
            case NUM: return handleNUM(node); break;
            case INT: handleINT(node); break;
            case VOID: handleVOID(node); break;
            case RETURN: handleRETURN(node); break;
            case IF: handleIF(node); break;
            case WHILE: handleWHILE(node); break;
            case EQ: handleEQ(node); break;
            case EQ_EQ: return handleEQ_EQ(node); break;
            case LESS_EQ: return handleLESS_EQ(node); break;
            case LESS: return handleLESS(node); break;
            case GREAT: return handleGREAT(node); break;
            case GREAT_EQ: return handleGREAT_EQ(node); break;
            case NOT_EQ: return handleNOT_EQ(node); break;
            case SUM: return handleSUM(node); break;
            case SUB: return handleSUB(node); break;
            case MULT: return handleMULT(node); break;
            case DIV: return handleDIV(node); break;
        }
        
        readTreeDiscardReturn(node->sibling);
    }
    return "";
}

void generateIntermediateCode(SyntaxTree* root) {
    readSyntaxTree(root);
    // incrementAliasesAfter(-1);
    
    // printIntermediateCodeQuadruples();

    // Alias *mainAlias = findFunctionAlias("main");
    // Quadruple *goToMain = newQuadruple("JUMP", mainAlias->aliasName, "-", "-");

    // goToMain->next = intermediateCode->firstQuad;
    // intermediateCode->firstQuad = goToMain;
}