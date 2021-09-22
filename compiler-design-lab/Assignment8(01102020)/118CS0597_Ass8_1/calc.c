#include "calc.h"

char*
get_tmp() {
	static int i = 1;
	char* tmp = (char*)malloc(8 * sizeof(char));
	sprintf(tmp, "t%d", i++);
	return tmp;
}

char*
gen(char op, char* arg1, char* arg2) {
	if(op == '=') {
		fprintf(yyout, "%s %c %s\n", arg1, op, arg2);
		return NULL;
	}
	char* tmp = get_tmp();
	if(arg2)
		fprintf(yyout, "%s = %s %c %s\n", tmp, arg1, op, arg2);
	else
		fprintf(yyout, "%s = %c %s\n", tmp, op, arg1);
	return tmp;
}

void
yyerror(char *s, ...) {
	va_list ap;
	va_start(ap, s);

	fprintf(stderr, "%s:%d: error: ", infile, yylineno);
	vfprintf(stderr, s, ap);
	fprintf(stderr, "\n");

	va_end(ap);
}

int
yywrap() {
	return 1;
}

int
main(int argc, char** argv) {
	if(argc < 2) {
		fprintf(stderr, "Usage: calc [FILE]...\n");
		return 1;
	}
	for(int i = 1; i < argc; ++i){
		if(!(yyin = fopen(argv[i], "r"))) {
			perror(argv[i]);
			continue;
		}
		
		infile = argv[i];
		outfile = (char*)malloc(sizeof(char) * (strlen(argv[i] + 5)));
		sprintf(outfile, "out_%s", argv[i]);

		if(!(yyout = fopen(outfile, "w"))){
			perror(outfile);
			continue;
		}
		yylineno = 1;
		yyparse();

		fclose(yyin);
		fclose(yyout);
	}
	return 0;
}
