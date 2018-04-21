#ifndef _ASTREE_H
#define _ASTREE_H


#define MAX_OFFSPRING 4 //suggested by our teacher




/*here we will put a lot of defines with values for representing the possible types inside the AST*/
#define AST_INITIAL 1
#define AST_GLOBAL_VAR_DEF 2
#define AST_VECTOR_DEF 3
#define AST_INT 4
#define AST_FUNCTION_DEF 5
#define AST_HEADER 6
#define AST_DEF_PARAM 7
#define AST_DEF_PARAM_T 8
#define AST_COMMANDS_L 9



#include "hashtable.h"

typedef struct astree {
    int type; 
    hashNode *id; //pointer for the info inside our hash
    struct astree *offspring[MAX_OFFSPRING];
} ASTree;

ASTree* astree_create(int type, hashNode *id, ASTree *offspring_0, ASTree *offspring_1, ASTree *offspring_2, ASTree *offspring_3);

#endif