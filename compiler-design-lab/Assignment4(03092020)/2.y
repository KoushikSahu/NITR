%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
int yyerror();
%}

%token A I B T E NL

%%
stmt: S NL { printf("Valid string\n"); 
			exit(0); } 
; 
S : I C T S E S | I C T S | A
; 
C : B
;
%%

int yyerror(char* msg){
    printf("Invalid string entered\n");
    exit(0);
}

int main(){
    printf("Enter string\n");
    yyparse();
}