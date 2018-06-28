#include "assembly_gen.h"

int tac_translate(TAC* tac, FILE* fout) {
	
}

int gen_assembly(TAC* tac_list, FILE *fout) {
	TAC* tmp = tac_list;
	for(; tmp != NULL; tmp = tmp->next) {
		tac_translate(tmp, fout);
	}
}
