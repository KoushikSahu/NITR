%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
int yyerror();
%}

%token TRUE FALSE VAR NOT AND OR IMP IFF LEFT RIGHT NL

%left NOT
%left IFF
%left IMP
%left AND
%left OR

%%
Input: | Input Line ;
Line: NL | Expression NL {
    printf("Valid expression\n");
    exit(0);
};
Operand: VAR | TRUE | FALSE ;
Operator: AND | OR | IMP | IFF ;
Expression: 
Operand
| Expression Operator Expression
| NOT Expression
| LEFT Expression RIGHT
; 
%%

int yyerror(char* msg){
    printf("Invalid expression\n");
    exit(0);
}

int main(){
    printf("Enter the expression\n");
    yyparse();
}