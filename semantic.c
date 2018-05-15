
#include "astree.h"
#include "hashtable.h"

void assign_types(ASTree *node) {
    print_astnode(node); //for debug sake

	switch(node->type) {
    //AST_FUNCTION_DEF
	case AST_FUNCTION_DEF:
	//TO DO 
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
		if (node->offspring[1] != NULL)
			assert = assert_type(node->offspring[1], type)
					&& assert_type(node->offspring[0], type);
		break;
			
	}
	return assert;
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

