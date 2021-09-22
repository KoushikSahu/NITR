%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
int yyerror();
%}

%union {
    int number;
    char* string;
}

%token article_blk book_blk inproceeding_blk article title journal year page volume publisher editor series full minimal crossref NL TAB OPEN CLOSE EQ COMMA HYPHEN NUMBER author ALPHANUM book inproceedings

%%
P: A P | B P | I P | A | B | I ;
A: article_blk BLK1 ;
B: book_blk BLK2 ;
I: inproceeding_blk BLK3 ;
BLK1: OPEN article HYPHEN STEXT COMMA NL author EQ OPEN ALPHANUM CLOSE COMMA NL title EQ OPEN ALPHANUM CLOSE COMMA NL journal EQ OPEN ALPHANUM CLOSE COMMA NL year EQ NUMBER COMMA NL page EQ NUMBER COMMA NL CLOSE NL {
    printf("<ARTICLE>\n");
    printf("\t<article>");
    printf("%s", $<string>4);
    printf("</article>\n");
    printf("\t<author>");
    printf("%s", $<string>10);
    printf("</author>\n");
    printf("\t<title>");
    printf("%s", $<string>17);
    printf("</title>\n");
    printf("\t<journal>");
    printf("%s", $<string>24);
    printf("</journal>\n");
    printf("\t<year>");
    printf("%d", $<number>30);
    printf("</year>\n");
    printf("\t<page>");
    printf("%d", $<string>35);
    printf("</page>\n");
    printf("<\ARTICLE>\n");
};
BLK2: OPEN book HYPHEN STEXT COMMA NL author EQ OPEN ALPHANUM CLOSE COMMA NL title EQ OPEN ALPHANUM CLOSE COMMA NL volume EQ NUMBER COMMA NL publisher EQ OPEN ALPHANUM CLOSE COMMA NL CLOSE NL {
    printf("<BOOK>\n");
    printf("\t<book>");
    printf("%s", $<string>4);
    printf("</book>\n");
    printf("\t<author>");
    printf("%s", $<string>10);
    printf("</author>\n");
    printf("\t<title>");
    printf("%s", $<string>17);
    printf("</title>\n");
    printf("\t<volume>");
    printf("%d", $<number>23);
    printf("</volume>\n");
    printf("\t<publisher>");
    printf("%s", $<string>29);
    printf("</publisher>\n");
    printf("<\BOOK>\n");
};
BLK3: OPEN inproceedings HYPHEN STEXT COMMA NL author EQ OPEN ALPHANUM CLOSE COMMA NL title EQ OPEN ALPHANUM CLOSE COMMA NL editor EQ OPEN ALPHANUM CLOSE COMMA NL series EQ OPEN ALPHANUM CLOSE COMMA NL year EQ NUMBER COMMA NL publisher EQ OPEN ALPHANUM CLOSE COMMA NL CLOSE NL {
    printf("<INPROCEEDINGS>\n");
    printf("\t<inproceedings>");
    printf("%s", $<string>4);
    printf("</proceedings>\n");
    printf("\t<author>");
    printf("%s", $<string>10);
    printf("</author>\n");
    printf("\t<title>");
    printf("%s", $<string>17);
    printf("</title>\n");
    printf("\t<editor>");
    printf("%s", $<string>24);
    printf("</editor>\n");
    printf("\t<series>");
    printf("%s", $<string>31);
    printf("</series>\n");
    printf("\t<series>");
    printf("%d", $<number>37);
    printf("</series>\n");
    printf("\t<series>");
    printf("%s", $<string>43);
    printf("</series>\n");
    printf("<\INPROCEEDINGS>\n");
};
STEXT: full | minimal | crossref | journal ;
%%

int yyerror(char* msg){
    printf("%s!\n", msg);
    exit(0);
}

int main(){
    printf("Enter the bibtex file\n");
    printf("<document>\n");
    yyparse();
    printf("</document>\n");
    printf("Accepted bibtex file. No errors found\n");
    exit(0);
}