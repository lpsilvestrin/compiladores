#ifndef _ASTREE_H
#define _ASTREE_H


#define MAX_OFFSPRING 4 //suggested by our teacher

#include "hashtable.h"

typedef struct astree {
    int type; 
    hashNode * symbol; //pointer for the info inside our hash
    struct astree *offspring[MAX_OFFSPRING];
} ASTree;

void initASTree();

#endif