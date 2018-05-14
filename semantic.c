
#include "astree.h"
#include "hashtable.h"

void assign_types(ASTree *node) {
    print_astnode(node); //for debug sake

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
		fprintf(stderr, "[SEMANTIC] Variable %s already assigned with type: ", node->id->id);
		print_type(node->id);
	}
	
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

