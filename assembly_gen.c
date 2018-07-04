#include "assembly_gen.h"

int SIZE = 4; 
int TABLE_SIZE = 40;
int PAR_COUNT = 0;
ASTree* _SCOPE = NULL;

// return the position of a parameter in the current scope
int find_param_pos(hashNode* var) {
	int pos = 1;
	for (ASTree *tmp = _SCOPE; tmp != NULL; tmp = tmp->offspring[1]) {
		if (strcmp(tmp->id->id, var->id)==0) {
			return pos;
		}
		pos++;
	}
	return 0;			
}

// load an operand (either variable or "imadiato") into a register
void load_operand(FILE* fout, hashNode* op, char* reg) {
	if (strcmp(reg, "rsi")==0) {
		fprintf(fout, "\tmovq\t");
	} else {
		fprintf(fout, "\tmovl\t");
	}
	int pos = find_param_pos(op);
	// test if is a global var
	if (pos == 0) {
		fprintf(fout, ".%s(%%rip), %%%s\n", op->id, reg);
	} else {
	// var is in the stack
		fprintf(fout, "%d(%%rbp), %%%s\n", (8+8*pos), reg);

	}
}

void store_var(FILE* fout, hashNode* src, hashNode* dst) {
	int dst_pos = find_param_pos(dst);
	load_operand(fout, src, "eax");
	if (dst_pos == 0) {
		fprintf(fout, "\tmovl\t%%eax, .%s(%%rip)\n", dst->id);
	} else {
		fprintf(fout, "\tmovl\t%%eax, %d(%%rbp)\n", (8+8*dst_pos));
	}

}

void tac_translate_arithmetic(FILE* fout, TAC* tac, char* op) { 
	load_operand(fout, tac->op1, "edx");
	if(strcmp(op,"neg") == 0){
		fprintf(fout, "\tmovl\t$-1, %%eax\n");
		fprintf(fout, "\timull\t%%edx, %%eax\n");
		fprintf(fout, "\tmovl\t%%eax, .%s(%%rip)\n", tac->result->id);
		return;
	}
	load_operand(fout, tac->op2, "eax");
	if(strcmp(op,"idivl") == 0) {
		fprintf(fout, "\tcltd\n");
		fprintf(fout, "\t%s\t%%eax\n", op);
		fprintf(fout, "\tmovl\t%%eax, .%s(%%rip)\n", tac->result->id);
		return;
	}
	fprintf(fout, "\t%s\t%%edx, %%eax\n", op);
	fprintf(fout, "\tmovl\t%%eax, .%s(%%rip)\n", tac->result->id);
}

void tac_translate_cmp(FILE* fout, TAC* tac) {
	load_operand(fout, tac->op1, "eax");
	load_operand(fout, tac->op2, "edx");
	fprintf(fout, "\tcmpl\t%%edx, %%eax\n");
	switch(tac->type) {
	case TAC_EQ:
		fprintf(fout, "\tsete\t%%al\n");break;
	case TAC_NEQ: 
		fprintf(fout, "\tsetne\t%%al\n");break;
	case TAC_LEQ:
		fprintf(fout, "\tsetle\t%%al\n");break;
	case TAC_GEQ: 
		fprintf(fout, "\tsetge\t%%al\n");break;
	case TAC_LESS: 
		fprintf(fout, "\tsetl\t%%al\n"); break;
	case TAC_GREAT: 
		fprintf(fout, "\tsetg\t%%al\n"); break;
	}
	fprintf(fout, "\tmovzx\t%%al, %%eax\n");
	fprintf(fout, "\tmovl\t%%eax, .%s(%%rip)\n", tac->result->id);
	
}

void tac_translate_bool_op(FILE* fout, TAC* tac, char* op) {
	load_operand(fout, tac->op1, "eax");	
	if(strcmp(op,"notl") == 1) {
		load_operand(fout, tac->op2, "edx");	
		fprintf(fout,"\t%s %%eax, %%edx\n", op); 
		fprintf(fout, "\tmovl\t%%edx, .%s(%%rip)\n", tac->result->id);
 	} else {
		 fprintf(fout,"\t%s %%eax\n", op);
	}
	fprintf(fout, "\tmovl\t%%eax, .%s(%%rip)\n", tac->result->id);
}

void tac_translate(TAC* tac, FILE* fout) {
	int temp1;
	switch(tac->type) {
	case TAC_VAR_DEF:
		fprintf(fout, ".%s:\n", tac->result->id);
		switch(tac->result->type) {
			case SYMBOL_LIT_CHAR: 
				fprintf(fout, "\t.byte\t%d\n",tac->op1->value?tac->op1->value[1]:0);	
				break;
			case SYMBOL_LIT_INT: 
			case SYMBOL_LIT_FLOAT: 
				fprintf(fout, "\t.long\t%s\n",tac->op1->value?tac->op1->value:0);
				break;
			default: 
				fprintf(stderr, "ERROR ON assembly_gen, CASE TAC_VAR_DEF\n");
				break;
		}
		//fprintf(fout, "\t.long\t%s\n",tac->op1->value?tac->op1->value:0);
		break;
	case TAC_VEC_DEF: 
		temp1 = atoi(tac->op1->value) * SIZE; //vector size
		fprintf(fout, "\t.comm\t.%s,%d,%d\n",tac->result->id, temp1, temp1); //.comm	vetor,8,8
		break;
	case TAC_FUN_BEGIN:
		// set scope for next instructions
		_SCOPE = tac->result->list_head;
		fprintf(fout, "\t.globl %s\n", tac->result->id);
		fprintf(fout, "%s:\n", tac->result->id);
		fprintf(fout, "\t.cfi_startproc\n\tpushq\t%%rbp\n");
		fprintf(fout, "\tmovq\t%%rsp, %%rbp\n");
		break;
	case TAC_FUN_END:
		// reset scope
		_SCOPE = NULL;
		fprintf(fout, "\tpopq\t%%rbp\n");
		fprintf(fout, "\tret\n");
		fprintf(fout, "\t.cfi_endproc\n");

		break;	
	case TAC_FUN_ARG: break;
	case TAC_FUN_CALL: 
		fprintf(fout, "\tcall\t%s\n", tac->op1->id);
		fprintf(fout, "\taddq\t$%d, %%rsp\n", (PAR_COUNT*8));
		// get return value from edx
		fprintf(fout, "\tmovl\t%%edx, .%s(%%rip)\n", tac->result->id);
		PAR_COUNT = 0; // reset param_count
		break;	
	case TAC_POINTER_DEF: break;
	case TAC_PRINT:
		if (tac->result->type == SYMBOL_LIT_STRING) {
			fprintf(fout, "\tmovq\t$.%s, %%rsi\n", tac->result->id);
			fprintf(fout, "\tmovl\t$._print_string, %%edi\n");
		} else if (tac->result->type == SYMBOL_LIT_CHAR) {
			load_operand(fout, tac->result, "rsi");		
			fprintf(fout, "\tmovl\t$._print_char, %%edi\n");
			
		} else {
			load_operand(fout, tac->result, "rsi");
			//			fprintf(fout, "\tmovq\t%%eax, %%rsi\n");
			fprintf(fout, "\tmovl\t$._print_int, %%edi\n");
		}
		fprintf(fout, "\tcall\tprintf\n");
		break;
	case TAC_READ: 
		fprintf(fout, "\tmovl\t$.%s, %%esi\n",tac->result->id); //removed the $
		switch(tac->result->type) {
			case SYMBOL_LIT_CHAR: 
				fprintf(fout, "\tmovl\t$._print_string, %%edi\n");
				break;
			case SYMBOL_LIT_INT: 
				fprintf(fout, "\tmovl\t$._print_int, %%edi\n");
				break;
			case SYMBOL_LIT_FLOAT: 
				fprintf(fout, "\tmovl\t$._print_float, %%edi\n");
				break;
			default: 
				fprintf(stderr, "ERROR ON assembly_gen, CASE TAC_READ\n");
				break;
		}
		/*	movl	$k, %esi
		movl	$.LC0, %edi
		movl	$0, %eax
		call	scanf*/
		fprintf(fout, "\tmovl\t$0, %%eax\n");
		fprintf(fout, "\tcall\tscanf\n");
		//fprintf(fout, "\tmovl\t%%eax, .%s(%%rip)\n", tac->result->id);

		break;
	case TAC_ADD: 
		tac_translate_arithmetic(fout, tac, "addl");
		break;
	case TAC_SUB: 
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
	case TAC_INC:
		load_operand(fout, tac->result, "eax");
		fprintf(fout, "\taddl\t$1, %%eax\n");
		fprintf(fout, "\tmovl\t%%eax, .%s(%%rip)\n", tac->result->id);
		break;
	case TAC_EQ:
	case TAC_NEQ: 
	case TAC_LEQ: 
	case TAC_GEQ: 
	case TAC_LESS: 
	case TAC_GREAT:
		tac_translate_cmp(fout, tac);
		break;
	case TAC_JUMP: 
		fprintf(fout, "\tjmp\t.%s\n", tac->result->id);
		break;
	case TAC_RETURN: 
		// return through edx
		load_operand(fout, tac->op1, "edx");
		break;
	case TAC_SYMBOL: break;
	case TAC_VAR_AS: 
		store_var(fout, tac->op1, tac->result);
		break;
	case TAC_VECTOR_AS: 
		temp1 = atoi(tac->op1->value) * SIZE;
		fprintf(fout, "\tmovl\t$%s, .%s+%d(%%rip)\n", tac->op2->value, tac->result->value, temp1);
		break;
	case TAC_IFZ: 
		fprintf(fout, "\tmovl\t .%s(%%rip), %%ebx\n", tac->result->id);
		fprintf(fout, "\ttest\t %%ebx, %%ebx\n");
		fprintf(fout, "\tje\t .%s\n", tac->op1->id);
		break;
	case TAC_LABEL: 
		fprintf(fout, ".%s:\n", tac->result->id);
		break;
	case TAC_ID_POINTER: break;
	case TAC_ID_ADDRESS: break;
	case TAC_VECTOR: // case TAC_VECTOR:(temp,vetor,index) 
		temp1 = atoi(tac->op2->value) * SIZE;
		fprintf(fout, "\tmovl\t%%edi, .%s+%d(%%rip)\n", tac->op1->id, temp1);
		break;
	case TAC_PARAM: 
		load_operand(fout, tac->result, "eax");
		fprintf(fout, "\tpushq\t%%rax\n");
		PAR_COUNT++;
		//fprintf(fout, "\tmovl\t%%eax, -%d(%%rsp)\n", (++PAR_COUNT)*4);
		break;
	case TAC_PARAM_DEF: break;
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
		for (currNode = table->data[i]; currNode != NULL; currNode = currNode->next) {
		if(currNode->scan_type != SYMBOL_IDENTIFIER){
			switch(currNode->type){
				case SYMBOL_TEMP:
					// allocate a position for temporary expressions
					fprintf(fout, ".%s:\n", currNode->id); //.long
					fprintf(fout, "\t.long 0\n");
					break;
				case SYMBOL_LIT_INT:
					fprintf(fout, ".%s:\n", currNode->id); //.long
					fprintf(fout, "\t.long %s\n", currNode->value);
					break;
				case SYMBOL_LIT_FLOAT:
					fprintf(fout, ".%s:\n", currNode->id); //.long
					fprintf(fout, "\t.long %s\n", currNode->value); 
					break;
				case SYMBOL_LIT_CHAR:
					fprintf(fout, ".%s:\n", currNode->id);
					fprintf(fout, "\t.byte %d\n", currNode->value[1]);
					break;
				case SYMBOL_LIT_STRING:
					fprintf(fout, ".%s:\n", currNode->id);
					fprintf(fout, "\t.string %s\n", currNode->value);
					break;
				default:
					break;
			}
		}
		}
	}
} 

void print_flags(FILE *fout) {
	fprintf(fout, "._print_int:\n");
	fprintf(fout, "\t.string \"%%d\"\n");
	fprintf(fout, "._print_string:\n");
	fprintf(fout, "\t.string \"%%s\"\n");
	fprintf(fout, "._print_float:\n");
	fprintf(fout, "\t.string \"%%f\"\n");
	fprintf(fout, "._print_char:\n");
	fprintf(fout, "\t.string \"%%c\"\n");
}

int gen_assembly(TAC* tac_list, hashTable *table, FILE *fout) {
	TAC* tmp = tac_list;

	if(tac_list == NULL) {
		gen_empty_program(fout);
		return 0;
	} 
	fprintf(fout, "\t.data\n");
	print_flags(fout);
	gen_hash(table, fout);
	for(; tmp != NULL; tmp = tmp->next) {
		tac_translate(tmp, fout);
	}
	return 0;
}
