
#include "astree.h"

#define MAX_PARAM_SIZE 30


int fun2type(int fun_type, int line);
int vec2scalar(int vec_type, int line);
int ptr2scalar(int ptr_type, int line);


void assign_types(ASTree *node);

void check_assignment_types(ASTree *node, ASTree *scope);

void semantic_analysis(ASTree *root);
