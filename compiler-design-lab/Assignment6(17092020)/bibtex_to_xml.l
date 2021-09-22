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
    return series;
}
"full" {
    return full;
}
"minimal" {
    return minimal;
}
"crossref" {
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
[ ] {
    return SPACE;
}
[0-9] {
    return DIG;
}
[a-zA-Z] {
    return LETTER;
}
%%

int yywrap(){
    return 1;
}