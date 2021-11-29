%{

#include "../globals.h"

void yyerror(const char *s) {
    syntacticError();
}

%}

%start intermediateCode
%token ID NUM INT VOID RETURN IF ELSE WHILE EQ EQ_EQ SEMICOL L_BRACK R_BRACK L_BRACE R_BRACE
%token L_PAR R_PAR LESS_EQ LESS GREAT GREAT_EQ NOT_EQ COMMA SUM SUB MULT DIV ERR

%%

intermediateCode:   declaration_list
                        {
                            root = $1;
                        };

declaration_list:   declaration_list declaration
                        {
                            SyntaxTree *aux = $1;
                            if (aux != NULL) {
                                while (aux->sibling != NULL)
                                    aux = aux->sibling;
                                aux->sibling = $2;
                                $$ = $1;
                            }
                            else $$ = $2;
                        } |
                    declaration
                        {
                            $$ = $1;
                        };

declaration:        var_declaration
                        {
                            $$ = $1;
                        } |
                    fun_declaration
                        {
                            $$ = $1;
                        };

var_declaration:    type_specifier lonely_id SEMICOL
                        {
                            if ($1->tkn == VOID) {
                                // printf("semanticError var_declaration\n");
                                semanticError($2->label);
                            }

                            SyntaxTree* aux = $2;
                            // printf("var = %s, scope = %s\n", aux->label, scope);

                            char* chaux = (char*) malloc(100*sizeof(char));
                            strcpy(chaux, aux->label);
                            strcat(chaux, scope);
                            int tni = hash(chaux);

                            char* chaux2 = (char*) malloc(100*sizeof(char));
                            strcpy(chaux2, aux->label);
                            strcat(chaux2, "GLOBAL");
                            int tni2 = hash(chaux2);

                            Symbol *saux = &symbolTable[tni];
                            Symbol *saux2 = &symbolTable[tni2];
                            if (saux->type != -1 || saux2->type != -1) {
                                // printf("semanticError var_declaration2\n");
                                semanticError(aux->label);
                            }
                            else {
                                strcpy(saux->name, aux->label);
                                strcpy(saux->scope, scope);

                                saux->isFunction = 0;
                                saux->type = $1->tkn;

                                saux->firstLine = (Line*) malloc(sizeof(Line));
                                saux->firstLine->number = line_count;
                                saux->firstLine->next = NULL;
                                saux->lastLine = saux->firstLine;
                            }

                            $$ = $1;
                            $$->top = $2;
                        } |
                    type_specifier lonely_id L_BRACK lonely_num R_BRACK SEMICOL
                        {
                            if ($1->tkn == VOID) {
                                // printf("semanticError var_declaration3\n");
                                semanticError($2->label);
                            }

                            SyntaxTree* aux = $2;
                            // printf("var = %s, scope = %s\n", aux->label, scope);

                            char* chaux = (char*) malloc(100*sizeof(char));
                            strcpy(chaux, aux->label);
                            strcat(chaux, scope);
                            int tni = hash(chaux);

                            char* chaux2 = (char*) malloc(100*sizeof(char));
                            strcpy(chaux2, aux->label);
                            strcat(chaux2, "GLOBAL");
                            int tni2 = hash(chaux2);

                            Symbol *saux = &symbolTable[tni];
                            Symbol *saux2 = &symbolTable[tni2];
                            if (saux->type != -1 || saux2->type != -1) {
                                // printf("semanticError var_declaration4\n");
                                semanticError(aux->label);
                            }
                            else {
                                strcpy(saux->name, aux->label);
                                strcpy(saux->scope, scope);

                                SyntaxTree* aux2 = $1;
                                saux->isFunction = 0;
                                saux->type = aux2->tkn;

                                saux->firstLine = (Line*) malloc(sizeof(Line));
                                saux->firstLine->number = line_count;
                                saux->firstLine->next = NULL;
                                saux->lastLine = saux->firstLine;
                            }

                            $$ = $1;
                            $$->top = $2;
                            $2->top = $4;
                        };

type_specifier:     INT
                        {
                            $$ = newNode(INT, yytext, scope, 0, 0);
                        } |
                    VOID
                        {
                            $$ = newNode(VOID, yytext, scope, 0, 0);
                        };

fun_declaration:    new_fun params R_PAR compound_stmt
                        {
                            $$ = $1;
                            $1->mid = $2;
                            $1->bot = $4;
                            
                            strcpy(scope, "GLOBAL");
                        } |
                    new_fun R_PAR compound_stmt
                        {
                            $$ = $1;
                            $1->mid = NULL;
                            $1->bot = $3;
                            
                            strcpy(scope, "GLOBAL");
                        };

params:             param_list
                        {
                            $$ = $1;
                        } |
                    VOID
                        {
                            $$ = NULL;
                        };

param_list:         param_list COMMA param
                        {
                            SyntaxTree *t = $1;
                            if (t != NULL) {
                                while (t->sibling != NULL)
                                    t = t->sibling;
                                t->sibling = $3;
                                $$ = $1;
                            }
                            else $$ = $3;
                        } |
                    param
                        {
                            $$ = $1;
                        };

param:              type_specifier lonely_id
                        {
                            SyntaxTree* aux = $2;
                            // printf("var = %s, scope = %s\n", aux->label, scope);

                            char* chaux = (char*) malloc(100*sizeof(char));
                            strcpy(chaux, aux->label);
                            strcat(chaux, scope);
                            int tni = hash(chaux);

                            char* chaux2 = (char*) malloc(100*sizeof(char));
                            strcpy(chaux2, aux->label);
                            strcat(chaux2, "GLOBAL");
                            int tni2 = hash(chaux2);

                            Symbol *saux = &symbolTable[tni];
                            Symbol *saux2 = &symbolTable[tni2];
                            if (saux->type != -1 || saux2->type != -1) {
                                // printf("semanticError param\n");
                                semanticError(aux->label);
                            }
                            else {
                                strcpy(saux->name, aux->label);
                                strcpy(saux->scope, scope);

                                saux->isFunction = 0;
                                saux->type = $1->tkn;

                                saux->firstLine = (Line*) malloc(sizeof(Line));
                                saux->firstLine->number = line_count;
                                saux->firstLine->next = NULL;
                                saux->lastLine = saux->firstLine;
                            }

                            $$ = $1;
                            $$->top = $2;
                        } |
                    type_specifier lonely_id L_BRACK R_BRACK
                        {
                            SyntaxTree* aux = $2;
                            // printf("var = %s, scope = %s\n", aux->label, scope);

                            char* chaux = (char*) malloc(100*sizeof(char));
                            strcpy(chaux, aux->label);
                            strcat(chaux, scope);
                            int tni = hash(chaux);

                            char* chaux2 = (char*) malloc(100*sizeof(char));
                            strcpy(chaux2, aux->label);
                            strcat(chaux2, "GLOBAL");
                            int tni2 = hash(chaux2);

                            Symbol *saux = &symbolTable[tni];
                            Symbol *saux2 = &symbolTable[tni2];
                            if (saux->type != -1 || saux2->type != -1) {
                                // printf("semanticError param2\n");
                                semanticError(aux->label);
                            }
                            else {
                                strcpy(saux->name, aux->label);
                                strcpy(saux->scope, scope);

                                saux->isFunction = 0;
                                saux->type = $1->tkn;

                                saux->firstLine = (Line*) malloc(sizeof(Line));
                                saux->firstLine->number = line_count;
                                saux->firstLine->next = NULL;
                                saux->lastLine = saux->firstLine;
                            }

                            $$ = $1;
                            $$->top = $2;
                        };

compound_stmt:      L_BRACE local_declarations statement_list R_BRACE
                        {
                            SyntaxTree* aux = $2;
                            if (aux == NULL) {
                                $$ = $3;
                            }
                            else {
                                $$ = $2;
                                aux = $2;
                                while (aux->sibling != NULL)
                                    aux = aux->sibling;
                                aux->sibling = $3;
                            }
                        };

local_declarations: local_declarations var_declaration
                        {
                            SyntaxTree *aux = $1;
                            if (aux != NULL) {
                                while (aux->sibling != NULL)
                                    aux = aux->sibling;
                                aux->sibling = $2;
                                $$ = $1;
                            }
                            else $$ = $2;
                        } |

                        {
                            $$ = NULL;
                        };
                    
statement_list:   statement_list statement
                        {
                            SyntaxTree *aux = $1;
                            if (aux != NULL) {
                                while (aux->sibling != NULL)
                                    aux = aux->sibling;
                                aux->sibling = $2;
                                $$ = $1;
                            }
                            else $$ = $2;
                        } |

                        {
                            $$ = NULL;
                        };

statement:          expression_stmt
                        { $$ = $1; } |
                    compound_stmt
                        { $$ = $1; } |
                    selection_stmt
                        { $$ = $1; } |
                    iteration_stmt
                        { $$ = $1; } |
                    return_stmt
                        { $$ = $1; };

expression_stmt:    expression SEMICOL
                        { $$ = $1; } |
                    SEMICOL
                        {
                            char *aux = (char*) malloc(6*sizeof(char));
                            strcpy(aux, "EMPTY");
                            $$ = newNode(-1, aux, scope, 0, 0);
                        };

selection_stmt:     IF L_PAR expression R_PAR statement
                        {
                            char *aux = (char*) malloc(3*sizeof(char));
                            strcpy(aux, "if");
                            $$ = newNode(IF, aux, scope, 0, 0);
                            $$->top = $3;
                            $$->mid = $5;
                        } |
                    IF L_PAR expression R_PAR statement ELSE statement
                        {
                            char *aux = (char*) malloc(3*sizeof(char));
                            strcpy(aux, "if");
                            $$ = newNode(IF, aux, scope, 0, 0);
                            $$->top = $3;
                            $$->mid = $5;
                            $$->bot = $7;
                        };

iteration_stmt:     WHILE L_PAR expression R_PAR statement
                        {
                            char *aux = (char*) malloc(6*sizeof(char));
                            strcpy(aux, "while");
                            $$ = newNode(WHILE, aux, scope, 0, 0);
                            $$->top = $3;
                            $$->mid = $5;
                        };

return_stmt:        RETURN SEMICOL
                        {
                            char *aux = (char*) malloc(7*sizeof(char));
                            strcpy(aux, "return");
                            $$ = newNode(RETURN, aux, scope, 0, 0);
                        } |
                    RETURN expression SEMICOL
                        {
                            char *aux = (char*) malloc(7*sizeof(char));
                            strcpy(aux, "return");
                            $$ = newNode(RETURN, aux, scope, 0, 0);
                            $$->top = $2;
                        };

expression:         var EQ expression
                        {
                            char* chaux = (char*) malloc(sizeof(char));
                            strcpy(chaux, $3->label);
                            strcat(chaux, "GLOBAL");
                            int tni = hash(chaux);

                            Symbol *saux = &symbolTable[tni];

                            if (saux->type == VOID) {
                                // printf("semanticError expression\n");
                                semanticError($3->label);
                            }

                            char *aux = (char*) malloc(2*sizeof(char));
                            strcpy(aux, "=");
                            $$ = newNode(EQ, aux, scope, 0, 0);
                            $$->top = $1;
                            $$->mid = $3;
                        } |
                    simple_expression
                        { $$ = $1; };

var:                lonely_id
                        {
                            // printf("de novo var = %s, scope = %s\n", $1->label, scope);

                            char* chaux = (char*) malloc(100*sizeof(char));
                            strcpy(chaux, $1->label);
                            strcat(chaux, scope);
                            int tni = hash(chaux);

                            char* chaux2 = (char*) malloc(100*sizeof(char));
                            strcpy(chaux2, $1->label);
                            strcat(chaux2, "GLOBAL");
                            int tni2 = hash(chaux2);

                            Symbol *saux = &symbolTable[tni];
                            Symbol *saux2 = &symbolTable[tni2];
                            
                            if (saux->type == -1 && saux2->type == -1) {
                                // printf("semanticError var\n");
                                semanticError($1->label);
                            } else {
                                Line *laux = (Line*) malloc(sizeof(Line));
                                laux->number = line_count;
                                
                                if (saux->type == -1) {
                                    saux2->lastLine->next = laux;
                                    saux2->lastLine = laux;
                                    saux2->lastLine->next = NULL;
                                } else if(saux2->type == -1) {
                                    saux->lastLine->next = laux;
                                    saux->lastLine = laux;
                                    saux->lastLine->next = NULL;
                                }
                            }

                            $$ = $1;
                        } |
                    lonely_id L_BRACK expression R_BRACK
                        {
                            // printf("de novo var = %s, scope = %s\n", $1->label, scope);

                            char* chaux = (char*) malloc(100*sizeof(char));
                            strcpy(chaux, $1->label);
                            strcat(chaux, scope);
                            int tni = hash(chaux);

                            char* chaux2 = (char*) malloc(100*sizeof(char));
                            strcpy(chaux2, $1->label);
                            strcat(chaux2, "GLOBAL");
                            int tni2 = hash(chaux2);

                            Symbol *saux = &symbolTable[tni];
                            Symbol *saux2 = &symbolTable[tni2];
                            if (saux->type == -1 && saux2->type == -1) {
                                // printf("semanticError var2\n");
                                semanticError($1->label);
                            } else {
                                Line *laux = (Line*) malloc(sizeof(Line));
                                laux->number = line_count;
                                
                                if (saux->type == -1) {
                                    saux2->lastLine->next = laux;
                                    saux2->lastLine = laux;
                                    saux2->lastLine->next = NULL;
                                } else if(saux2->type == -1) {
                                    saux->lastLine->next = laux;
                                    saux->lastLine = laux;
                                    saux->lastLine->next = NULL;
                                }
                            }

                            $$ = $1;
                            $$->top = $3;
                        };

simple_expression:  additive_expression relop additive_expression
                        {
                            $$ = $2;
                            $$->top = $1;
                            $$->mid = $3;
                        } |
                    additive_expression
                        { $$ = $1; };

relop:              LESS_EQ
                        {
                            char *aux = (char*) malloc(3*sizeof(char));
                            strcpy(aux, "<=");
                            $$ = newNode(LESS_EQ, aux, scope, 0, 0);
                        } |
                    LESS
                        {
                            char *aux = (char*) malloc(2*sizeof(char));
                            strcpy(aux, "<");
                            $$ = newNode(LESS, aux, scope, 0, 0); } |
                    GREAT
                        {
                            char *aux = (char*) malloc(2*sizeof(char));
                            strcpy(aux, ">");
                            $$ = newNode(GREAT, aux, scope, 0, 0);
                        } |
                    GREAT_EQ
                        {
                            char *aux = (char*) malloc(3*sizeof(char));
                            strcpy(aux, ">=");
                            $$ = newNode(GREAT_EQ, aux, scope, 0, 0);
                        } |
                    EQ_EQ
                        {
                            char *aux = (char*) malloc(3*sizeof(char));
                            strcpy(aux, "==");
                            $$ = newNode(EQ_EQ, aux, scope, 0, 0);
                        } |
                    NOT_EQ
                        {
                            char *aux = (char*) malloc(3*sizeof(char));
                            strcpy(aux, "!=");
                            $$ = newNode(NOT_EQ, aux, scope, 0, 0);
                        };

additive_expression:additive_expression addop term
                        {
                            $$ = $2;
                            $$->top = $1;
                            $$->mid = $3;
                        } |
                    term
                        { $$ = $1; };

addop:              SUM
                        {
                            char *aux = (char*) malloc(2*sizeof(char));
                            strcpy(aux, "+");
                            $$ = newNode(SUM, aux, scope, 0, 0);
                        } |
                    SUB
                        {
                            char *aux = (char*) malloc(2*sizeof(char));
                            strcpy(aux, "-");
                            $$ = newNode(SUB, aux, scope, 0, 0);
                        };

term:               term mulop factor
                        {
                            $$ = $2;
                            $$->top = $1;
                            $$->mid = $3;
                        } |
                    factor
                        { $$ = $1; };

mulop:              MULT
                        {
                            char *aux = (char*) malloc(2*sizeof(char));
                            strcpy(aux, "*");
                            $$ = newNode(MULT, aux, scope, 0, 0);
                        } |
                    DIV
                        {
                            char *aux = (char*) malloc(2*sizeof(char));
                            strcpy(aux, "/");
                            $$ = newNode(DIV, aux, scope, 0, 0);
                        };

factor:             L_PAR expression R_PAR
                        { $$ = $2; } |
                    var
                        { $$ = $1; } |
                    call
                        { $$ = $1; } |
                    lonely_num
                        { $$ = $1; };

call:               lonely_id L_PAR args R_PAR
                        {
                            // printf("de novo fun = %s, scope = %s\n", $1->label, scope);
                            $1->isFunction = 1;

                            char* chaux = (char*) malloc(100*sizeof(char));
                            strcpy(chaux, $1->label);
                            strcat(chaux, "GLOBAL");
                            int tni = hash(chaux);

                            Symbol *saux = &symbolTable[tni];
                            
                            if (saux->type == -1 && strcmp($1->label, "input") && strcmp($1->label, "output")) {
                                // printf("semanticError call\n");
                                semanticError($1->label);
                            } else if(strcmp($1->label, "input") && strcmp($1->label, "output")) {
                                Line *laux = (Line*) malloc(sizeof(Line));
                                laux->number = line_count;

                                $1->isVoid = saux->type == VOID;
                                
                                saux->lastLine->next = laux;
                                saux->lastLine = laux;
                                saux->lastLine->next = NULL;
                            }

                            $$ = $1;
                            $$->top = $3;
                        };

args:               arg_list
                        { $$ = $1; } |
                    
                        {
                            $$ = NULL;
                        };

arg_list:           arg_list COMMA expression
                        {
                            SyntaxTree *t = $1;
                            if (t != NULL) {
                                while (t->sibling != NULL)
                                    t = t->sibling;
                                t->sibling = $3;
                                $$ = $1;
                            }
                            else $$ = $3;
                        } |
                    expression
                        {
                            $$ = $1;
                        };

new_fun:            type_specifier lonely_id L_PAR
                        {
                            SyntaxTree* aux = $2;
                            // printf("fun = %s, scope = %s\n", aux->label, scope);
                            $2->isFunction = 1;

                            char* chaux = (char*) malloc(100 * sizeof(char));
                            strcpy(chaux, $2->label);
                            strcat(chaux, "GLOBAL");
                            int tni = hash(chaux);

                            Symbol *saux = &symbolTable[tni];
                            if (saux->type != -1) {
                                // printf("semanticError new_fun\n");
                                semanticError($2->label);
                            }
                            else {
                                strcpy(saux->name, aux->label);
                                strcpy(saux->scope, "GLOBAL");

                                saux->isFunction = 1;
                                saux->type = $1->tkn;
                                $2->isVoid = $1->tkn == VOID;

                                saux->firstLine = (Line*) malloc(sizeof(Line));
                                saux->firstLine->number = line_count;
                                saux->firstLine->next = NULL;
                                saux->lastLine = saux->firstLine;
                            }

                            $$ = $1;
                            $$->top = $2;
                            
                            strcpy(scope, $2->label);
                            // printf("new scope %s   teste %s\n", scope, $2->label);
                        };

lonely_id:          ID
                        { $$ = newNode(ID, yytext, scope, 0, 0); };

lonely_num:         NUM
                        { $$ = newNode(NUM, yytext, scope, 0, 0); };

%%
