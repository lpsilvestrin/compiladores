#include <stdio.h>
#include <stdlib.h>
#include "astree.h"

extern int getLineNumber();

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
	node->line = getLineNumber();
    node->id = id;
    node->offspring[0] = offspring_0;
    node->offspring[1] = offspring_1;
    node->offspring[2] = offspring_2;
    node->offspring[3] = offspring_3;
    return node;
}


int decompile_tree(ASTree* tree, FILE *prog) {
	if (tree == NULL) {
		return 0;
	}
	ASTree *n1, *n2, *n3;//, *n4;
	n1 = tree->offspring[0];
	n2 = tree->offspring[1];
	n3 = tree->offspring[2];
	//n4 = tree->offspring[3];
	hashNode *id = tree->id;
	switch(tree->type) {
		case AST_GLOBAL:
			decompile_tree(n2, prog);
			fprintf(prog, " ");	
			decompile_tree(n1, prog);
			break;
		case AST_GLOBAL_VAR_DEF:
			print_symbol(n1->type, prog); // type
			fprintf(prog, " %s = ", id->id); // identifier
			decompile_tree(n2, prog); // value
			fprintf(prog, ";\n");
			break;
		case AST_GLOBAL_POINTER_DEF:
			print_symbol(n1->type, prog); // type
			fprintf(prog, " #%s = ", id->id); // identifier
			decompile_tree(n2, prog); // value
			fprintf(prog, ";\n");
			break;
		case AST_GLOBAL_VECTOR_DEF:
			print_symbol(n1->type, prog); // type
			fprintf(prog, " %s[", id->id); // identifier
			decompile_tree(n2, prog); // size
			fprintf(prog, "]");
			if (n3 != NULL) {
				fprintf(prog, " : ");
				decompile_tree(n3, prog); // value initialization
			}
			fprintf(prog, ";\n");
			break;
		case AST_FUNCTION_DEF: 
			decompile_tree(n1, prog); // function header
			//fprintf(prog, " {"); 
			//that's inside the block
			decompile_tree(n2, prog); // code block
			//fprintf(prog,"}\n");
			break;
		case AST_HEADER: 
			print_symbol(n1->type, prog); // function type
			fprintf(prog, " %s", id->id); // function name
			fprintf(prog, "("); // empty parameters
			//double ()
			if (n2 != NULL) {
				decompile_tree(n2, prog); //ast_def_param
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
		case AST_BLOCK:
			fprintf(prog, "{\n");
			if(n1!= NULL){
				decompile_tree(n1,prog);
			}
			fprintf(prog, "}\n");
			break;
		case AST_COMMANDS_L: 
			decompile_tree(n2,prog); // recursion to the list head
			fprintf(prog,";\n"); // << in the middle
			decompile_tree(n1,prog); // print command
			break;
		case AST_VECTOR_AS: 
			fprintf(prog, "%s[", id->id); // identifier
			decompile_tree(n1, prog); // position
			fprintf(prog, "] = ");
			decompile_tree(n2, prog); // assigned value
			break;
		case AST_VAR_AS:
			fprintf(prog, "%s = ", id->id); // identifier
			decompile_tree(n1, prog); // assigned value
			break;
		case AST_READ: 
			fprintf(prog,"read %s", id->id);
			break;
		case AST_PRINT: 
			if (n1 == NULL)
				fprintf(prog,"print ");
			if (n1 != NULL)	{ //first the recursion, then the value
				fprintf(prog," ");
				decompile_tree(n1,prog);
			}
			if (id != NULL) {	
				fprintf(prog," ");
				fprintf(prog,"%s", id->id);
			}
			if (n2 != NULL) {
				fprintf(prog," ");
				decompile_tree(n2,prog);
			}
			break;
		case AST_RETURN:
			fprintf(prog,"return ");
			decompile_tree(n1,prog); //expression
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
		case AST_ID: 
			if (id != NULL) // it should always be the case	
				fprintf(prog,"%s", id->id);
			break;
		case AST_ID_POINTER: 
			if (id != NULL) 	
				fprintf(prog,"#%s", id->id);
			break;
		case AST_ID_ADDRESS: 
			if (id != NULL) 
				fprintf(prog,"&%s", id->id);
			break;
		case AST_VECTOR: 
			if (id != NULL) {
				fprintf(prog,"%s[", id->id);
				decompile_tree(n1,prog); //expression
				fprintf(prog,"]");
			}
			break;
		case AST_FUNCTION: 
			if (id != NULL) 
				fprintf(prog,"%s", id->id);
			fprintf(prog, "(");
			if (n1 != NULL){
				
				decompile_tree(n1,prog); //parameters
			}
			fprintf(prog, ")");
			break;
		case AST_PARAM: 
			if(n1 != NULL) {
				decompile_tree(n1, prog);
				if(n2 != NULL) {
					fprintf(prog, ",");
					decompile_tree(n2, prog);
				}
			}
			break;
		case AST_IF:  //same for if and if then else
			fprintf(prog,"if (");
			if(n1 != NULL) {
				//fprintf(prog, "%d\n", n1->type);
				decompile_tree(n1,prog);
			}
			//else
			//	fprintf(prog, "N1 NULL\n");
			fprintf(prog,") then ");
			if(n2 != NULL)
				decompile_tree(n2,prog);
			if(n3 != NULL){
				fprintf(prog, " else ");
				decompile_tree(n3, prog);
			}
			break; 
		case AST_FOR: 
			fprintf(prog, "for (");
			if((id != NULL)&&(n1 != NULL)&&(n2 != NULL)&&(n3 != NULL)) {
				fprintf(prog, "%s = ", id->id);
				decompile_tree(n1, prog);
				fprintf(prog, " to ");
				decompile_tree(n2,prog);
				fprintf(prog, ") ");
				decompile_tree(n3, prog);
			}
			break;
		case AST_WHILE:  //KW_WHILE '(' expression ')' simple_command  {$$=astree_create(AST_WHILE,0,$3,$5,0,0);}
			fprintf(prog, "while");
			fprintf(prog,"(");
			if(n1 != NULL) {
				decompile_tree(n1,prog);
			} 
			fprintf(prog,") ");
			if(n2 != NULL) {

				decompile_tree(n2, prog);
			}
			break;
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
		//default: break;
	}
	return 0;
}

void print_astnode(ASTree* node) {
	int type = node->type;
    switch(type){
        case AST_GLOBAL: 
			fprintf(stderr, "AST_GLOBAL\n");
			break;
        case AST_GLOBAL_VAR_DEF: 
			fprintf(stderr, "AST_GLOBAL_VAR_DEF\n");
			break;
        case AST_GLOBAL_POINTER_DEF: 
			fprintf(stderr, "AST_GLOBAL_POINTER_DEF\n");
			break;
        case AST_GLOBAL_VECTOR_DEF: 
			fprintf(stderr, "AST_GLOBAL_VECTOR_DEF\n");
			break;
        case AST_FUNCTION_DEF: 
			fprintf(stderr, "AST_FUNCTION_DEF\n");
			break;
        case AST_DEF_PARAM: 
			fprintf(stderr, "AST_DEF_PARAM\n");
			break;
        case AST_DEF_PARAM_T: 
			fprintf(stderr, "AST_DEF_PARAM_T\n");
			break;
        case AST_BLOCK: 
			fprintf(stderr, "AST_BLOCK\n");
			break;
        case AST_COMMANDS_L: 
			fprintf(stderr, "AST_COMMANDS_L\n");
			break;
        case AST_VAR_AS: 
			fprintf(stderr, "AST_VAR_AS\n");
			break;
        case AST_VECTOR_AS: 
			fprintf(stderr, "AST_VECTOR_AS\n");
			break;
        case AST_READ: 
			fprintf(stderr, "AST_READ\n");
			break;
        case AST_PRINT: 
			fprintf(stderr, "AST_PRINT\n");
			break;
        case AST_RETURN: 
			fprintf(stderr, "AST_RETURN\n");
			break;
        case AST_NOT_EXP: 
			fprintf(stderr, "AST_NOT_EXP\n");
			break;
        case AST_NEG_EXP: 
			fprintf(stderr, "AST_NEG_EXP\n");
			break;
        case AST_PAR_EXP: 
			fprintf(stderr, "AST_PAR_EXP\n");
			break;
        case AST_PLUS_EXP: 
			fprintf(stderr, "AST_PLUS_EXP\n");
			break;
        case AST_MINUS_EXP: 
			fprintf(stderr, "AST_MINUS_EXP\n");
			break;
        case AST_MUL_EXP: 
			fprintf(stderr, "AST_MUL_EXP\n");
			break;
        case AST_DIV_EXP: 
			fprintf(stderr, "AST_DIV_EXP\n");
			break;
        case AST_LESS_EXP: 
			fprintf(stderr, "AST_LESS_EXP\n");
			break;
        case AST_GREAT_EXP: 
			fprintf(stderr, "AST_GREAT_EXP\n");
			break;
        case AST_LE_EXP: 
			fprintf(stderr, "AST_LE_EXP\n");
			break;
        case AST_GE_EXP: 
			fprintf(stderr, "AST_GE_EXP\n");
			break;
        case AST_EQ_EXP:
			fprintf(stderr, "AST_EQ_EXP\n");
			break;
        case AST_NE_EXP:
			fprintf(stderr, "AST_NE_EXP\n");
			break;
        case AST_AND_EXP:
			fprintf(stderr, "AST_AND_EXP\n");
			break;
        case AST_OR_EXP: 
			fprintf(stderr, "AST_OR_EXP\n");
			break;
        case AST_ID: 
			fprintf(stderr, "AST_ID\n");
			break;
        case AST_ID_POINTER: 
			fprintf(stderr, "AST_ID_POINTER\n");
			break;
        case AST_ID_ADDRESS: 
			fprintf(stderr, "AST_ID_ADDRESS\n");
			break;
        case AST_VECTOR_DEF: 
			fprintf(stderr, "AST_VECTOR_DEF\n");
			break;
        case AST_VECTOR: 
			fprintf(stderr, "AST_VECTOR\n");
			break;
        case AST_FUNCTION: 
			fprintf(stderr, "AST_FUNCTION\n");
			break;
        case AST_PARAM:
			fprintf(stderr, "AST_PARAM\n");
			break;
        case AST_IF: 
			fprintf(stderr, "AST_IF\n");
			break;
        case AST_FOR: 
			fprintf(stderr, "AST_FOR\n");
			break;
        case AST_WHILE: 
			fprintf(stderr, "AST_WHILE\n");
			break;
        case AST_INIT_VALUES: 
			fprintf(stderr, "AST_INIT_VALUES\n");
			break;
        case AST_INT_SYMBOL: 
			fprintf(stderr, "AST_INT_SYMBOL\n");
			break;
        case AST_FLOAT_SYMBOL: 
			fprintf(stderr, "AST_FLOAT_SYMBOL\n");
			break;
        case AST_CHAR_SYMBOL: 
			fprintf(stderr, "AST_CHAR_SYMBOL\n");
			break;
        case AST_INT:
			fprintf(stderr, "AST_INT\n");
			break;
        case AST_REAL: 
			fprintf(stderr, "AST_REAL\n");
			break;
        case AST_CHAR: 
            fprintf(stderr, "AST_CHAR\n");
            break;
        default: 
            fprintf(stderr, "ERROR\n");
            break;
    }
}
void debug_AST(ASTree *node){
    print_astnode(node);
    for(int i =0; i < MAX_OFFSPRING; i++){
        if(node->offspring[i] != NULL)
            debug_AST(node->offspring[i]);
    }

}