#ifndef _ASTREE_H
#define _ASTREE_H


#define MAX_OFFSPRING 4 //suggested by our teacher

/*here we will put a lot of defines with values for representing the possible types inside the AST*/


#include "hashtable.h"

typedef struct astree {
    int type; 
    hashNode *id; //pointer for the info inside our hash
    struct astree *offspring[MAX_OFFSPRING];
} ASTree;

ASTree* astree_create(int type, hashNode *id, ASTree *offspring_0, ASTree *offspring_1, ASTree *offspring_2, ASTree *offspring_3);

#endif