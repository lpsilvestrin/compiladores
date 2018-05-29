#include "tac.h"


int next_label = 0;
int next_temp = 0;

void print_tac(TAC *tac);


hashNode* new_label() {
	return make_label(next_label++, SymbolsTable);
}

hashNode* new_temp() {
	return make_temp(next_temp++, SymbolsTable);
}

TAC* tac_create(int type, hashNode *result, hashNode *op1, hashNode *op2) { 
    TAC *t = (TAC*)malloc(sizeof(TAC));
    t->type = type;
    t->result = result;
    t->op1 = op1;
    t->op2 = op2;
    t->prev = NULL;
    t->next = NULL;
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
    for(aux = tac; aux->prev != NULL; aux = aux->prev)
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

TAC* binary_op(int op, TAC* t1, TAC* t2) {
	TAC* btac = tac_create(op, new_temp(), t1?t1->result:NULL, t2?t2->result:NULL);
	return tac_join(t1, tac_join(t2, btac));
}

TAC* tac_generate_code(ASTree *node) {
    if(node == NULL) {
        return NULL;
    }
    TAC *new_code[MAX_OFFSPRING];
    TAC *t1, *t2, *t3, *t4, *t5, *t6;
	hashNode *label, *label2;
    
    for(int i=0; i < MAX_OFFSPRING; i++) {
        if(node->offspring[i] == NULL) {
            new_code[i] = NULL;
        } else {
            new_code[i] = tac_generate_code(node->offspring[i]);
            }
    }

    switch(node->type) {
        case AST_GLOBAL: 
			return tac_join(new_code[1], new_code[0]);
			break;
        case AST_GLOBAL_VAR_DEF:
			return tac_create(TAC_VAR_DEF, node->id, new_code[1]->result, NULL);
            break;
        case AST_GLOBAL_POINTER_DEF: 
            return tac_create(TAC_POINTER_DEF, node->id, new_code[1]->result, NULL); 
            break;
        case AST_GLOBAL_VECTOR_DEF: 
			t1 = tac_create(TAC_VEC_DEF, node->id, new_code[1]->result, NULL);
			return tac_join(t1, new_code[2]); // join vec def with init values
			break;
		case AST_INIT_VALUES:
			t1 = tac_create(TAC_SYMBOL, new_code[1]->result, NULL, NULL);
			return tac_join(new_code[0], t1);
        case AST_FUNCTION_DEF: 
			return tac_join(new_code[0], new_code[1]); //tac_join(new_code[1], new_code[0]); 
			break;
        case AST_HEADER: 
			t1 = tac_create(TAC_FUN_BEGIN, node->id, NULL, NULL);
			return tac_join(t1, new_code[1]);//, t1);
			break;
        case AST_DEF_PARAM_T: 
			t1 = tac_create(TAC_SYMBOL, node->id, NULL, NULL);
			return tac_join(t1, new_code[1]);
			break;
        case AST_BLOCK: 
			t1 = tac_create(TAC_FUN_END, new_label(), NULL, NULL);
			return tac_join(new_code[0], t1); 
			break;
        case AST_COMMANDS_L:
			return tac_join(new_code[0], new_code[1]);
			break;
        case AST_VAR_AS: 
			t1 = tac_create(TAC_VAR_AS, node->id, new_code[0]->result, NULL);
			return tac_join(t1, new_code[0]);//tac_join(new_code[0], t1);
			break;
        case AST_VECTOR_AS: 
			t1 = tac_create(TAC_VECTOR_AS, node->id, new_code[0]->result, new_code[1]->result);
			return tac_join(new_code[0], tac_join(new_code[1], t1));
			break;
        case AST_READ: 
            return tac_create(TAC_READ, node->id, NULL, NULL);
            break;
        case AST_PRINT: 
            /*
                    | print_c LIT_STRING    {$$=astree_create(AST_PRINT,$2,$1,0,0,0);}
                    | print_c expression    {$$=astree_create(AST_PRINT,0,$1,$2,0,0);}
            */
            t1 =  tac_create(TAC_PRINT, node?node->id:new_code[1]->result, NULL, NULL);
            return tac_join(new_code[0], t1);
            break;
        case AST_RETURN: 
            t1 = tac_create(TAC_RETURN, new_code[0]->result, NULL, NULL);
            t2 = tac_create(TAC_JUMP, new_label(), NULL, NULL);
            return tac_join(t1,t2);
            break;
        case AST_NOT_EXP:
			t1 = tac_create(TAC_NOT, new_temp(), new_code[0]->result, NULL);
			return tac_join(new_code[0], t1);
			break;
        case AST_NEG_EXP: 
			t1 = tac_create(TAC_NEG, new_temp(), new_code[0]->result, NULL);
			return tac_join(new_code[0], t1);
			break;
        case AST_PAR_EXP: 
			return new_code[0];
			break;
        case AST_PLUS_EXP: 
			return binary_op(TAC_ADD, new_code[0], new_code[1]);
			break;
        case AST_MINUS_EXP:
			return binary_op(TAC_SUB, new_code[0], new_code[1]);
			break;
        case AST_MUL_EXP: 
			return binary_op(TAC_MUL, new_code[0], new_code[1]);
			break;
        case AST_DIV_EXP:
			return binary_op(TAC_DIV, new_code[0], new_code[1]);
        case AST_LESS_EXP:
			return binary_op(TAC_LESS, new_code[0], new_code[1]);
        case AST_GREAT_EXP:
			return binary_op(TAC_GREAT, new_code[0], new_code[1]);
        case AST_LE_EXP:
			return binary_op(TAC_LEQ, new_code[0], new_code[1]);
        case AST_GE_EXP:
			return binary_op(TAC_GEQ, new_code[0], new_code[1]);
        case AST_EQ_EXP:
			return binary_op(TAC_EQ, new_code[0], new_code[1]);
        case AST_NE_EXP:
			return binary_op(TAC_NEQ, new_code[0], new_code[1]);
        case AST_AND_EXP:
			return binary_op(TAC_AND, new_code[0], new_code[1]);
        case AST_OR_EXP:
			return binary_op(TAC_OR, new_code[0], new_code[1]);
        case AST_ID: 
			return tac_create(TAC_SYMBOL, node->id, NULL, NULL);
			break;
        case AST_ID_POINTER: 
			return tac_create(TAC_ID_POINTER, node->id, NULL, NULL);
			break;
        case AST_ID_ADDRESS: 
			return tac_create(TAC_ID_ADDRESS, node->id, NULL, NULL);
			break;
        case AST_VECTOR: 
			t1 = tac_create(TAC_VECTOR, node->id, new_code[0]->result, NULL);
			return tac_join(new_code[0], t1);
			break;
        case AST_FUNCTION: 
			t1 = tac_create(TAC_FUN_CALL, node->id, NULL, NULL); //call
            t2 = tac_join(new_code[0],t1); //args + call
            t3 = tac_create(TAC_LABEL, new_label(), NULL, NULL); //jump label
            //return tac_join(t1,t2);
            return tac_join(t2,t3);
			break;
        case AST_PARAM: 
            //print_astnode(node);
            t1 = tac_create(TAC_PARAM, new_code[0]->result, NULL ,NULL); //parameters_list_tail ',' expression
            return tac_join(new_code[1], t1); //{$$=astree_create(AST_PARAM,0,$1,$3,0,0);}
            break;
        case AST_IF: 
			// if result is zero, jump to new_label
			label = new_label();
			t1 = tac_create(TAC_IFZ, new_code[0]->result, label, NULL);
			t2 = tac_create(TAC_LABEL, label, NULL, NULL);
			return tac_join(new_code[0], tac_join(t1, tac_join(new_code[1], tac_join(t2, new_code[2]))));
			break;
        case AST_FOR: 
            //print_astnode(node);
            //KW_FOR '(' TK_IDENTIFIER '=' expression KW_TO expression ')' simple_command
            //{$$=astree_create(AST_FOR,$3,$5,$7,$9,0);}
            label = new_label();
			label2 = new_label();
            //assignment
            t1 = tac_create(TAC_VAR_AS, node->id, new_code[0]->result, NULL);
            //beginning label
            t2 = tac_create(TAC_LABEL, label, NULL, NULL);
            //comparison with jump to ending label
            //<<<<<<<<<<<missing t1->result++
            t3 = binary_op(TAC_SUB, t1, new_code[1]); 
            t4 = tac_create(TAC_IFZ, t3->result, label2, NULL);
            //here goes the code
            //jump 
            t5 = tac_create(TAC_JUMP, label, NULL, NULL);
            //ending label
			t6 = tac_create(TAC_LABEL, label2, NULL, NULL);

            return NULL; //everything breaks if I try to join t3 :(
            break;
        case AST_WHILE: 
			label = new_label();
			label2 = new_label();
			t1 = tac_create(TAC_IFZ, new_code[0]->result, label2, NULL);
			t2 = tac_create(TAC_LABEL, label, NULL, NULL);
			t3 = tac_create(TAC_LABEL, label2, NULL, NULL);
			t4 = tac_create(TAC_JUMP, label, NULL, NULL);
			// order: label1, new_code[0], IFZ, new_code[1], JUMP(label1), label2, continue...
			return tac_join(t2, tac_join(new_code[0], tac_join(t1, tac_join(new_code[1], tac_join(t4, t3)))));	
			break;
        case AST_DEF_PARAM: 
        case AST_INT_SYMBOL: 
        case AST_FLOAT_SYMBOL: 
        case AST_CHAR_SYMBOL:
			// do nothing
            break;
        case AST_INT: 
        case AST_REAL: 
        case AST_CHAR: 
            return tac_create(TAC_SYMBOL, node->id, NULL, NULL);
            break;
        default:
            fprintf(stderr, "[TAC] SOMETHING IS WRONG!!\n");
            return NULL;
    }
    return NULL;
}

void print_tac(TAC *tac) {
    if(tac == NULL)
        return;
    switch(tac->type) {
        case TAC_FUN_BEGIN: fprintf(stderr, "TAC_FUN_BEGIN\n"); break;
        case TAC_FUN_END: fprintf(stderr, "TAC_FUN_END\n"); break;
        case TAC_FUN_ARG: fprintf(stderr, "TAC_FUN_ARG\n"); break;
        case TAC_FUN_CALL: fprintf(stderr, "TAC_FUN_CALL\n"); break;
        case TAC_VAR_DEF: fprintf(stderr, "TAC_VAR_DEF\n"); break;
        case TAC_VEC_DEF: fprintf(stderr, "TAC_VEC_DEF\n"); break;
        case TAC_POINTER_DEF: fprintf(stderr, "TAC_POINTER_DEF\n"); break;
        case TAC_PRINT: fprintf(stderr, "TAC_PRINT\n"); break;
        case TAC_READ: fprintf(stderr, "TAC_READ\n"); break;
        case TAC_ADD: fprintf(stderr, "TAC_ADD\n"); break;
        case TAC_SUB: fprintf(stderr, "TAC_SUB\n"); break;
        case TAC_MUL: fprintf(stderr, "TAC_MUL\n"); break;
        case TAC_DIV: fprintf(stderr, "TAC_DIV\n"); break;
        case TAC_NEG: fprintf(stderr, "TAC_NEG\n"); break;
        case TAC_AND: fprintf(stderr, "TAC_AND\n"); break;
        case TAC_OR: fprintf(stderr, "TAC_OR\n"); break;
        case TAC_NOT: fprintf(stderr, "TAC_NOT\n"); break;
        case TAC_EQ: fprintf(stderr, "TAC_EQ\n"); break;
        case TAC_NEQ: fprintf(stderr, "TAC_NEQ\n"); break;
        case TAC_LEQ: fprintf(stderr, "TAC_LEQ\n"); break;
        case TAC_GEQ: fprintf(stderr, "TAC_GEQ\n"); break;
        case TAC_JUMP: fprintf(stderr, "TAC_JUMP\n"); break;
        case TAC_RETURN: fprintf(stderr, "TAC_RETURN\n"); break;
        case TAC_SYMBOL: fprintf(stderr, "TAC_SYMBOL %s\n", tac->result->id); break;
        case TAC_PARAM: fprintf(stderr, "TAC_PARAM %s\n", tac->result->id); break;
        case TAC_VAR_AS: fprintf(stderr, "TAC_VAR_AS\n"); break;
        case TAC_VECTOR_AS: fprintf(stderr, "TAC_VECTOR_AS\n"); break;
        case TAC_IFZ: fprintf(stderr, "TAC_IFZ\n"); break;
        case TAC_LABEL: fprintf(stderr, "TAC_LABEL\n"); break;
        case TAC_LESS: fprintf(stderr, "TAC_LESS\n"); break;
        case TAC_GREAT: fprintf(stderr, "TAC_GREAT\n"); break;
        case TAC_ID_POINTER: fprintf(stderr, "TAC_ID_POINTER\n"); break;
        case TAC_ID_ADDRESS: fprintf(stderr, "TAC_ID_ADDRESS\n"); break;
        case TAC_VECTOR: fprintf(stderr, "TAC_VECTOR\n"); break;
        default: fprintf(stderr, "WEIRD TAC TYPE ON FUNCTION print_tac\n"); break;
    }

}
