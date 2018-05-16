
#include "astree.h"
#include "semantic.h"
#include "hashtable.h"

void assign_types(ASTree *node) {
    print_astnode(node); //for debug sake

	switch(node->type) {
    //AST_FUNCTION_DEF
	case AST_FUNCTION_DEF:
		break;
    
    //AST_GLOBAL_VAR_DEF 
   	case AST_GLOBAL_VAR_DEF:
        print_type(node->id); //hash pointer
        if(node->id->type == SYMBOL_IDENTIFIER){ //not assigned
            int type = node->offspring[0]->type;
            switch(type){
                case AST_CHAR_SYMBOL: 
                node->id->type = SYMBOL_LIT_CHAR;
                fprintf(stderr, "[SEMANTIC] Changing variable %s type:", node->id->id);
                print_type(node->id);
                break;
                case AST_INT_SYMBOL: 
                node->id->type = SYMBOL_LIT_INT;
                fprintf(stderr, "[SEMANTIC] Changing variable %s type:", node->id->id);
                print_type(node->id);
                break;
               case AST_FLOAT_SYMBOL: 
                node->id->type = SYMBOL_LIT_FLOAT;
                fprintf(stderr, "[SEMANTIC] Changing variable %s type:", node->id->id);
                print_type(node->id);
                break;
                default: 
                fprintf(stderr, "[SEMANTIC] ERROR\n");
                break;
            }
        } else{
            fprintf(stderr, "[SEMANTIC] Variable %s already assigned with type: ", node->id->id);
            print_type(node->id);
        }
		break;
    case AST_GLOBAL_VECTOR_DEF:
	case AST_GLOBAL_POINTER_DEF:
		print_type(node->id);
		assign_pointer_type(node);
		break;
	

    //AST_DEF_PARAM_T
    case AST_DEF_PARAM_T:
        //TO DO
		break;
    }


    //recursion
    for(int i =MAX_OFFSPRING-1; i >= 0; i--){
        if(node->offspring[i] != NULL)
            assign_types(node->offspring[i]);
    }
}

void assign_pointer_type(ASTree *node) {
	if(node->id->type == SYMBOL_IDENTIFIER){ //not assigned
		int type = node->offspring[0]->type;
		switch(type){
			case AST_CHAR_SYMBOL: 
				node->id->type = SYMBOL_PTR_CHAR;
				fprintf(stderr, "[SEMANTIC] Changing variable %s type:", node->id->id);
				print_type(node->id);
				break;
			case AST_INT_SYMBOL: 
				node->id->type = SYMBOL_PTR_INT;
				fprintf(stderr, "[SEMANTIC] Changing variable %s type:", node->id->id);
				print_type(node->id);
				break;
		   case AST_FLOAT_SYMBOL: 
				node->id->type = SYMBOL_PTR_FLOAT;
				fprintf(stderr, "[SEMANTIC] Changing variable %s type:", node->id->id);
				print_type(node->id);
				break;
			default: 
				fprintf(stderr, "[SEMANTIC] ERROR\n");
				break;
		}
	} else{
		fprintf(stderr, "[SEMANTIC] Variable %s already declared with type: ", node->id->id);
		print_type(node->id);
	}
	// assert the init value list type
	if (node->offspring[2] != NULL) {
		int assert = assert_type(node->offspring[2], ptr2scalar(node->id->type));
		if (assert == 0)
			fprintf(stderr, "[SEMANTIC] incorrect vector initialization\n");
	}
	
}

int ptr2scalar(int ptr_type) {
	switch(ptr_type) {
		case SYMBOL_PTR_CHAR: return SYMBOL_LIT_CHAR;
		case SYMBOL_PTR_INT: return SYMBOL_LIT_INT;
			case SYMBOL_PTR_FLOAT: return SYMBOL_LIT_FLOAT;
	}
	fprintf(stderr, "[SEMANTIC] invalid ptr type\n");
	return -1;
}

int assert_type(ASTree *node, int type) {
	int assert = 1; // 1 is correct type and 0 is wrong type
	int node_type = -1;
	ASTree *n1 = node->offspring[0];
	ASTree *n2 = node->offspring[1];
	if (node->id != NULL)
		node_type = node->id->type;
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
			assert = assert_type(n2, type)
					&& assert_type(n1, type);
		break;
	case AST_ID_POINTER:
	case AST_ID:
		assert = (node_type == type);
		break;
	case AST_VECTOR:
		break; //TODO
	case AST_FUNCTION:
		break; // TODO
	case AST_NOT_EXP:
		assert = assert_type(n1, SYMBOL_LIT_BOOL); 	
		break;
	case AST_NEG_EXP:
		assert = assert_type(n1, SYMBOL_LIT_INT) 
				|| assert_type(n1, SYMBOL_LIT_FLOAT);
		break;
	case AST_PAR_EXP:
		assert = assert_type(n1, type);
		break;
	case AST_PLUS_EXP:
		//TODO : assert_plus_type
		break;
	default:
		break;
	}
	return assert;
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
	case AST_FUNCTION:
		type = get_from_scope(node->id, scope);
		break;
	}
	return type;	
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

// assert if plus expression 
int assert_plus_exp(ASTree *node, int type) {
	ASTree *n1 = node->offspring[0];
	ASTree *n2 = node->offspring[1];
	int assert =  (((assert_ptr_type(n1) || assert_ptr_type(n2))
		&& !(assert_ptr_type(n1) && assert_ptr_type(n2))) // only one can be pointer
		|| (assert_arit_type(n1) || assert_arit_type(n2))) // at least one should be aritmetic
		&& (!assert_type(n1,SYMBOL_LIT_BOOL) && !assert_type(n2,SYMBOL_LIT_BOOL)); // none of them should be boolean 
	// test the return type
	//int final_type;
	// TODO: testar se tipo de retorno da soma é o mesmo passar por parametro
	return assert;
}

int assert_arit_type(ASTree *node) {
	return assert_type(node, SYMBOL_LIT_INT)
		|| assert_type(node, SYMBOL_LIT_CHAR)
		|| assert_type(node, SYMBOL_LIT_FLOAT);
}

int assert_ptr_type(ASTree *node) {
	return assert_type(node, SYMBOL_PTR_INT)
		|| assert_type(node, SYMBOL_PTR_CHAR)
		|| assert_type(node, SYMBOL_PTR_FLOAT);
}

//check if int var = X x = int type
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
            assign_types(node->offspring[i]);
    }

}

//check if var[] -> var = array type; var(la,la,la) -> var = function type
void check_variables_usage(ASTree *node) {
    
}

void semantic_analysis(ASTree *root) {
    assign_types(root);
    check_assignment_types(root);
    check_variables_usage(root);
}

