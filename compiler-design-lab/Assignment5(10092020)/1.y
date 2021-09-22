%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int yylex();
int yyerror();
%}

%token NUMBER ADD MUL NL

%left ADD
%left MUL

%start Input

%%
Input: | Input Line ;
Line: NL | Expression NL {
    printf("Result: %d\n", $1);
    exit(0);
};
Expression:
    NUMBER { $$=$1; }
|   Expression ADD Expression { $$=$1+$3; }
|   Expression MUL Expression { $$=$1*$3; }
;
%%

int yyerror(char* msg){
    printf("Invalid Expression\n");
    exit(0);
}

int main(){
    printf("Enter expression to evaluate\n");
    if(yyparse()){
        fprintf(stderr, "Successful parsing\n");
    }else{
        fprintf(stderr, "Error found\n");
    }
}