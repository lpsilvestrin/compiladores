#include <stdio.h>
#include <stdlib.h>
#include "astree.h"
#include "ast_ids.h"

void print_binary_op(char* op, ASTree* n1, ASTree *n2, FILE* prog) {
	decompile_tree(n1,prog);
	fprintf(prog, "%s", op);
	decompile_tree(n2,prog);
	
}

void print_symbol(int s, FILE* prog) {
	switch(s) {
		case AST_INT_SYMBOL:
			fprintf(prog, "int");
			break;
		case AST_FLOAT_SYMBOL:
			fprintf(prog, "float");
			break;
		case AST_CHAR_SYMBOL:
			fprintf(prog, "char");
			break;
	}
}

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
	// tree recursion from right to the left
	for(int i = MAX_OFFSPRING-1; i >= 0; i--) {
		if (node->offspring[i] != NULL) 
			print_astnode(node->offspring[i], level+1);
	}
}

int decompile_tree(ASTree* tree, FILE *prog) {
	if (tree == NULL) {
		return 0;
	}
	ASTree *n1, *n2, *n3, *n4;
	n1 = tree->offspring[0];
	n2 = tree->offspring[1];
	n3 = tree->offspring[2];
	n4 = tree->offspring[3];
	hashNode *id = tree->id;
	switch(tree->type) {
		case AST_INITIAL:
			decompile_tree(n2, prog);
			fprintf(prog, " ");	
			decompile_tree(n1, prog);
			break;
		case AST_GLOBAL_VAR_DEF:
			print_symbol(n1->type, prog); // type
			fprintf(prog, " %s = ", id->id); // identifier
			decompile_tree(n2, prog); // value
			fprintf(prog, ";");
			break;
		case AST_GLOBAL_POINTER_DEF:
			print_symbol(n1->type, prog); // type
			fprintf(prog, " #%s = ", id->id); // identifier
			decompile_tree(n2, prog); // value
			fprintf(prog, ";");
			break;
		case AST_VECTOR_DEF:
			print_symbol(n1->type, prog); // type
			fprintf(prog, " #%s[", id->id); // identifier
			decompile_tree(n2, prog); // size
			fprintf(prog, "]");
			if (n3 != NULL) {
				fprintf(prog, " : ");
				decompile_tree(n3, prog); // value initialization
			}
			fprintf(prog, ";");
			 
			break;
		case AST_FUNCTION_DEF: 
			decompile_tree(n1, prog); // function header
			fprintf(prog, " {");
			decompile_tree(n2, prog); // code block
			fprintf(prog,"}\n");
			break;
		case AST_HEADER: 
			print_symbol(n1->type, prog); // function type
			fprintf(prog, " %s ", id->id); // function name
			fprintf(prog, "("); // empty parameters
			if (n2 != NULL) {
				decompile_tree(n2, prog);
			}
			fprintf(prog, ")"); // empty parameters
			break;
		case AST_DEF_PARAM: // not used 
			fprintf(prog,"(");
			decompile_tree(n1,prog);
			fprintf(prog,")");
			break;
		case AST_DEF_PARAM_T: 
			if (n2 != NULL) {
				decompile_tree(n2, prog);
				fprintf(prog,",");
			}
			print_symbol(n1->type, prog);	
			fprintf(prog, " %s ", id->id);

			break;
		case AST_COMMANDS_L: 
			decompile_tree(n2,prog); // recursion to the list head
			decompile_tree(n1,prog); // print command
			fprintf(prog,";\n");
			break;
		case AST_VECTOR_AS: 
			fprintf(prog, " %s[", id->id); // identifier
			decompile_tree(n1, prog); // position
			fprintf(prog, "] = ");
			decompile_tree(n3, prog); // assigned value
			break;
		case AST_VAR_AS:
			fprintf(prog, " %s = ", id->id); // identifier
			decompile_tree(n1, prog); // assigned value
			break;
		case AST_READ: 
			fprintf(prog,"read %s", id->id);
			break;
		case AST_PRINT: 
			fprintf(prog,"print ");
			if (id != NULL)	
				fprintf(prog,"%s", id->id);
			if (n1 != NULL)	
				decompile_tree(n1,prog);
			break;
		case AST_RETURN:
			fprintf(prog,"return ");
			decompile_tree(n1,prog);
			break;
		case AST_NOT_EXP: 
			fprintf(prog,"!");
			decompile_tree(n1,prog);
			break;
		case AST_NEG_EXP: 
			fprintf(prog,"-");
			decompile_tree(n1,prog);
			break;
		case AST_PAR_EXP:
			fprintf(prog,"(");
			decompile_tree(n1,prog);
			fprintf(prog,")");
			break;
		case AST_PLUS_EXP:
			break;
			print_binary_op(" + ",n1,n2,prog);
			break;
		case AST_MINUS_EXP: 
			print_binary_op(" - ",n1,n2,prog);
			break;
		case AST_MUL_EXP:
			print_binary_op(" * ",n1,n2,prog);
			break;
		case AST_DIV_EXP:
			print_binary_op(" / ",n1,n2,prog);
			break;
		case AST_LESS_EXP:
			print_binary_op(" < ",n1,n2,prog);
			break;
		case AST_GREAT_EXP:
			print_binary_op(" > ",n1,n2,prog);
			break;
		case AST_LE_EXP:
			print_binary_op(" <= ",n1,n2,prog);
			break;
		case AST_GE_EXP:
			print_binary_op(" >= ",n1,n2,prog);
			break;
		case AST_EQ_EXP:
			print_binary_op(" == ",n1,n2,prog);
			break;
		case AST_NE_EXP:
			print_binary_op(" != ",n1,n2,prog);
			break;
		case AST_AND_EXP:
			print_binary_op(" && ",n1,n2,prog);
			break;
		case AST_OR_EXP:
			print_binary_op(" || ",n1,n2,prog);
			break;
		case AST_ID: break;
		case AST_ID_POINTER: break;
		case AST_ID_ADDRESS: break;
		case AST_VECTOR: break;
		case AST_FUNCTION: break;
		case AST_PARAM: break;
		case AST_IF: break; //same for if and if then else
		case AST_FOR: break;
		case AST_WHILE: break;
		case AST_REAL: // same behaviour for all literals 
		case AST_INT:
		case AST_CHAR: 
			fprintf(prog, "%s", tree->id->id);
			break;
		case AST_INIT_VALUES: 
			// start recursion to the left
			decompile_tree(n1, prog);
			fprintf(prog, " ");
			decompile_tree(n2, prog);
			break;
		default: break;
	}
	return 0;
}
