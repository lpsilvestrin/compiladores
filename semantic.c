#include "astree.h"
#include "semantic.h"
#include "hashtable.h"

int _SEMANTIC_ERROR = 0;

int fun2type(int fun_type, int line) {
	switch(fun_type) {
		case SYMBOL_FUN_CHAR: return SYMBOL_LIT_CHAR;
		case SYMBOL_FUN_INT: return SYMBOL_LIT_INT;
			case SYMBOL_FUN_FLOAT: return SYMBOL_LIT_FLOAT;
	}
	fprintf(stderr, "[SEMANTIC PROBLEM] line %d: Invalid function type\n", line);
	_SEMANTIC_ERROR = 1;
	return -1;
}

int vec2scalar(int vec_type, int line) {
	switch(vec_type) {
		case SYMBOL_VEC_CHAR: return SYMBOL_LIT_CHAR;
		case SYMBOL_VEC_INT: return SYMBOL_LIT_INT;
			case SYMBOL_VEC_FLOAT: return SYMBOL_LIT_FLOAT;
	}
	fprintf(stderr, "[SEMANTIC PROBLEM] line %d: Invalid vector type\n", line);
	_SEMANTIC_ERROR = 1;
	return -1;

}

int ptr2scalar(int ptr_type, int line) {
	switch(ptr_type) {
		case SYMBOL_PTR_CHAR: return SYMBOL_LIT_CHAR;
		case SYMBOL_PTR_INT: return SYMBOL_LIT_INT;
			case SYMBOL_PTR_FLOAT: return SYMBOL_LIT_FLOAT;
	}
	fprintf(stderr, "[SEMANTIC PROBLEM] line %d: Invalid pointer type\n", line);
	_SEMANTIC_ERROR = 1;
	return -1;
}

int scalar2ptr(int scalar_type, int line) {
	switch(scalar_type) {
		case SYMBOL_LIT_CHAR: return SYMBOL_PTR_CHAR;
		case SYMBOL_LIT_INT: return SYMBOL_PTR_INT;
			case SYMBOL_LIT_FLOAT: return SYMBOL_PTR_FLOAT;
	}
	fprintf(stderr, "[SEMANTIC PROBLEM] line %d: Invalid scalar type on line\n", line);
	_SEMANTIC_ERROR = 1;
	return -1;
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
	if (node == NULL) {
		// if both have empty parameters, return true
		if (param_types == NULL) 
			return 1;
		else { // if one of them is empty and the other isn't, return false
			return 0;
		}
	}
	if (param_types == NULL) 
		return 0;
	int param_type = kw2type(param_types->offspring[0]->type);
	ASTree *exp, *list_rest;
	// test in which node of the parameter list the expression is
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

void check_undeclared(int line, hashNode* var) {
	fprintf(stderr, "[SEMANTIC PROBLEM] line %d, %s wasn't declared previously\n", line, var->id);
	_SEMANTIC_ERROR = 1;

}

int get_type(ASTree *node, ASTree* scope) {
	int hash_node_type = -1;
	int type = -1; // invalid type
	ASTree *n1 = node->offspring[0];
	ASTree *n2 = node->offspring[1];
	int tn1, tn2;
	if(node == NULL) { 
		fprintf(stderr, "[SEMANTIC] INTERNAL ERROR: get_type with NULL node\n");
		return type;
	} 
	if (node->id != NULL) {
		hash_node_type = get_from_scope(node->id, scope);
	}

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
		tn1 = get_type(n1, scope); 
		if (n2 != NULL) {
			tn2 = get_type(n2, scope);
			if (test_arit_type(tn1)&&(test_arit_type(tn2)))//(tn1 == tn2)
				type = tn1;
		} else {
			type = tn1;
		}
		break;
	case AST_ID_POINTER:
		if (test_ptr_type(hash_node_type))
			type = ptr2scalar(hash_node_type, node->line);
		break;
	case AST_ID:
		if (hash_node_type == SYMBOL_IDENTIFIER) {
			check_undeclared(node->line, node->id);
		}
		type = hash_node_type;
		break;
	case AST_ID_ADDRESS:
		if (hash_node_type == SYMBOL_IDENTIFIER) {
			check_undeclared(node->line, node->id);
		}
		if(test_arit_type(hash_node_type))
			type = scalar2ptr(hash_node_type, node->line);
		break;
	case AST_VECTOR:
		if (hash_node_type == SYMBOL_IDENTIFIER) {
			check_undeclared(node->line, node->id);
		}
		// test index type
		if (get_type(n1, scope) != SYMBOL_LIT_INT)
			fprintf(stderr, "[SEMANTIC PROBLEM] line %d: invalid vector index\n", node->line);
		type = vec2scalar(hash_node_type, node->line);
		break; 
	case AST_FUNCTION:
		if (!assert_param_list_type(n1, node->id->list_head, scope)) {
			fprintf(stderr, "[SEMANTIC PROBLEM] line %d: fuction %s called with incorrect parameters\n", node->line, node->id->id);
			_SEMANTIC_ERROR = 1;
		}		
		type = fun2type(hash_node_type, node->line);
		break; 
	case AST_NOT_EXP:
		tn1 = get_type(n1, scope);
		if (tn1 == SYMBOL_LIT_BOOL)
			fprintf(stderr, "[SEMANTIC PROBLEM] line %d: ! operator expects BOOL expression\n", node->line);
				
		type = SYMBOL_LIT_BOOL;
		break;
	case AST_NEG_EXP:
		tn1 = get_type(n1, scope);
		if (test_arit_type(tn1))
			type = tn1;
		if (tn1 == -1)
			type = SYMBOL_LIT_FLOAT;
		break;
	case AST_MUL_EXP:
	case AST_DIV_EXP:
		tn1 = get_type(n1, scope);
		tn2 = get_type(n2, scope);
		if (test_arit_type(tn1) && test_arit_type(tn2))
			type = tn1;
		if (tn1 == -1 || tn2 == -1)
			type = SYMBOL_LIT_FLOAT;
		break;
	case AST_PAR_EXP: // ()
		type = get_type(n1, scope);
		break;
	case AST_MINUS_EXP:
	case AST_PLUS_EXP:
		tn1 = get_type(n1, scope);
		tn2 = get_type(n2, scope);
		if (test_arit_type(tn1)) {
			if (test_arit_type(tn2) || test_ptr_type(tn2))
				type = tn2;
		}
		else {
		if (test_ptr_type(tn1) && test_arit_type(tn2))
			type = tn1;
		} 
		if (tn1 == -1 || tn2 == -1)
			type = SYMBOL_LIT_FLOAT;
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
		if (tn1 == -1 || tn2 == -1)
			type = SYMBOL_LIT_BOOL;
		break;
	case AST_AND_EXP:
	case AST_OR_EXP:
		tn1 = get_type(n1, scope);
		tn2 = get_type(n2, scope);
		if (tn1 == SYMBOL_LIT_BOOL &&
			tn2 == SYMBOL_LIT_BOOL)
			type = SYMBOL_LIT_BOOL;
		if (tn1 == -1 || tn2 == -1)
			type = SYMBOL_LIT_BOOL;
		break;
	default:
		break;
	}
	return type;
}

void assign_fun_type(ASTree *node){  
	//ASTree *block = node->offspring[1]; //saves the block
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
		//fprintf(stderr, "[SEMANTIC] line %d: Changing variable %s type: ", node->line, node->id->id);
		//print_type(node->id);
	} else{
		fprintf(stderr, "[SEMANTIC PROBLEM] line %d: Function %s already declared with type: ", node->line, node->id->id);
		_SEMANTIC_ERROR = 1;
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
				_SEMANTIC_ERROR = 1;
				break;
			}
			node = node->offspring[1];
		}while(node != NULL);
		//printHash(params);
		free(params);
	}
	//check what's inside
	//check_commands(block, old->id->list_head);
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
	//fprintf(stderr, "[SEMANTIC] line %d: Changing variable %s type: ", node->line, node->id->id);
	//print_type(node->id);
	} else{
		fprintf(stderr, "[SEMANTIC PROBLEM] line %d: Variable %s already declared with type: ", node->line, node->id->id);
		_SEMANTIC_ERROR = 1;
		print_type(node->id);
	}
	//type = kw2type(type);
	int assignment = get_type(node->offspring[1], NULL);
	if(!test_arit_type(assignment)) {
	//if(type != assignment) {
		fprintf(stderr, "[SEMANTIC PROBLEM] line %d: Incorrect initialization value for variable %s\n", node->line, node->id->id);
		_SEMANTIC_ERROR = 1;
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
		//fprintf(stderr, "[SEMANTIC] line %d: Changing pointer %s type: ", node->line, node->id->id);
		//print_type(node->id);
	} else{
		fprintf(stderr, "[SEMANTIC PROBLEM] line %d: Pointer %s already declared with type: ", node->line, node->id->id);
		_SEMANTIC_ERROR = 1;
		print_type(node->id);
	}
	type = kw2type(type);
	int assignment = get_type(node->offspring[1], NULL);
	if(type != assignment) {
		fprintf(stderr, "[SEMANTIC PROBLEM] line %d: Incorrect initialization value for pointer %s\n", node->line, node->id->id);
		_SEMANTIC_ERROR = 1;
		}
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
		//fprintf(stderr, "[SEMANTIC] line %d: Changing vector %s type: ", node->line, node->id->id);
		//print_type(node->id);
	} else{
		fprintf(stderr, "[SEMANTIC PROBLEM] line %d: Vector %s already declared with type: ", node->line, node->id->id);
		_SEMANTIC_ERROR = 1;
	}
	int size_type = node->offspring[1]->type;
	if(size_type != AST_INT) {
		fprintf(stderr, "[SEMANTIC PROBLEM] line %d: Vector must have an integer as size. Given type ", node->line);
		_SEMANTIC_ERROR = 1;
		print_type(node->offspring[1]->id);
	}
	if(node->offspring[2] != NULL) { //there are init values 
		//type = kw2type(type);
		int init_values_type = get_type(node->offspring[2], NULL);
		if(!test_arit_type(init_values_type)) {
			fprintf(stderr, "[SEMANTIC PROBLEM] line %d: Incorrect initialization value to vector %s\n", node->line, node->id->id);
			_SEMANTIC_ERROR = 1;
		}
	}
}

void check_commands(ASTree *node, ASTree *scope) {
    //print_astnode(node); //for debug sake
	int type;
	int assignment;
	ASTree *n1, *n2, *n3;
	switch(node->type) {
		case AST_BLOCK:
			n1 = node->offspring[0];
			if (n1 != NULL)
				check_commands(node->offspring[0], scope);
			break;
		case AST_COMMANDS_L:
			n1 = node->offspring[0];
			n2 = node->offspring[1];
			if (n2 != NULL)
				check_commands(n2, scope);
			if (n1 != NULL)
				check_commands(n1, scope);
			break;
		case AST_VECTOR_AS:  //{$$=astree_create(AST_VECTOR_AS,$1,$3,$6,0,0);}
			if(node->id == NULL){
				fprintf(stderr, "RIP OUR HASH\n");
				break;
			}
			// get the scalar type of the vector
			type = vec2scalar(get_from_scope(node->id, scope), node->line);
			if(type == -1) {
				fprintf(stderr, "[SEMANTIC PROBLEM] line %d: %s undeclared \n", node->line, node->id->id);
				_SEMANTIC_ERROR = 1;
			}
			// check index type
			if (get_type(node->offspring[0], scope) != SYMBOL_LIT_INT) {
				fprintf(stderr, "[SEMANTIC PROBLEM] line %d: incorrect index type", node->line);
				_SEMANTIC_ERROR = 1;
			}
			//check the assignment
			assignment = get_type(node->offspring[1], scope);
			if(!test_arit_type(assignment)) {
				fprintf(stderr, "[SEMANTIC PROBLEM] line %d: Incorrect assignment value for vector %s\n", node->line, node->id->id);
				_SEMANTIC_ERROR = 1;
			}
			
			break;
		case AST_VAR_AS: //{$$=astree_create(AST_VAR_AS,$1,$3,0,0,0);}
			if(node->id == NULL){
				fprintf(stderr, "RIP OUR HASH\n");
				break;
			}
			//type = kw2type(node->type);
			//type = get_from_scope(node->id, scope);
			assignment = get_type(node->offspring[0], scope);
			if(!test_arit_type(assignment)) {
			//if(type != assignment) {
				fprintf(stderr, "[SEMANTIC PROBLEM] line %d: Incorrect assignment value for variable %s\n", node->line, node->id->id);
				_SEMANTIC_ERROR = 1;
			}
			break;
		case AST_READ:  //scalar value
			if(node == NULL){
				fprintf(stderr, "[SEMANTIC] INTERNAL PROBLEM: AST_READ null node\n");
				break;
			}
			type = get_from_scope(node->id, scope); //must be an scalar
			if(!test_arit_type(type)){
				fprintf(stderr, "[SEMANTIC PROBLEM] line %d: read function variable type must be scalar.\n", node->line);
				_SEMANTIC_ERROR = 1;
				break;
			}
			break;
		case AST_PRINT: // arithmetic expression OR string
			if(node == NULL){
				fprintf(stderr, "[SEMANTIC] INTERNAL PROBLEM: AST_PRINT null node\n");
				break;
			}
			n1 = node->offspring[0];
			n2 = node->offspring[1];
			
			// print can't have both id and n2 null	
			if (node->id == NULL && n2 == NULL) {
				fprintf(stderr, "[SEMANTIC] INTERNAL PROBLEM: AST_PRINT null node\n");
				break;
			}
			if(node->id != NULL){ //
				if (node->id->type != SYMBOL_LIT_STRING) {
						fprintf(stderr, "[SEMANTIC] line %d: invalid parameter to print\n", node->line);
						break;
				}
			}
			if (n2 != NULL) {
				type = get_type(n2, scope);
				if(!test_arit_type(type)){
					fprintf(stderr, "[SEMANTIC PROBLEM] line %d: print function accepts string and arihtmetic value.\n", node->line);
					_SEMANTIC_ERROR = 1;
					break;
				}
			}
			if(n1 != NULL) { // end of recursion
				check_commands(n1, scope);
			}

			
			/*print_c: 
    		KW_PRINT                {$$=0;} //it does not save tokens and intermediate productions 
    		| print_c LIT_STRING    {$$=astree_create(AST_PRINT,$2,$1,0,0,0);}
			| print_c expression    {$$=astree_create(AST_PRINT,0,$1,$2,0,0);}
			;
			*/
			 break; 
		case AST_RETURN: //aritmetic expression
			if(node == NULL){
				fprintf(stderr, "[SEMANTIC] INTERNAL PROBLEM: AST_RETURN null node\n");
				break;
			}
			type = get_type(node->offspring[0], scope);
			if(!test_arit_type(type)){
				fprintf(stderr, "[SEMANTIC PROBLEM] line %d: return function accepts only scalar value.\n", node->line);
				_SEMANTIC_ERROR = 1;
				break;
			}
			break; 
		case AST_IF: 
			if(node == NULL) {
				fprintf(stderr, "[SEMANTIC] INTERNAL PROBLEM: AST_IF null node\n");
				break;
			}
			n1 = node->offspring[0]; 
			n2 = node->offspring[1];
			n3 = node->offspring[2];
			if((node == NULL)||(n1 == NULL)||(n2 == NULL)) {
				fprintf(stderr, "[SEMANTIC] INTERNAL PROBLEM: AST_IF null node\n");
				break;
			}
			type = get_type(n1, scope);
			if(type != SYMBOL_LIT_BOOL) {
				fprintf(stderr, "[SEMANTIC PROBLEM] line %d: if condition is not a boolean expression.\n", node->line);
				_SEMANTIC_ERROR = 1;
				//break;
			}
			check_commands(n2, scope);
			if(n3 != NULL) {
				check_commands(n3, scope);
			}
			/*
			if_c: 
				KW_IF '(' expression ')' KW_THEN simple_command {$$=astree_create(AST_IF,0,$3,$6,0,0);}
				KW_IF '(' expression ')' KW_THEN simple_command KW_ELSE simple_command  {$$=astree_create(AST_IF,0,$3,$6,$8,0);}
			*/
			break;
		case AST_FOR:
			if(node == NULL) {
				fprintf(stderr, "[SEMANTIC] INTERNAL PROBLEM: AST_FOR null node\n");
				break;
			}
			n1 = node->offspring[0]; 
			n2 = node->offspring[1];
			n3 = node->offspring[2];
			if((n1 == NULL)||(n2 == NULL)||(n3 == NULL)) {
				fprintf(stderr, "[SEMANTIC] INTERNAL PROBLEM: AST_FOR null node\n");
				break;
			}
			//check identifier scalar type
			type = get_from_scope(node->id, scope);
			if(!test_arit_type(type)) {
				fprintf(stderr, "[SEMANTIC PROBLEM] line %d for loop: Identifier must be char, int or float type.\n", node->line);
				_SEMANTIC_ERROR = 1;
				//break;
			}
			type = get_type(n1, scope);
			if(!test_arit_type(type)) {
				fprintf(stderr, "[SEMANTIC PROBLEM] line %d for loop: First expression should be arithmetic.\n", node->line);
				_SEMANTIC_ERROR = 1;
				//break;
			}
			type = get_type(n2, scope);
			if(!test_arit_type(type)) {
				fprintf(stderr, "[SEMANTIC PROBLEM] line %d for loop: Second expression should be arithmetic.\n", node->line);
				_SEMANTIC_ERROR = 1;
				//break;
			}
			check_commands(n3, scope);
			//KW_FOR '(' TK_IDENTIFIER '=' expression KW_TO expression ')' simple_command {$$=astree_create(AST_FOR,$3,$5,$7,$9,0);}
			break;
		case AST_WHILE: 
			if(node == NULL){
				fprintf(stderr, "[SEMANTIC] INTERNAL PROBLEM: AST_WHILE null node\n");
				break;
			}
			n1 = node->offspring[0];
			n2 = node->offspring[1];
			if((n1 == NULL)||(n2 == NULL)) {
				fprintf(stderr, "[SEMANTIC] INTERNAL PROBLEM: AST_WHILE null node\n");
				break;
			}
			type = get_type(n1, scope);
			if(type != SYMBOL_LIT_BOOL) {
				fprintf(stderr, "[SEMANTIC PROBLEM] line %d while loop: Control expression must be boolean type.\n", node->line);
				_SEMANTIC_ERROR = 1;
				//break;
			}
			check_commands(n2,scope);
			//KW_WHILE '(' expression ')' simple_command  {$$=astree_create(AST_WHILE,0,$3,$5,0,0);}
			break;
		default: break;
	}
}

void assign_types(ASTree *node) {
    //print_astnode(node); //for debug sake
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

void check_types(ASTree *node) {
	switch(node->type) {
	case AST_FUNCTION_DEF:
		check_commands(node->offspring[1], node->offspring[0]->id->list_head);
		break;
	}
    //recursion
    for(int i =MAX_OFFSPRING-1; i >= 0; i--){
        if(node->offspring[i] != NULL)
            check_types(node->offspring[i]);
    }
}

void semantic_analysis(ASTree *node) {
	if(node != NULL) { //empty program case
		assign_types(node);
		check_types(node);
	}
}





