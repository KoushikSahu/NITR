%{
#include <stdio.h>
#include <stdlib.h>

int a_cnt = 0, b_cnt = 0, c_cnt = 0;

int yylex();
int yyerror();
%}

%token A B C NL LEX_ERROR

%%
STMT: STR NL {return 0;};
STR: PREFIX ;
PREFIX: A {a_cnt++;} | A PREFIX {a_cnt++;} | A MID {a_cnt++;} | LEX_ERROR {
    printf("Lex error! Enter only a, b, c or newline(Enter)!\n");
    exit(0);       
};
MID: B {b_cnt++;} | B MID {b_cnt++;} | B SUFFIX {b_cnt++;} | LEX_ERROR {
    printf("Lex error! Enter only a, b, c or newline(Enter)!\n");
    exit(0);       
};
SUFFIX: C {c_cnt++;} | C SUFFIX {c_cnt++;} | LEX_ERROR {
    printf("Lex error! Enter only a, b, c or newline(Enter)!\n");
    exit(0);       
};
%%

int yyerror(char* msg){
    puts(msg);
    exit(0);
}

int main(){
    puts("Enter the string to test for grammar a^nb^nc^n");
    yyparse();
    if(a_cnt==b_cnt && b_cnt==c_cnt){
        puts("String is accepted and satisfies the grammar");
    }else{
        puts("Count of a, b and c is not same");
    }
}