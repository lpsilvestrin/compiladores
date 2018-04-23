#ifndef _ASTREE_H
#define _ASTREE_H


#define MAX_OFFSPRING 4 //suggested by our teacher




/*here we will put a lot of defines with values for representing the possible types inside the AST*/
/*#define AST_INITIAL 1
#define AST_GLOBAL_VAR_DEF 2
#define AST_GLOBAL_VECTOR_DEF 42
#define AST_VECTOR_DEF 3
#define AST_INT 4
#define AST_FUNCTION_DEF 5
#define AST_HEADER 6
#define AST_DEF_PARAM 7
#define AST_DEF_PARAM_T 8
#define AST_COMMANDS_L 9
#define AST_VECTOR_AS 10
#define AST_VAR_AS 11
#define AST_READ 12
#define AST_PRINT 13
#define AST_NOT_EXP 14
#define AST_NEG_EXP 15
#define AST_PAR_EXP 16
#define AST_PLUS_EXP 17
#define AST_MINUS_EXP 18
#define AST_MUL_EXP 19
#define AST_DIV_EXP 20
#define AST_LESS_EXP 21
#define AST_GREAT_EXP 22
#define AST_LE_EXP 23
#define AST_GE_EXP 24
#define AST_EQ_EXP 25
#define AST_NE_EXP 26
#define AST_AND_EXP 27
#define AST_OR_EXP 28
#define AST_ID 29
#define AST_ID_POINTER 30
#define AST_ID_ADDRESS 31
#define AST_VECTOR 32
#define AST_FUNCTION 33
#define AST_PARAM 34
#define AST_IF 35
#define AST_IFELSE 36
#define AST_FOR 37
#define AST_WHILE 38
#define AST_REAL 39
#define AST_CHAR 40
#define AST_INIT_VALUES 41



*/



#include "hashtable.h"

typedef struct astree {
    int type; 
    hashNode *id; //pointer for the info inside our hash
    struct astree *offspring[MAX_OFFSPRING];
} ASTree;

ASTree* astree_create(int type, hashNode *id, ASTree *offspring_0, ASTree *offspring_1, ASTree *offspring_2, ASTree *offspring_3);
void print_astnode(ASTree* node, int level);
int decompile_tree(ASTree* tree, FILE *prog);

#endif
