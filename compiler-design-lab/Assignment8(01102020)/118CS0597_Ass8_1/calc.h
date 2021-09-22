#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

char* infile;
char* outfile;

extern FILE* yyin;
extern FILE* yyout;
extern int yylineno;
void yyerror(char* s, ...);
int yywrap();

extern int yyparse();

char* get_tmp();
char* gen(char op, char* arg1, char* arg2);

