#import <stdlib.h>
#import <stdio.h>


extern int running;
extern int lineNumber;
extern FILE *yyin;
extern void tokenTreatment(int tk_code);
extern int yylex();


int main(int argc, char** argv) {
	if (argc < 2) {
		printf("Usage: etapa1 <file>");
		exit(1);
	}
	yyin = fopen(argv[1], "r");
  int res = yylex();
  while(res){
      tokenTreatment(res);
      //printf("achei algo, mas to com preguica\n");
      res = yylex();
      }
	/*while (res != 0) {
		printf("achou %d\n", res);
		res = yylex();
	}*/



	fclose(yyin);
	return 0;
}
