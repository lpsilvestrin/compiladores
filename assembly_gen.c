#include "assembly_gen.h"

void trac_translate_binpop(char* op) {

}

void tac_translate(TAC* tac, FILE* fout) {
	switch(tac->type) {
	case TAC_VAR_DEF:
		fprintf(fout, "%s:\n", tac->result->id);
		fprintf(fout, "\t.long\t%s\n",tac->op1->id);
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
	case TAC_VEC_DEF: break;
	case TAC_POINTER_DEF: break;
	case TAC_PRINT: break;
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
	case TAC_VAR_AS: break;
	case TAC_VECTOR_AS: break;
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

int gen_assembly(TAC* tac_list, FILE *fout) {
	//empty program case here??

	TAC* tmp = tac_list;
	fprintf(fout, ".data\n");
	for(; tmp != NULL; tmp = tmp->next) {
		tac_translate(tmp, fout);
	}
	return 0;
}
