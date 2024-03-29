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
    TAC *t1, *t2, *t3, *t4, *t5, *t6, *t7, *t8;
	TAC *tac_temp;
	hashNode *label, *label2, *temp;
    
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
			if (new_code[2] != NULL) {
				node->id->has_init_values = 1;
			}
			t1 = tac_create(TAC_VEC_DEF, node->id, new_code[1]->result, NULL);
			return tac_join(t1, new_code[2]); // join vec def with init values
			break;
		case AST_INIT_VALUES:
			t1 = tac_create(TAC_VEC_INIT, new_code[1]->result, NULL, NULL);
			return tac_join(new_code[0], t1);
        case AST_FUNCTION_DEF: 
			t1 = tac_create(TAC_FUN_END, new_label(), NULL, NULL);
			return tac_join(new_code[0], tac_join(new_code[1], t1)); //tac_join(new_code[1], new_code[0]); 
			break;
        case AST_HEADER: 
			t1 = tac_create(TAC_FUN_BEGIN, node->id, NULL, NULL);
			return tac_join(t1, new_code[1]);//, t1);
			break;
        case AST_DEF_PARAM_T: 
			t1 = tac_create(TAC_PARAM_DEF, node->id, NULL, NULL);
			return tac_join(t1, new_code[1]);
			break;
        case AST_BLOCK: 
			return new_code[0]; 
			break;
        case AST_COMMANDS_L:
			return tac_join(new_code[1], new_code[0]);
			break;
        case AST_VAR_AS: 
			t1 = tac_create(TAC_VAR_AS, node->id, new_code[0]->result, NULL);
			return tac_join(new_code[0], t1);//tac_join(new_code[0], t1);
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
	        t1 =  tac_create(TAC_PRINT, node->id?node->id:new_code[1]->result, NULL, NULL);
			if (new_code[1] != NULL) {
				return tac_join(new_code[0], tac_join(new_code[1], t1));	
			}
            return tac_join(new_code[0], t1);
            break;
        case AST_RETURN: 
            t1 = tac_create(TAC_RETURN, new_label(), new_code[0]->result, NULL);
            return tac_join(new_code[0], t1);
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
			t1 = tac_create(TAC_VECTOR, new_temp(), node->id, new_code[0]->result);
			return tac_join(new_code[0], t1);
			break;
        case AST_FUNCTION: 
			t1 = tac_create(TAC_FUN_CALL, new_temp(), node->id, NULL); //call
            t2 = tac_join(new_code[0],t1); //args + call
            //return tac_join(t1,t2);
            return t2;
			break;
        case AST_PARAM: 
            //print_astnode(node);
			if (new_code[1]) {
	            t1 = tac_create(TAC_PARAM, new_code[1]->result, NULL ,NULL); //parameters_list_tail ',' expression
	            return tac_join(new_code[0], t1); //{$$=astree_create(AST_PARAM,0,$1,$3,0,0);}
			} else {
				return tac_create(TAC_PARAM, new_code[0]->result, NULL, NULL);
			}
            break;
        case AST_IF: 
			// order: condition, ifz(label), new_code1, JUMP(label2), label, new_code2, label2
			// order without else: condition, ifz(label), new_code1, label
			// if result is zero, jump to new_label
			label = new_label();

			// calculate condition and test the result in the if
			t1 = tac_join(new_code[0], tac_create(TAC_IFZ, new_code[0]->result, label, NULL));
			t2 = tac_join(t1, new_code[1]);
			// else case
			if (new_code[2] != NULL) {
				label2 = new_label();
				t3 = tac_join(tac_create(TAC_JUMP, label2, NULL, NULL), tac_create(TAC_LABEL, label, NULL, NULL));
				t4 = tac_join(t3, tac_join(new_code[2], tac_create(TAC_LABEL, label2, NULL, NULL)));
			} else {
				t4 = tac_create(TAC_LABEL, label, NULL, NULL);	
			}
			return tac_join(t2, t4);
			break;
        case AST_FOR: 
            //print_astnode(node);
            //KW_FOR '(' TK_IDENTIFIER '=' expression KW_TO expression ')' simple_command
            //{$$=astree_create(AST_FOR,$3,$5,$7,$9,0);}
			// order: label, new_code0, VAR_AS(id, res0), new_code1, SUB(id, res1), 
			// 						IFZ(label2), new_code2, JUMP(label), label2
            label = new_label();
			label2 = new_label();
            //assignment
            t1 = tac_create(TAC_VAR_AS, node->id, new_code[0]->result, NULL);
            //beginning label
            t2 = tac_create(TAC_LABEL, label, NULL, NULL);
            //comparison with jump to ending label
            // binary_op joins both operands
            t3 = tac_create(TAC_SUB, new_temp(), new_code[1]->result, node->id); 
            t4 = tac_create(TAC_IFZ, t3->result, label2, NULL);
			
			t7 = tac_create(TAC_INC, node->id, NULL, NULL);
			//t8 = tac_create(TAC_VAR_AS, node->id, t7->result, NULL);
            //here goes the code
            //jump 
            t5 = tac_create(TAC_JUMP, label, NULL, NULL);
            //ending label
			t6 = tac_create(TAC_LABEL, label2, NULL, NULL);

            return tac_join(t1, 
				tac_join(t2, 
				tac_join(new_code[0], 
				tac_join(t3, 
				tac_join(t4,
				tac_join(new_code[2], 
				tac_join(t7, 
				tac_join(t5, t6)))))))); 
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
        case TAC_FUN_BEGIN: fprintf(stderr, "TAC_FUN_BEGIN(%s,_,_)\n", tac->result->id); break;
        case TAC_FUN_END: fprintf(stderr, "TAC_FUN_END\n"); break;
        case TAC_FUN_ARG: fprintf(stderr, "TAC_FUN_ARG\n"); break;
        case TAC_FUN_CALL: fprintf(stderr, "TAC_FUN_CALL(%s,%s,_)\n", tac->result->id, tac->op1->id); break;
        case TAC_VAR_DEF: fprintf(stderr, "TAC_VAR_DEF(%s,_,_)\n", tac->result->id); break;
        case TAC_VEC_DEF: fprintf(stderr, "TAC_VEC_DEF(%s,%s,_)\n", tac->result->id, tac->op1->id); break;
        case TAC_POINTER_DEF: fprintf(stderr, "TAC_POINTER_DEF\n"); break;
        case TAC_PRINT: fprintf(stderr, "TAC_PRINT(%s,_,_)\n", tac->result->id); break;
        case TAC_READ: fprintf(stderr, "TAC_READ(%s,_,_)\n", tac->result->id); break;
        case TAC_ADD: fprintf(stderr, "TAC_ADD(%s,%s,%s)\n", tac->result->id, tac->op1->id, tac->op2->id); break;
        case TAC_SUB: fprintf(stderr, "TAC_SUB(%s,%s,%s)\n", tac->result->id, tac->op1->id, tac->op2->id); break;
        case TAC_MUL: fprintf(stderr, "TAC_MUL(%s,%s,%s)\n", tac->result->id, tac->op1->id, tac->op2->id); break;
        case TAC_DIV: fprintf(stderr, "TAC_DIV(%s,%s,%s)\n", tac->result->id, tac->op1->id, tac->op2->id); break;
        case TAC_NEG: fprintf(stderr, "TAC_NEG(%s,%s,_)\n", tac->result->id, tac->op1->id); break;
        case TAC_AND: fprintf(stderr, "TAC_AND(%s,%s,%s)\n", tac->result->id, tac->op1->id, tac->op2->id); break;
        case TAC_OR: fprintf(stderr, "TAC_OR(%s,%s,%s)\n", tac->result->id, tac->op1->id, tac->op2->id); break;
        case TAC_NOT: fprintf(stderr, "TAC_NOT(%s,%s,_)\n", tac->result->id, tac->op1->id); break;
        case TAC_EQ: fprintf(stderr, "TAC_EQ(%s,%s,%s)\n", tac->result->id, tac->op1->id, tac->op2->id); break;
        case TAC_NEQ: fprintf(stderr, "TAC_NEQ(%s,%s,%s)\n", tac->result->id, tac->op1->id, tac->op2->id); break;
        case TAC_LEQ: fprintf(stderr, "TAC_LEQ(%s,%s,%s)\n", tac->result->id, tac->op1->id, tac->op2->id); break;
        case TAC_GEQ: fprintf(stderr, "TAC_GEQ(%s,%s,%s)\n", tac->result->id, tac->op1->id, tac->op2->id); break;
        case TAC_LESS: fprintf(stderr, "TAC_LESS(%s,%s,%s)\n", tac->result->id, tac->op1->id, tac->op2->id); break;
        case TAC_GREAT: fprintf(stderr, "TAC_GREAT(%s,%s,%s)\n", tac->result->id, tac->op1->id, tac->op2->id); break;
        case TAC_JUMP: fprintf(stderr, "TAC_JUMP(%s,_,_)\n", tac->result->id); break;
        case TAC_RETURN: fprintf(stderr, "TAC_RETURN(%s,%s,_)\n", tac->result->id, tac->op1->id); break;
        case TAC_SYMBOL: break;//fprintf(stderr, "TAC_SYMBOL(%s,_,_)\n", tac->result->id); break;
        case TAC_PARAM: fprintf(stderr, "TAC_PARAM(%s,_,_)\n", tac->result->id); break;
        case TAC_PARAM_DEF: fprintf(stderr, "TAC_PARAM_DEF(%s,_,_)\n", tac->result->id); break;
        case TAC_VAR_AS: fprintf(stderr, "TAC_VAR_AS(%s,%s,_)\n", tac->result->id, tac->op1->id); break;
        case TAC_VECTOR_AS: fprintf(stderr, "TAC_VECTOR_AS(%s,%s,%s)\n", tac->result->id, tac->op1->id, tac->op2->id); break;
        case TAC_VEC_INIT: fprintf(stderr, "TAC_VEC_INIT(%s,_,_)\n", tac->result->id); break;
        case TAC_IFZ: fprintf(stderr, "TAC_IFZ(%s,%s,_)\n", tac->result->id, tac->op1->id); break;
        case TAC_LABEL: fprintf(stderr, "TAC_LABEL(%s,_,_)\n", tac->result->id); break;
        case TAC_ID_POINTER: fprintf(stderr, "TAC_ID_POINTER\n"); break;
        case TAC_ID_ADDRESS: fprintf(stderr, "TAC_ID_ADDRESS\n"); break;
        case TAC_VECTOR: fprintf(stderr, "TAC_VECTOR(%s,%s,%s)\n", tac->result->id, tac->op1->id, tac->op2->id); break;
        default: fprintf(stderr, "WEIRD TAC TYPE ON FUNCTION print_tac\n"); break;
    }

}
