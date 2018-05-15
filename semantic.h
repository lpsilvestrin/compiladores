
#include "astree.h"

void assign_types(ASTree *node);
int assert_type(ASTree *node, int type);
void semantic_analysis(ASTree *root);
void check_assignment_types(ASTree *node);
