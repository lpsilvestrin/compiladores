#include "assembly_gen.h"

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
	}	
}

int gen_assembly(TAC* tac_list, FILE *fout) {
	TAC* tmp = tac_list;
	fprintf(fout, ".data");
	for(; tmp != NULL; tmp = tmp->next) {
		tac_translate(tmp, fout);
	}
	return 0;
}
