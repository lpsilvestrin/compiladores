

int main(int argc, char** argv) {
	if (argc < 2) {
		printf("nome do arquivo inválido");
		exit(1);
	}
	yyin = fopen(argv[1], "r");
	int res = yylex();
	while (res != 0) {
		printf("achou %d\n", res);
		res = yylex();
	}

	fclose(yyin);
	exit(0);
}
