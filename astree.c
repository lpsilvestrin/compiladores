

#include <stdio.h>
#include <stdlib.h>
#include "astree.h"


ASTree* astree_create(int type, hashNode *id, ASTree *offspring_0, ASTree *offspring_1, ASTree *offspring_2, ASTree *offspring_3){
    ASTree *node = (ASTree*)malloc(sizeof(ASTree));
    node->type = type;
    node->id = id;
    node->offspring[0] = offspring_0;
    node->offspring[1] = offspring_1;
    node->offspring[2] = offspring_2;
    node->offspring[3] = offspring_3;
    return node;
}

