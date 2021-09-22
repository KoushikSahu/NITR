%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
int yyerror();
%}

%token article_blk book_blk inproceeding_blk article title journal year page volume publisher editor series full minimal crossref NL TAB OPEN CLOSE EQ COMMA SPACE HYPHEN DIG author LETTER book inproceedings

%%
P: A P | B P | I P | A | B | I ;
A: article_blk BLK1 ;
B: book_blk BLK2 ;
I: inproceeding_blk BLK3 ;
BLK1: OPEN article HYPHEN STEXT COMMA NL author EQ OPEN TEXT CLOSE COMMA NL title EQ OPEN ALPHANUM CLOSE COMMA NL journal EQ OPEN TEXT CLOSE COMMA NL year EQ NUMBER COMMA NL page EQ NUMBER COMMA NL CLOSE NL ;
BLK2: OPEN book HYPHEN STEXT COMMA NL author EQ OPEN TEXT CLOSE COMMA NL title EQ OPEN ALPHANUM CLOSE COMMA NL volume EQ DIG COMMA NL publisher EQ OPEN TEXT CLOSE COMMA NL CLOSE NL ;
BLK3: OPEN inproceedings HYPHEN STEXT COMMA NL author EQ OPEN TEXT CLOSE COMMA NL title EQ OPEN ALPHANUM CLOSE COMMA NL editor EQ OPEN TEXT CLOSE COMMA NL series EQ OPEN TEXT CLOSE COMMA NL year EQ NUMBER COMMA NL publisher EQ OPEN ALPHANUM CLOSE COMMA NL CLOSE NL ;
NUMBER: DIG NUMBER | DIG ;
STEXT: full | minimal | crossref | journal ;
TEXT: LETTER TEXT | SPACE TEXT | LETTER | SPACE ;
ALPHANUM: LETTER ALPHANUM | DIG ALPHANUM | SPACE ALPHANUM | LETTER | DIG | SPACE ;
%%

int yyerror(char* msg){
    printf("%s!\n", msg);
    exit(0);
}

int main(){
    printf("Enter the bibtex file\n");
    yyparse();
    printf("Accepted bibtex file. No errors found\n");
    exit(0);
}