#ifndef _ASTREE_H
#define _ASTREE_H


#define MAX_OFFSPRING 4 //suggested by our teacher

#include "hashtable.h"

typedef struct astree_node {
    int type; 
    hashNode * symbol; //pointer for the info inside our hash
    struct astree_node *offspring[MAX_OFFSPRING];
} ASTree;

#endif