%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* bin_str;

int yylex();
int yyerror();
%}

%union {
    char* string;
}

%token HYPHEN BIN NL LEX_ERROR

%%
STMT: HYPHEN BIN_STR NL {printf("-");return 0;} | BIN_STR NL {return 0;} ;
BIN_STR: BIN {bin_str=$<string>1;} ;
%%

int yyerror(char* msg){
    puts(msg);
    exit(0);
}

int power(int a, int n){
    int ans = 1;
    while(n){
        if(n%2==1) ans *= a;
        a *= a;
        n /= 2;
    }
    return ans;
}

int main(){
    puts("Enter the binary string");
    yyparse();
    int ans = 0;
    for(int i=0; i<strlen(bin_str); i++){
        ans += (bin_str[i]-'0')*power(2, strlen(bin_str)-i-1);
    }
    printf("%d\n", ans);
    exit(0);
}