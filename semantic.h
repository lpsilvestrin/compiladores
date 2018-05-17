
#include "astree.h"

#define MAX_PARAM_SIZE 30


int fun2type(int fun_type, int line);
int vec2scalar(int vec_type, int line);
int ptr2scalar(int ptr_type, int line);
int scalar2ptr(int scalar_type, int line);
int kw2type(int kw);
int compat_types(int t1, int t2);
int assert_param_list_type(ASTree *node, ASTree *param_types, ASTree* scope);
int get_from_scope(hashNode* id, ASTree *scope);
int test_arit_type(int type);
int test_ptr_type(int type);
int get_type(ASTree *node, ASTree* scope);
void assign_fun_type(ASTree *node);
void assign_var_type(ASTree *node);
void assign_pointer_type(ASTree *node);
void assign_vector_type(ASTree *node);
void check_commands(ASTree *node, ASTree *scope);
void semantic_analysis(ASTree *node);
