
#include "astree.h"
#include "hashtable.h"

void assign_types(ASTree *node){
    //declaration can be: function, vector or variable

    //AST_FUNCTION_DEF
    if(node->type == AST_FUNCTION_DEF){
        //TO DO 
    }

    //AST_GLOBAL_VECTOR_DEF
    if(node->type == AST_GLOBAL_VECTOR_DEF){
        //como tipar o assignment?? vetor[xx]: 1 2 3 4 "l" 6.7
        //TO DO
    }
    //AST_GLOBAL_VAR_DEF
    if(node->type == AST_GLOBAL_VAR_DEF){
        //scalar_type TK_IDENTIFIER '=' init_value ';' {$$=astree_create(AST_GLOBAL_VAR_DEF,$2,$1,$4,0,0);}
        if(node->id->type == SYMBOL_IDENTIFIER){ //not assigned
            //get type 
            int type = node->offspring[0]->type;
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
                default: break;
            }
        } else{
            fprintf(stderr, "Variable %s already assigned with type: ", node->id->id);
            int type = node->id->type;
            switch(type){
                case SYMBOL_LIT_CHAR: 
                    fprintf(stderr, "char\n");
                break;
                case SYMBOL_LIT_INT: 
                    fprintf(stderr, "int\n");
                break;
                case SYMBOL_LIT_FLOAT: 
                    fprintf(stderr, "float\n");
                break;
                default: break;
            }
        }

    }
    //AST_GLOBAL_POINTER_DEF
    if(node->type == AST_GLOBAL_POINTER_DEF){
        //TO DO
    }
    //AST_DEF_PARAM_T
    if(node->type == AST_DEF_PARAM_T){
        //TO DO
    }

    //recursion
    for(int i =0; i < MAX_OFFSPRING; i++){
        if(node->offspring[i] != NULL)
            assign_types(node->offspring[i]);
    }
}

void semantic_analysis(ASTree *root){
    assign_types(root);
}