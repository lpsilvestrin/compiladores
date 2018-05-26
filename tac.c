#include "tac.h"
#include "astree.h"

void print_tac(TAC *tac);

TAC* tac_create(int type, hashNode *result, hashNode *op1, hashNode *op2) { //, TAC *prev, TAC *next) {
    TAC *t = (TAC*)malloc(sizeof(TAC));
    t->type = type;
    t->result = result;
    t->op1 = op1;
    t->op2 = op2;
    t->prev = NULL;
    t->next = NULL;
    //t->prev = prev;
    //t->next = next;
    return t;
}

TAC* tac_join(TAC* tac1, TAC* tac2) {
    TAC* temp;
    if(tac1 == NULL)
        return tac2;
    if(tac2 == NULL)
        return tac1;
    for(temp = tac2; temp->prev; temp = temp->prev); 
    temp->prev = tac1;
    return tac2;
}

TAC* tac_reverse(TAC *tac) {
    if(tac == NULL) {
        return NULL;
    } 
    TAC *aux;
    for(aux = tac; aux->prev; aux = aux->prev)
        aux->prev->next = aux;
    return aux;
}

void tac_print_code(TAC *tac){
    if(tac == NULL){
        return;
    }
    print_tac(tac);
    tac_print_code(tac->next);
}

TAC* tac_generate_code(ASTree *node) {
    if(node == NULL) {
        return NULL;
    }

    TAC *new_code[MAX_OFFSPRING];
    TAC *t1;
    TAC *t2;

    //starts from the end
    for(int i =0; i < MAX_OFFSPRING; i++) {
        if(node->offspring[i] == NULL) {
            new_code[i] = NULL;
        } else {
            new_code[i] = tac_generate_code(node->offspring[i]);
        }
    }
    switch(node->type) {
        case AST_GLOBAL: break;
        case AST_GLOBAL_VAR_DEF: 
            t1 = tac_create(TAC_VAR_DEF, node->offspring[0]->id, NULL, NULL); //$$=astree_create(AST_GLOBAL_VAR_DEF,$2,$1,$4,0,0);}
            t2 = tac_create(TAC_ASSIGNMENT, node->offspring[2]->id, NULL, NULL); //{$$=astree_create(AST_CHAR,$1,0,0,0,0);} 
            return tac_join(t1, t2);
            break;
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
            return tac_create(TAC_SYMBOL, node->id, NULL, NULL);
            break;
        case AST_INT: // ?????????
        case AST_REAL: 
        case AST_CHAR: break;
        default:
            fprintf(stderr, "[TAC] SOMETHING IS WRONG!!\n");
    }
    return NULL;
}

void print_tac(TAC *tac) {
    if(tac == NULL)
        return;
    switch(tac->type) {
        case TAC_FUN_BEGIN: fprintf(stderr, "TAC_FUN_BEGIN"); break;
        case TAC_FUN_END: fprintf(stderr, "TAC_FUN_END"); break;
        case TAC_FUN_ARG: fprintf(stderr, "TAC_FUN_ARG"); break;
        case TAC_FUN_CALL: fprintf(stderr, "TAC_FUN_CALL"); break;
        case TAC_VAR_DEF: fprintf(stderr, "TAC_VAR_DEF"); break;
        case TAC_VEC_DEF: fprintf(stderr, "TAC_VEC_DEF"); break;
        case TAC_POINTER_ASSIGN: fprintf(stderr, "TAC_POINTER_ASSIGN"); break;
        case TAC_PRINT: fprintf(stderr, "TAC_PRINT"); break;
        case TAC_READ: fprintf(stderr, "TAC_READ"); break;
        case TAC_ADD: fprintf(stderr, "TAC_ADD"); break;
        case TAC_SUB: fprintf(stderr, "TAC_SUB"); break;
        case TAC_MUL: fprintf(stderr, "TAC_MUL"); break;
        case TAC_DIV: fprintf(stderr, "TAC_DIV"); break;
        case TAC_NEG: fprintf(stderr, "TAC_NEG"); break;
        case TAC_AND: fprintf(stderr, "TAC_AND"); break;
        case TAC_OR: fprintf(stderr, "TAC_OR"); break;
        case TAC_NOT: fprintf(stderr, "TAC_NOT"); break;
        case TAC_EQ: fprintf(stderr, "TAC_EQ"); break;
        case TAC_NEQ: fprintf(stderr, "TAC_NEQ"); break;
        case TAC_LEQ: fprintf(stderr, "TAC_LEQ"); break;
        case TAC_GEQ: fprintf(stderr, "TAC_GEQ"); break;
        case TAC_JUMP: fprintf(stderr, "TAC_JUMP"); break;
        case TAC_RETURN: fprintf(stderr, "TAC_RETURN"); break;
        case TAC_SYMBOL: fprintf(stderr, "TAC_SYMBOL"); break;
        case TAC_ASSIGNMENT: fprintf(stderr, "TAC_ASSIGNMENT"); break;
        default: fprintf(stderr, "WEIRD TAC TYPE ON FUNCTION print_tac\n"); break;
    }

}