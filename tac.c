#include "tac.h"
#include "astree.h"

TAC* tac_create(int type, hashNode *result, hashNode *op1, hashNode *op2, TAC *prev, TAC *next) {
    TAC *t = (TAC*)malloc(sizeof(TAC));
    t->type = type;
    t->result = result;
    t->op1 = op1;
    t->op2 = op2;
    t->prev = prev;
    t->next = next;
    return t;
}


TAC* create_code(ASTree *node) {
    if(node == NULL) {
        return NULL;
    }

    TAC *new_code[MAX_OFFSPRING];

    //starts from the end
    for(int i =0; i < MAX_OFFSPRING; i++) {
        if(node->offspring[i] == NULL) {
            new_code[i] = NULL;
        } else {
            new_code[i] = create_code(node->offspring[i]);
        }
    }

    switch(node->type) {
        case AST_GLOBAL: break;
        case AST_GLOBAL_VAR_DEF: break;
        case AST_GLOBAL_POINTER_DEF: break;
        case AST_GLOBAL_VECTOR_DEF: break;
        case AST_FUNCTION_DEF: break;
        case AST_HEADER: break;
        case AST_DEF_PARAM: break;
        case AST_DEF_PARAM_T: break;
        case AST_BLOCK: break;
        case AST_COMMANDS_L: break;
        case AST_VAR_AS: break;
        case AST_VECTOR_AS: break;
        case AST_READ: break;
        case AST_PRINT: break;
        case AST_RETURN: break;
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
        case AST_VECTOR_DEF: break;
        case AST_VECTOR: break;
        case AST_FUNCTION: break;
        case AST_PARAM: break;
        case AST_IF: break;
        case AST_FOR: break;
        case AST_WHILE: break;
        case AST_INIT_VALUES: break;
        case AST_INT_SYMBOL: 
        case AST_FLOAT_SYMBOL: 
        case AST_CHAR_SYMBOL: 
            return tac_create(TAC_SYMBOL, node->id, NULL, NULL, NULL, NULL);
            break;
        case AST_INT: break;
        case AST_REAL: break;
        case AST_CHAR: break;
        default:
            fprintf(stderr, "[TAC] SOMETHING IS WRONG!!\n");
    }
    return NULL;
}