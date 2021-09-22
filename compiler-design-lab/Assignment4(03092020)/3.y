%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
int yyerror();
%}

%token OPEN S CLOSE NL

%%
stmt: X NL {
    printf("Balanced paranthesis string\n");
    exit(0);
};
X: | OPEN X CLOSE
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