
#include "astree.h"
#include "semantic.h"
#include "hashtable.h"



int ptr2scalar(int ptr_type) {
	switch(ptr_type) {
		case SYMBOL_PTR_CHAR: return SYMBOL_LIT_CHAR;
		case SYMBOL_PTR_INT: return SYMBOL_LIT_INT;
			case SYMBOL_PTR_FLOAT: return SYMBOL_LIT_FLOAT;
	}
	fprintf(stderr, "[SEMANTIC] invalid ptr type\n");
	return -1;
}

// return the type of an expression
int get_exp_type(ASTree *node, ASTree *scope) {
	int type = -1; // invalid type
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
	// identifiers
	case AST_ID_POINTER:
	case AST_ID:
	case AST_VECTOR:
		type = get_from_scope(node->id, scope);
		break;
	case AST_FUNCTION:
		break;

	
	}
	return type;	
}

int assert_param_list_type(ASTree *node, ASTree *param_types, ASTree* scope) {
	int assert = 1;

	if (node == NULL) {
	// if empty parameters, return true
		if (param_types == NULL) 
			return 1;
		else
			return 0;
	}
	if (param_types == NULL)
		return 0;
	int param_type = kw2type(param_types->offspring[0]->type);
	return assert_type(node->offspring[0], param_type, scope) && 
		assert_param_list_type(node->offspring[1], param_types->offspring[1], scope); 
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

int assert_type(ASTree *node, int type, ASTree* scope) {
	int assert = 1; // 1 is correct type and 0 is wrong type
	int node_type = -1;
	ASTree *n1 = node->offspring[0];
	ASTree *n2 = node->offspring[1];
	if (node->id != NULL)
		node_type = get_from_scope(node->id, scope);
	switch(node->type) {
	case AST_CHAR:
		assert = (type == SYMBOL_LIT_CHAR);
		break;
	case AST_INT:
		assert = (type == SYMBOL_LIT_INT);
		break;
	case AST_REAL:
		assert = (type == SYMBOL_LIT_FLOAT);
		break;
	case AST_INIT_VALUES:
		// check the type of the list of init values
		if (n2 != NULL)
			assert = assert_type(n2, type, scope)
					&& assert_type(n1, type, scope);
		break;
	case AST_ID_POINTER:
	case AST_ID:
		assert = (node_type == type);
		break;
	case AST_VECTOR:
		break; //TODO
	case AST_FUNCTION:
		assert = assert_param_list_type(n1, node->id->list_head, scope) &&
			(type == node_type);
		break; // TODO
	case AST_PARAM:

		break;
	case AST_NOT_EXP:
		assert = assert_type(n1, SYMBOL_LIT_BOOL, scope); 	
		break;
	case AST_NEG_EXP:
		assert = assert_type(n1, SYMBOL_LIT_INT, scope) 
				|| assert_type(n1, SYMBOL_LIT_FLOAT, scope);
		break;
	case AST_PAR_EXP:
		assert = assert_type(n1, type, scope);
		break;
	case AST_PLUS_EXP:
		//TODO : assert_plus_type
		break;
	default:
		break;
	}
	return assert;
}


// assert if plus expression 
int assert_plus_exp(ASTree *node, int type, ASTree *scope) {
	ASTree *n1 = node->offspring[0];
	ASTree *n2 = node->offspring[1];
	int assert =  (((assert_ptr_type(n1, scope) || assert_ptr_type(n2, scope))
		&& !(assert_ptr_type(n1, scope) && assert_ptr_type(n2, scope))) // only one can be pointer
		|| (assert_arit_type(n1,scope) || assert_arit_type(n2,scope))) // at least one should be aritmetic
		&& (!assert_type(n1,SYMBOL_LIT_BOOL, scope) && !assert_type(n2,SYMBOL_LIT_BOOL, scope)); // none of them should be boolean 
	// test the return type
	//int final_type;
	// TODO: testar se tipo de retorno da soma é o mesmo passar por parametro
	return assert;
}

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


/*Assignment functions*/


void assign_fun_type(ASTree *node){ //TO DO: FIX RETURNS!!!
	//print_type(node->id); //hash pointer
        if(node->id->type == SYMBOL_IDENTIFIER){ //not assigned
            int type = node->offspring[0]->type;
            switch(type){
                case AST_CHAR_SYMBOL: 
                node->id->type = SYMBOL_FUN_CHAR;
                fprintf(stderr, "[SEMANTIC] Changing variable %s type: ", node->id->id);
                print_type(node->id);
                break;
                case AST_INT_SYMBOL: 
                node->id->type = SYMBOL_FUN_INT;
                fprintf(stderr, "[SEMANTIC] Changing variable %s type: ", node->id->id);
                print_type(node->id);
                break;
               case AST_FLOAT_SYMBOL: 
                node->id->type = SYMBOL_FUN_FLOAT;
                fprintf(stderr, "[SEMANTIC] Changing variable %s type: ", node->id->id);
                print_type(node->id);
                break;
                default: 
                fprintf(stderr, "[SEMANTIC] ERROR\n");
                break;
            }
        } else{
            fprintf(stderr, "[SEMANTIC PROBLEM] Function %s already declared with type: ", node->id->id);
            print_type(node->id);
        }

		ASTree *old = node;
		if(node->offspring[1] != NULL) {//check parameters
			node = node->offspring[1];
			hashTable *params;
			initHash(params, MAX_PARAM_SIZE);
			do{
				hashNode *n;
				initNode(&n);
				strcpy(n->id, node->id->id); // atribuindo identificador como key
				n->type = node->id->type;
				hashNode* res =insertHash(n, params);
				if (res != n) 
				free(n);
				free(params);
				fprintf(stderr, "[SEMANTIC PROBLEM] On function %s: parameter %s was declared twice.\n", old->id->id, node->id->id);
				break;
			}while(node->offspring[1] != NULL);
		}		
}

void assign_var_type(ASTree *node) {
	//print_type(node->id); //hash pointer
        if(node->id->type == SYMBOL_IDENTIFIER){ //not assigned
            int type = node->offspring[0]->type;
            switch(type){
                case AST_CHAR_SYMBOL: 
                node->id->type = SYMBOL_LIT_CHAR;
                fprintf(stderr, "[SEMANTIC] Changing variable %s type: ", node->id->id);
                print_type(node->id);
                break;
                case AST_INT_SYMBOL: 
                node->id->type = SYMBOL_LIT_INT;
                fprintf(stderr, "[SEMANTIC] Changing variable %s type: ", node->id->id);
                print_type(node->id);
                break;
               case AST_FLOAT_SYMBOL: 
                node->id->type = SYMBOL_LIT_FLOAT;
                fprintf(stderr, "[SEMANTIC] Changing variable %s type: ", node->id->id);
                print_type(node->id);
                break;
                default: 
                fprintf(stderr, "[SEMANTIC] ERROR\n");
                break;
            }
        } else{
            fprintf(stderr, "[SEMANTIC PROBLEM] Variable %s already declared with type: ", node->id->id);
            print_type(node->id);
        }
}

void assign_pointer_type(ASTree *node) {
	if(node->id->type == SYMBOL_IDENTIFIER){ //not assigned
		int type = node->offspring[0]->type;
		switch(type){
			case AST_CHAR_SYMBOL: 
				node->id->type = SYMBOL_PTR_CHAR;
				fprintf(stderr, "[SEMANTIC] Changing variable %s type: ", node->id->id);
				print_type(node->id);
				break;
			case AST_INT_SYMBOL: 
				node->id->type = SYMBOL_PTR_INT;
				fprintf(stderr, "[SEMANTIC] Changing variable %s type: ", node->id->id);
				print_type(node->id);
				break;
		   case AST_FLOAT_SYMBOL: 
				node->id->type = SYMBOL_PTR_FLOAT;
				fprintf(stderr, "[SEMANTIC] Changing variable %s type: ", node->id->id);
				print_type(node->id);
				break;
			default: 
				fprintf(stderr, "[SEMANTIC] ERROR\n");
				break;
		}
	} else{
		fprintf(stderr, "[SEMANTIC PROBLEM] Variable %s already declared with type: ", node->id->id);
		print_type(node->id);
	}
}

void assign_vector_type(ASTree *node) {
	//TO DO
	//check if the elements (if they exist) are from the same type than vec type 
	int type;
	if(node->id->type == SYMBOL_IDENTIFIER){ //not assigned
		type = node->offspring[0]->type;
		switch(type){
			case AST_CHAR_SYMBOL: 
				node->id->type = SYMBOL_VEC_CHAR;
				fprintf(stderr, "[SEMANTIC] Changing variable %s type: ", node->id->id);
				print_type(node->id);
				break;
			case AST_INT_SYMBOL: 
				node->id->type = SYMBOL_VEC_INT;
				fprintf(stderr, "[SEMANTIC] Changing variable %s type: ", node->id->id);
				print_type(node->id);
				break;
		   case AST_FLOAT_SYMBOL: 
				node->id->type = SYMBOL_VEC_FLOAT;
				fprintf(stderr, "[SEMANTIC] Changing variable %s type: ", node->id->id);
				print_type(node->id);
				break;
			default: 
				fprintf(stderr, "[SEMANTIC] ERROR\n");
				break;
		}
	} else{
		fprintf(stderr, "[SEMANTIC PROBLEM] Variable %s already declared with type: ", node->id->id);
	}
	int size_type = node->offspring[1]->type;
	if(size_type != AST_INT) {
		fprintf(stderr, "[SEMANTIC PROBLEM] Vector must have an integer as size. Given type ");
		print_type(node->id);
	}

	if(node->offspring[2] != NULL) { //there are init values
		// assert type with global environment 
		type = kw2type(type);
		if(assert_type(node->offspring[2],type,NULL) == 0) {
			fprintf(stderr, "[SEMANTIC PROBLEM] Incorrect initialization value to vector %s\n", node->id->id);
		}
	}
}

void assign_param_type(ASTree *node) {
	//TO DO
}

/**********************/

//1: check assignments
void assign_types(ASTree *node) {
    print_astnode(node); //for debug sake
	switch(node->type) {
	case AST_HEADER: //function
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
    case AST_DEF_PARAM_T:
        assign_param_type(node);
		break;
    }
    //recursion
    for(int i =MAX_OFFSPRING-1; i >= 0; i--){
        if(node->offspring[i] != NULL)
            assign_types(node->offspring[i]);
    }
}


//NOT READY
//2: check if int var = X x = int type
void check_assignment_types(ASTree *node) {
    
    //print_astnode(node); //for debug sake

    //AST_FUNCTION_DEF
    if(node->type == AST_FUNCTION_DEF){
        //TO DO 
    }

    //AST_GLOBAL_VECTOR_DEF
    if(node->type == AST_GLOBAL_VECTOR_DEF){
        //como tipar o assignment?? vetor[xx]: 1 2 3 4 "l" 6.7
        //TO DO
    }

    //AST_GLOBAL_VAR_DEF & AST_GLOBAL_POINTER_DEF
    if((node->type == AST_GLOBAL_VAR_DEF)||(node->type == AST_GLOBAL_POINTER_DEF)){
        //TO DO
    }

    //AST_DEF_PARAM_T
    if(node->type == AST_DEF_PARAM_T){
        //TO DO
    }


    //recursion
    for(int i =MAX_OFFSPRING-1; i >= 0; i--){
        if(node->offspring[i] != NULL)
            check_assignment_types(node->offspring[i]);
    }

}

//NOT READY
//3: check if var[] -> var = array type; var(la,la,la) -> var = function type
void check_variables_usage(ASTree *node) {
    //TO DO
}

void semantic_analysis(ASTree *root) {
    assign_types(root);
    check_assignment_types(root);
    check_variables_usage(root);
}

