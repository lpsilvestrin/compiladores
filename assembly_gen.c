#include "assembly_gen.h"

void tac_translate(TAC* tac, FILE* fout) {
	switch(tac->type) {
	case TAC_VAR_DEF:
		fprintf(fout, "%s:\n", tac->result->id);
		fprintf(fout, "\t.long\t%s\n",tac->op1->id);
		break;
	}	
}

int gen_assembly(TAC* tac_list, FILE *fout) {
	TAC* tmp = tac_list;
	for(; tmp != NULL; tmp = tmp->next) {
		tac_translate(tmp, fout);
	}
	return 0;
}
