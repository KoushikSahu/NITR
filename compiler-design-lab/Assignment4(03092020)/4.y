%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
int yyerror();

char* inWords(int digit){
    switch(digit){
        case 0: return "zero";
            break;
        case 1: return "one";
            break;
        case 2: return "two";
            break;
        case 3: return "three";
            break;
        case 4: return "four";
            break;
        case 5: return "five";
            break;
        case 6: return "six";
            break;
        case 7: return "seven";
            break;
        case 8: return "eight";
            break;
        case 9: return "nine";
            break;
    }
}

char* inWords1(int digit){
    switch(digit){
        case 10: return "ten";
            break;
        case 11: return "eleven";
            break;
        case 12: return "twelve";
            break;
        case 13: return "thirteen";
            break;
        case 14: return "fourteen";
            break;
        case 15: return "fifteen";
            break;
        case 16: return "sixteen";
            break;
        case 17: return "seventenn";
            break;
        case 18: return "eighteen";
            break;
        case 19: return "nineteen";
            break;
    }
}

char* inWords2(int digit){
    switch(digit){
        case 0: return "";
            break;
        case 2: return "twenty";
            break;
        case 3: return "thirty";
            break;
        case 4: return "forty";
            break;
        case 5: return "fifty";
            break;
        case 6: return "sixty";
            break;
        case 7: return "seventy";
            break;
        case 8: return "eighty";
            break;
        case 9: return "ninety";
            break;
    }
}

void printInWords(int val){
    if(val<0 || val>999){
        printf("Error! Enter value between 0 and 999!\n");
    }else{
        int hundreds = -1, tens = -1, ones = -1;
        if(val) ones = val%10;
        val /= 10;
        if(val) tens = val%10;
        val /= 10;
        if(val) hundreds = val%10;
        val /= 10; 
        if(hundreds!=-1){
            printf("%s hundred ", inWords(hundreds));
        }
        if(tens==1){
            printf("%s\n", inWords1(10*tens+ones));
        }else if(tens!=-1){
            printf("%s %s\n", inWords2(tens), inWords(ones));
        }
    }
}

%}

%union{
    int num;
}

%token NUMBER NL

%%
stmt: NUMBER NL {
    printInWords($<num>1);
    exit(0);
};
%%

int yyerror(char* msg){
    printf("invalid string\n");
    exit(0);
}

int main(){
    printf("Enter the string\n");
    yyparse();
}