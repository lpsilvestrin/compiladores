#include "assembly_gen.h"


int SIZE = 4; 
/*	movl	k(%rip), %eax
	testl	%eax, %eax*/

void tac_translate_arithmetic(FILE* fout, TAC* tac, char* op) { 
	fprintf(fout, "\tmovl\t%s(%%rip), %%edx\n", tac->op1->id);
	if(strcmp(op,"neg") == 0){
		fprintf(fout, "\tmovl\t$-1, %%eax\n");
		fprintf(fout, "\timull\t%%edx, %%eax\n");
		return;
	}
	fprintf(fout, "\tmovl\t%s(%%rip), %%eax\n", tac->op2->id);
	if(strcmp(op,"idivl") == 0) {
		fprintf(fout, "\t	cltd\n");
		fprintf(fout, "\t%s\t%%eax\n", op);
		return;
	}
	fprintf(fout, "\t%s\t%%edx, %%eax\n", op);
}

void tac_translate_bool_op(FILE* fout, TAC* tac, char* op) {
	
	fprintf(fout,"\tmovl %s(%%rip), %%eax\n", tac->op1->id);
	if(strcmp(op,"notl") == 1) {
		fprintf(fout,"\tmovl %s(%%rip), %%edx\n", tac->op2->id);
		fprintf(fout,"\t%s %%eax, %%edx\n", op); //RESULT ON edx <---
 	} else {
		 fprintf(fout,"\t%s %%eax\n", op);
	 }
}

void tac_translate(TAC* tac, FILE* fout) {
	int temp1;
	switch(tac->type) {
	case TAC_VAR_DEF:
		fprintf(fout, "%s:\n", tac->result->id);
		fprintf(fout, "\t.long\t%s\n",tac->op1->value?tac->op1->value:0);
		break;
	case TAC_VEC_DEF: 
		temp1 = atoi(tac->op1->id) * SIZE; //vector size
		fprintf(fout, "\t.comm\t%s,%d,%d\n",tac->result->id, temp1, temp1); //.comm	vetor,8,8
		break;
	case TAC_FUN_BEGIN:
		fprintf(fout, "\t.globl %s\n", tac->result->id);
		fprintf(fout, "%s:\n", tac->result->id);
		fprintf(fout, "\t.cfi_startproc\n\tpushq\t%%rbp\n");
		fprintf(fout, "\tmovq\t%%rsp, %%rbp\n");
		break;
	case TAC_FUN_END:
		fprintf(fout, "\tpopq\t%%rbp\n");
		fprintf(fout, "\tret\n");
		fprintf(fout, "\t.cfi_endproc\n");
		break;	
	case TAC_FUN_ARG: break;
	case TAC_FUN_CALL: break;	
	case TAC_POINTER_DEF: break;
	case TAC_PRINT: 
		fprintf(fout, "\tmovl\t$.%s, %%edi\n", tac->result->id);
		fprintf(fout, "\tcall\tprintf\n");
		break;
	case TAC_READ: break;
	case TAC_ADD: 
		tac_translate_arithmetic(fout, tac, "addl");
		break;
	case TAC_SUB: break;
		tac_translate_arithmetic(fout, tac, "subl");
		break;
	case TAC_MUL: 
		tac_translate_arithmetic(fout, tac, "imull");
		break;
	case TAC_DIV:
		tac_translate_arithmetic(fout, tac, "idivl"); 
		break;
	case TAC_NEG: 
		tac_translate_arithmetic(fout, tac, "neg"); 
		break;
	case TAC_AND: 
		tac_translate_bool_op(fout, tac, "andl");
		break;
	case TAC_OR: 
		tac_translate_bool_op(fout, tac, "orl");
		break;
	case TAC_NOT: 
		tac_translate_bool_op(fout, tac, "notl");
		break;
	case TAC_EQ: break;
	case TAC_NEQ: break;
	case TAC_LEQ: break;
	case TAC_GEQ: break;
	case TAC_LESS: break;
	case TAC_GREAT: break;
	case TAC_JUMP: break;
	case TAC_RETURN: break;
	case TAC_SYMBOL: break;
	case TAC_VAR_AS: 
		fprintf(fout, "\tmovl\t$%s, %s(%%rip)\n", tac->op1->value, tac->result->value);
		break;
	case TAC_VECTOR_AS: 
		temp1 = atoi(tac->op1->value) * SIZE;
		fprintf(fout, "\tmovl\t$%s, %s+%d(%%rip)\n", tac->op2->value, tac->result->value, temp1);
		break;
	case TAC_IFZ:  //FIX: temp0 should be replaced by a register :)
		fprintf(fout, "\tmovl\t %s(%%rip) %%ebx\n", tac->result->id);
		fprintf(fout, "\tcmpl\t %%ebx %%ebx\n");
		fprintf(fout, "\tje\t .%s\n", tac->op1->id);
		break;
	case TAC_LABEL: 
		fprintf(fout, ".%s:\n", tac->result->id);
		break;
	case TAC_ID_POINTER: break;
	case TAC_ID_ADDRESS: break;
	case TAC_VECTOR: // case TAC_VECTOR:(temp,vetor,index) 
		temp1 = atoi(tac->op2->value) * SIZE;
		fprintf(fout, "\tmovl\t$%%edi, %s+%d(%%rip)\n", tac->op1->id, temp1);
		break;
	case TAC_PARAM: break;
	default: 
		break;
	}	
}

void gen_empty_program(FILE *fout) {
	fprintf(fout, "\t.globl main\n");
	fprintf(fout, "main:\n");
	fprintf(fout, "\t.cfi_startproc\n\tpushq\t%%rbp\n");
	fprintf(fout, "\tmovq\t%%rsp, %%rbp\n");
	fprintf(fout, "\tpopq\t%%rbp\n");
	fprintf(fout, "\tret\n");
	fprintf(fout, "\t.cfi_endproc\n");
}

void gen_hash(hashTable *table, FILE *fout) { //all the constants must be declared before the functions
	hashNode* currNode = NULL;
	int size = table->size;
	for (int i = 0; i < size; i++) {
		currNode = table->data[i];
		if(currNode != NULL){
			switch(currNode->type){
				case SYMBOL_LIT_INT:
					fprintf(fout, ".%s:\n", currNode->id); //.long
					fprintf(fout, "\t.long %s\n", currNode->value);
					break;
				case SYMBOL_LIT_FLOAT:
					fprintf(fout, ".%s:\n", currNode->id); //.long
					fprintf(fout, "\t.long %s\n", currNode->value); 
					break;
				case SYMBOL_LIT_CHAR:
					fprintf(fout, ".%s:\n", currNode->id); //.byte
					break;
				case SYMBOL_LIT_STRING:
					fprintf(fout, ".%s:\n", currNode->id);
					fprintf(fout, "\t.string %s\n", currNode->value);
					break;
				default:
					break;
				}}
			}
} 

int gen_assembly(TAC* tac_list, hashTable *table, FILE *fout) {
	TAC* tmp = tac_list;
	//fprintf(fout, ".data");
	if(tac_list == NULL) {
		gen_empty_program(fout);
		return 0;
	} 
	gen_hash(table, fout);
	for(; tmp != NULL; tmp = tmp->next) {
		tac_translate(tmp, fout);
	}
	return 0;
}
