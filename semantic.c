
#include "astree.h"
#include "semantic.h"
#include "hashtable.h"

int fun2type(int fun_type, int line) {
	switch(fun_type) {
		case SYMBOL_FUN_CHAR: return SYMBOL_LIT_CHAR;
		case SYMBOL_FUN_INT: return SYMBOL_LIT_INT;
			case SYMBOL_FUN_FLOAT: return SYMBOL_LIT_FLOAT;
	}
	fprintf(stderr, "[SEMANTIC PROBLEM] line %d: Invalid function type\n", line-1);
	return -1;
}

int vec2scalar(int vec_type, int line) {
	switch(vec_type) {
		case SYMBOL_VEC_CHAR: return SYMBOL_LIT_CHAR;
		case SYMBOL_VEC_INT: return SYMBOL_LIT_INT;
			case SYMBOL_VEC_FLOAT: return SYMBOL_LIT_FLOAT;
	}
	fprintf(stderr, "[SEMANTIC PROBLEM] line %d: Invalid vector type\n", line-1);
	return -1;

}

int ptr2scalar(int ptr_type, int line) {
	switch(ptr_type) {
		case SYMBOL_PTR_CHAR: return SYMBOL_LIT_CHAR;
		case SYMBOL_PTR_INT: return SYMBOL_LIT_INT;
			case SYMBOL_PTR_FLOAT: return SYMBOL_LIT_FLOAT;
	}
	fprintf(stderr, "[SEMANTIC PROBLEM] line %d: Invalid pointer type\n", line-1);
	return -1;
}

int scalar2ptr(int scalar_type, int line) {
	switch(scalar_type) {
		case SYMBOL_LIT_CHAR: return SYMBOL_PTR_CHAR;
		case SYMBOL_LIT_INT: return SYMBOL_PTR_INT;
			case SYMBOL_LIT_FLOAT: return SYMBOL_PTR_FLOAT;
	}
	fprintf(stderr, "[SEMANTIC PROBLEM] line %d: Invalid scalar type on line\n", line-1);
	return -1;
}

int compat_types(int t1, int t2) { //returns (0,1) (false, true)
	int type;
	switch(t1) {
	case SYMBOL_LIT_INT:
		type = test_arit_type(t2);
		break;	
	case SYMBOL_LIT_CHAR:
		type = test_arit_type(t2);
		break;	
	case SYMBOL_LIT_FLOAT:
		type = test_arit_type(t2);
		break;
	case SYMBOL_PTR_INT:
		type = test_ptr_type(t2);
		break;	
	case SYMBOL_PTR_CHAR:
		type = test_ptr_type(t2);
		break;	
	case SYMBOL_PTR_FLOAT:
		type = test_ptr_type(t2);
		break;	
	}
	return type;
}







int assert_param_list_type(ASTree *node, ASTree *param_types, ASTree* scope) {
	int assert = 1;

	if (node == NULL) {
	// if both have empty parameters, return true
		if (param_types == NULL) 
			return 1;
		else // if one of them is empty and the other isn't, return false
			return 0;
	}
	if (param_types == NULL)
		return 0;
	int param_type = kw2type(param_types->offspring[0]->type);
	ASTree *exp, *list_rest;
	// test in which node of the parameter listthe expression is
	if (node->offspring[1] == NULL) {
		exp = node->offspring[0];
		list_rest = NULL;
	} else {
		exp = node->offspring[1];
		list_rest = node->offspring[0];
	}
	return (get_type(exp, scope) == param_type) &&
		assert_param_list_type(list_rest, param_types->offspring[1], scope); 
}

int get_from_scope(hashNode* id, ASTree *scope) {
	// if it is not in the scope, search in the hash (GLOBAL)
	if (scope == NULL) {
		return id->type; 
	}	
	
	char *param = scope->id->id;
	
	if (strcmp(id->id, param) == 0) {
		// if they match, return the type from the param_list type keyword
		return kw2type(scope->offspring[0]->type);
	} 
	// if dont match, look at the next parameter in the list
	return get_from_scope(id, scope->offspring[1]);
	
}

// convert type keywords to the respective type
int kw2type(int kw) {
	int type = -1; // invalid type
	switch(kw) {
	case AST_CHAR_SYMBOL: type = SYMBOL_LIT_CHAR;
		break;
	case AST_INT_SYMBOL: type = SYMBOL_LIT_INT;
		break;
	case AST_FLOAT_SYMBOL: type = SYMBOL_LIT_FLOAT;
		break;
	}
	return type;
}

int test_arit_type(int type) {
	return (type == SYMBOL_LIT_CHAR) || 
			(type == SYMBOL_LIT_INT) ||
			(type == SYMBOL_LIT_FLOAT);
}

int test_ptr_type(int type) {
	return (type == SYMBOL_PTR_CHAR) || 
			(type == SYMBOL_PTR_INT) ||
			(type == SYMBOL_PTR_FLOAT);
}






int get_type(ASTree *node, ASTree* scope) {
	int node_type = -1;
	int type = -1; // invalid type
	ASTree *n1 = node->offspring[0];
	ASTree *n2 = node->offspring[1];
	int tn1, tn2;
	//ASTree *n3 = node->offspring[2];
	if (node->id != NULL)
		node_type = get_from_scope(node->id, scope);
	switch(node->type) {
	case AST_CHAR:
		type = SYMBOL_LIT_CHAR;
		break;
	case AST_INT:
		type = SYMBOL_LIT_INT;
		break;
	case AST_REAL:
		type = SYMBOL_LIT_FLOAT;
		break;
	case AST_INIT_VALUES:
		// check the type of the list of init values
		// TODO: acho que isso não ta 100% certo
		tn1 = get_type(n1, scope);
		if (n2 != NULL)
			tn2 = get_type(n2, scope);
		if (tn1 == tn2)
			type = tn1;
		break;
	case AST_ID_POINTER:
		if (test_ptr_type(node_type))
			type = ptr2scalar(node_type, node->line);
		break;
	case AST_ID:
		type = node_type;
		break;
	case AST_ID_ADDRESS:
		if(test_arit_type(node_type))
			type = scalar2ptr(node_type, node->line);
		break;
	case AST_VECTOR:
		// test address type
		if (get_type(n1, scope) == SYMBOL_LIT_INT)
			type = vec2scalar(node_type, node->line);
				
		break; 
	case AST_FUNCTION:
		if (assert_param_list_type(n1, node->id->list_head, scope))
			type = fun2type(node_type, node->line);
		break; // TODO
	case AST_PARAM:

		break;
	case AST_NOT_EXP:
		if (get_type(n1, scope) == SYMBOL_LIT_BOOL)
			type = SYMBOL_LIT_BOOL;	
		break;
	case AST_NEG_EXP:
		tn1 = get_type(n1, scope);
		if (test_arit_type(tn1))
			type = tn1;
		break;
	case AST_MUL_EXP:
	case AST_DIV_EXP:
		tn1 = get_type(n1, scope);
		tn2 = get_type(n2, scope);
		if (test_arit_type(tn1) && test_arit_type(tn2))
			type = tn1;
		break;
	case AST_PAR_EXP:
		type = get_type(n1, scope);
		break;
	case AST_MINUS_EXP:
	case AST_PLUS_EXP:
		tn1 = get_type(n1, scope);
		tn2 = get_type(n2, scope);
		if (test_arit_type(tn1))
			if (test_ptr_type(tn2) || test_ptr_type(tn2))
				type = tn2;
		else if (test_ptr_type(tn1) && test_arit_type(tn2))
			type = tn1;
		break;
	case AST_LESS_EXP:
	case AST_GREAT_EXP:
	case AST_GE_EXP:
	case AST_EQ_EXP:
	case AST_NE_EXP:
	case AST_LE_EXP:
		tn1 = get_type(n1, scope);
		tn2 = get_type(n2, scope);
		if (test_arit_type(tn1) &&
			test_arit_type(tn2))
			type = SYMBOL_LIT_BOOL;
		break;
	case AST_AND_EXP:
	case AST_OR_EXP:
		tn1 = get_type(n1, scope);
		tn2 = get_type(n2, scope);
		if (tn1 == SYMBOL_LIT_BOOL &&
			tn2 == SYMBOL_LIT_BOOL)
			type = SYMBOL_LIT_BOOL;
		break;
	/*case AST_IF:
		assert = assert_type(n1, SYMBOL_LIT_BOOL, scope);
		//assert = assert && assert_type(n2, 0, scope);
		//if (n3 != NULL)
			//assert = assert && assert_type(n3, 0,scope);
		break;
	case AST_WHILE:
		assert = assert_type(n1, SYMBOL_LIT_BOOL, scope);
		//assert = assert && assert_type(n2, 0, scope);
		break;
	case AST_FOR:
		assert = (node_type == SYMBOL_LIT_INT);
		assert = assert && assert_type(n1, SYMBOL_LIT_INT, scope);
		assert = assert && assert_type(n2, SYMBOL_LIT_INT, scope);
		//assert = assert && assert_type(n3, 0, scope);
		break;*/
	default:
		break;
	}
	return type;
}


/*Assignment functions*/

void assign_fun_type(ASTree *node){ 
	ASTree *block = node->offspring[1]; //saves the block
	node = node->offspring[0]; //goes to the header
	if(node->id->type == SYMBOL_IDENTIFIER){ //not assigned
		int type = node->offspring[0]->type;
		switch(type){
			case AST_CHAR_SYMBOL: 
			node->id->type = SYMBOL_FUN_CHAR;
			break;
			case AST_INT_SYMBOL: 
			node->id->type = SYMBOL_FUN_INT;
			break;
			case AST_FLOAT_SYMBOL: 
			node->id->type = SYMBOL_FUN_FLOAT;
			break;
			default: 
			fprintf(stderr, "[SEMANTIC] INTERNAL ERROR \n");
			break;
		}
		fprintf(stderr, "[SEMANTIC] line %d: Changing variable %s type: ", node->line, node->id->id);
		print_type(node->id);
	} else{
		fprintf(stderr, "[SEMANTIC PROBLEM] line %d: Function %s already declared with type: ", node->line, node->id->id);
		print_type(node->id);
	}

	ASTree *old = node; //old = header
	if(node->offspring[1] != NULL) {//check parameters
		node = node->offspring[1];
		hashTable *params;
		initHash(&params, MAX_PARAM_SIZE);
		do{
			hashNode *n;
			initNode(&n);
			strcpy(n->id, node->id->id); // atribuindo identificador como key
			n->type = node->id->type;
			hashNode* res =insertHash(n, params);
			if (res != n) {
				free(n);
				fprintf(stderr, "[SEMANTIC PROBLEM] line %d on function %s: parameter %s was declared twice.\n", node->line, old->id->id, node->id->id);
				break;
			}
			node = node->offspring[1];
		}while(node != NULL);
		printHash(params);
		free(params);
	}
	//check assignments
	check_assignment_types(block, old->id->list_head);
}

void assign_var_type(ASTree *node) {
	int type;
	if(node->id->type == SYMBOL_IDENTIFIER){ //not assigned
		type = node->offspring[0]->type;
		switch(type){
			case AST_CHAR_SYMBOL: 
			node->id->type = SYMBOL_LIT_CHAR;
			break;
			case AST_INT_SYMBOL: 
			node->id->type = SYMBOL_LIT_INT;
			break;
			case AST_FLOAT_SYMBOL: 
			node->id->type = SYMBOL_LIT_FLOAT;
			break;
			default: 
			fprintf(stderr, "[SEMANTIC] INTERNAL ERROR \n");
			break;
		}
	fprintf(stderr, "[SEMANTIC] line %d: Changing variable %s type: ", node->line, node->id->id);
	print_type(node->id);
	} else{
		fprintf(stderr, "[SEMANTIC PROBLEM] line %d: Variable %s already declared with type: ", node->line, node->id->id);
		print_type(node->id);
	}
	type = kw2type(type);
	if(assert_type(node->offspring[1],type,NULL) == 0) {
		fprintf(stderr, "[SEMANTIC PROBLEM] line %d: Incorrect initialization value for variable %s\n", node->line, node->id->id);
		}
}

void assign_pointer_type(ASTree *node) {
	int type;
	if(node->id->type == SYMBOL_IDENTIFIER){ //not assigned
		type = node->offspring[0]->type;
		switch(type){
			case AST_CHAR_SYMBOL: 
				node->id->type = SYMBOL_PTR_CHAR;
				break;
			case AST_INT_SYMBOL: 
				node->id->type = SYMBOL_PTR_INT;
				break;
		   case AST_FLOAT_SYMBOL: 
				node->id->type = SYMBOL_PTR_FLOAT;
				break;
			default: 
				fprintf(stderr, "[SEMANTIC] INTERNAL ERROR \n");
				break;
		}
		fprintf(stderr, "[SEMANTIC] line %d: Changing pointer %s type: ", node->line, node->id->id);
		print_type(node->id);
	} else{
		fprintf(stderr, "[SEMANTIC PROBLEM] line %d: Pointer %s already declared with type: ", node->line, node->id->id);
		print_type(node->id);
	}
	type = kw2type(type);
	if(assert_type(node->offspring[1],type,NULL) == 0) {
		fprintf(stderr, "[SEMANTIC PROBLEM] line %d: Incorrect initialization value for pointer %s\n", node->line, node->id->id);
		}
}

int assert_type(ASTree *node, int type, ASTree* scope){

}

void assign_vector_type(ASTree *node) {
	int type;
	if(node->id->type == SYMBOL_IDENTIFIER){ //not assigned
		type = node->offspring[0]->type;
		switch(type){
			case AST_CHAR_SYMBOL: 
				node->id->type = SYMBOL_VEC_CHAR;
				break;
			case AST_INT_SYMBOL: 
				node->id->type = SYMBOL_VEC_INT;
				break;
		   case AST_FLOAT_SYMBOL: 
				node->id->type = SYMBOL_VEC_FLOAT;
				break;
			default: 
				fprintf(stderr, "[SEMANTIC] INTERNAL ERROR \n");
				break;
		}
		fprintf(stderr, "[SEMANTIC] line %d: Changing vector %s type: ", node->line, node->id->id);
		print_type(node->id);
	} else{
		fprintf(stderr, "[SEMANTIC PROBLEM] line %d: Vector %s already declared with type: ", node->line, node->id->id);
	}
	int size_type = node->offspring[1]->type;
	if(size_type != AST_INT) {
		fprintf(stderr, "[SEMANTIC PROBLEM] line %d: Vector must have an integer as size. Given type ", node->line);
		print_type(node->id);
	}

	if(node->offspring[2] != NULL) { //there are init values 
		type = kw2type(type);
		int init_values_type = get_type(node->offspring[2], NULL);
		if(type != init_values_type) {
			fprintf(stderr, "[SEMANTIC PROBLEM] line %d: Incorrect initialization value to vector %s\n", node->line, node->id->id);
		}
	}
}


void assign_types(ASTree *node) {
    print_astnode(node); //for debug sake
	switch(node->type) {
	case AST_FUNCTION_DEF: //function
		assign_fun_type(node);
		break;
   	case AST_GLOBAL_VAR_DEF:
        assign_var_type(node);
		break;
    case AST_GLOBAL_VECTOR_DEF:
		assign_vector_type(node);
		break;
	case AST_GLOBAL_POINTER_DEF:
		assign_pointer_type(node);
		break;
    default:
		break;
    }
    //recursion
    for(int i =MAX_OFFSPRING-1; i >= 0; i--){
        if(node->offspring[i] != NULL)
            assign_types(node->offspring[i]);
    }
}


void check_assignment_types(ASTree *node, ASTree *scope) {
    print_astnode(node); //for debug sake
	int type;
	switch(node->type) {
		case AST_VECTOR_AS:  //{$$=astree_create(AST_VECTOR_AS,$1,$3,$6,0,0);}
			if(node->id == NULL){
				fprintf(stderr, "RIP OUR HASH\n");
			}
			fprintf(stderr, "get from scope\n");
			type = get_from_scope(node->id, scope);
			if(assert_type(node->offspring[1],type,scope) == 0) {
			fprintf(stderr, "[SEMANTIC PROBLEM] line %d: Incorrect assignment value to vector %s\n", node->line, node->id->id);
			}
			break;
		case AST_VAR_AS: //{$$=astree_create(AST_VAR_AS,$1,$3,0,0,0);}
			if(node->id == NULL){
				fprintf(stderr, "RIP OUR HASH\n");
			}
			fprintf(stderr, "get from scope\n");
			type = get_from_scope(node->id, scope);
			if(assert_type(node->offspring[0],type,scope) == 0) {
			fprintf(stderr, "[SEMANTIC PROBLEM] line %d: Incorrect assignment value to variable %s\n", node->line, node->id->id);
			}
			break;
		default: break;
	}
    //recursion
    for(int i =MAX_OFFSPRING-1; i >= 0; i--){
        if(node->offspring[i] != NULL)
            check_assignment_types(node->offspring[i], scope);
    }

}


//1: check assignments
//2: check if int var = X x = int type
//3: check if var[] -> var = array type; var(la,la,la) -> var = function type
void semantic_analysis(ASTree *root) {
    assign_types(root);
}









/////////////// TRASH



/*
int assert_arit_type(ASTree *node, ASTree *scope) {
	return assert_type(node, SYMBOL_LIT_INT, scope)
		|| assert_type(node, SYMBOL_LIT_CHAR, scope)
		|| assert_type(node, SYMBOL_LIT_FLOAT, scope);
}

int assert_ptr_type(ASTree *node, ASTree *scope) {
	return assert_type(node, SYMBOL_PTR_INT, scope)
		|| assert_type(node, SYMBOL_PTR_CHAR, scope)
		|| assert_type(node, SYMBOL_PTR_FLOAT, scope);
}
*/

