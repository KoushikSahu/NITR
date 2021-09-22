%{
#include "y.tab.h"
%}

%%
"@ARTICLE" {
    return article_blk;
}
"@BOOK" {
    return book_blk;
}
"@INPROCEEDINGS" {
    return inproceeding_blk;
}
"article" {
    return article;
}
"author" {
    return author;
}
"title" {
    return title;
}
"journal" {
    return journal;
}
"year" {
    return year;
}
"page" {
    return page;
}
"volume" {
    return volume;
}
"publisher" {
    return publisher;
}
"editor" {
    return editor;
}
"book" {
    return book;
}
"inproceedings" {
    return inproceedings;
}
"series" {
    yylval.string = "series";
    return series;
}
"full" {
    yylval.string = "full";
    return full;
}
"minimal" {
    yylval.string = "minimal";
    return minimal;
}
"crossref" {
    yylval.string = "crossref";
    return crossref;
}
[\n] {
    return NL;
}
[\t] {
    return TAB;
}
[{] {
    return OPEN;
}
[}] {
    return CLOSE;
}
[=] {
    return EQ;
}
[,] {
    return COMMA;
}
[-] {
    return HYPHEN;
}
[ 0-9]+ {
    yylval.number = atoi(yytext);
    return NUMBER;
}
[ a-zA-Z0-9]+ {
    yylval.string = strdup(yytext);
    return ALPHANUM;
}

%%

int yywrap(){
    return 1;
}