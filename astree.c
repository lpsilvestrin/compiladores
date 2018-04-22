

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

int decompile_tree(ASTree* tree, FILE *prog) {
	if (tree == NULL) {
		return 0;
	}
	switch(tree->type) {
		case AST_INITIAL:
			decompile_tree(tree->offspring[0], prog);
			fprintf(prog, ' ');	
			decompile_tree(tree->offspring[1], prog);
			break;
		case AST_GLOBAL_VAR_DEF:
			decompile_tree(tree->offspring[0], prog);
		case AST_VECTOR_DEF: break;
		case AST_INT: break;
		case AST_FUNCTION_DEF: break;
		case AST_HEADER: break;
		case AST_DEF_PARAM: break;
		case AST_DEF_PARAM_T: break;
		case AST_COMMANDS_L: break;
		case AST_VECTOR_AS: break;
		case AST_VAR_AS: break;
		case AST_READ: break;
		case AST_PRINT: break;
		case AST_NOT_EXP: break;
		case AST_NEG_EXP: break;
		case AST_PAR_EXP: break;
		case AST_PLUS_EXP: break;
		case AST_MINUS_EXP: break;
		case AST_MUL_EXP: break;
		case AST_DIV_EXP: break;
		case AST_LESS_EXP: break;
		case AST_GREAT_EXP: break;
		case AST_LE_EXP: break;
		case AST_GE_EXP: break;
		case AST_EQ_EXP: break;
		case AST_NE_EXP: break;
		case AST_AND_EXP: break;
		case AST_OR_EXP: break;
		case AST_ID: break;
		case AST_ID_POINTER: break;
		case AST_ID_ADDRESS: break;
		case AST_VECTOR: break;
		case AST_FUNCTION: break;
		case AST_PARAM: break;
		case AST_IF: break;
		case AST_IFELSE: break;
		case AST_FOR: break;
		case AST_WHILE: break;
		case AST_REAL: break;
		case AST_CHAR: break;
		case AST_INIT_VALUES: break;
		default: break;
	}
	return 0;
}
