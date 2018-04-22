

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

void print_astnode(ASTree* node, int level) {
	// print tree level indentation
	for(int i = 0; i < level; i++) {
		printf("-");
	}
	if(node->id != NULL)
		printf("%d, %s\n", node->type, node->id->id);
	for(int i = 0; i < MAX_OFFSPRING; i++) {
		if (node->offspring[i] != NULL) 
			print_astnode(node->offspring[i], level+1);
	}
}

void decompile_tree(ASTree* tree) {
	switch(tree->type) {
		case AST_GLOBAL_VAR_DEF:
		case AST_VECTOR_DEF:
		case AST_INT:
		case AST_FUNCTION_DEF:
		case AST_HEADER:
		case AST_DEF_PARAM:
		case AST_DEF_PARAM_T:
		case AST_COMMANDS_L:
		case AST_VECTOR_AS:
		case AST_VAR_AS:
		case AST_READ:
		case AST_PRINT:
		case AST_NOT_EXP:
		case AST_NEG_EXP:
		case AST_PAR_EXP:
		case AST_PLUS_EXP:
		case AST_MINUS_EXP:
		case AST_MUL_EXP:
		case AST_DIV_EXP:
		case AST_LESS_EXP:
		case AST_GREAT_EXP:
		case AST_LE_EXP:
		case AST_GE_EXP:
		case AST_EQ_EXP:
		case AST_NE_EXP:
		case AST_AND_EXP:
		case AST_OR_EXP:
		case AST_ID:
		case AST_ID_POINTER:
		case AST_ID_ADDRESS:
		case AST_VECTOR:
		case AST_FUNCTION:
		case AST_PARAM:
		case AST_IF:
		case AST_IFELSE:
		case AST_FOR:
		case AST_WHILE:
		case AST_REAL:
		case AST_CHAR:
		case AST_INIT_VALUES:
			printf(
		
		default: 
	}
}
