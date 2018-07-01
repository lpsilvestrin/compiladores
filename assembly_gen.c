#include "assembly_gen.h"


int SIZE = 4; 


void tac_translate_binop(char* op) {

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
	case TAC_ADD: break;
	case TAC_SUB: break;
	case TAC_MUL: break;
	case TAC_DIV: break;
	case TAC_NEG: break;
	case TAC_AND: break;
	case TAC_OR: break;
	case TAC_NOT: break;
	case TAC_EQ: break;
	case TAC_NEQ: break;
	case TAC_LEQ: break;
	case TAC_GEQ: break;
	case TAC_JUMP: break;
	case TAC_RETURN: break;
	case TAC_SYMBOL: break;
	case TAC_VAR_AS: 
		fprintf(fout, "\tmovl	$%s, %s(%%rip)\n", tac->op1->value, tac->result->value);
		break;
	case TAC_VECTOR_AS: 
		temp1 = atoi(tac->op1->value) * SIZE;
		//tac->result->id, tac->op1->id, tac->op2->id (name, index, value)
		fprintf(fout, "\tmovl	$%s, %s+%d(%%rip)\n", tac->op2->value, tac->result->value, temp1);
		//movl	$2, vetor(%rip) [0]
		//movl	$0, a+4(%rip)[1]
		break;
	case TAC_IFZ: break;
	case TAC_LABEL: break;
	case TAC_LESS: break;
	case TAC_GREAT: break;
	case TAC_ID_POINTER: break;
	case TAC_ID_ADDRESS: break;
	case TAC_VECTOR: break;
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
