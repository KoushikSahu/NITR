%{
#include "y.tab.h"
%}

%%
[-] {return HYPHEN;}
[01]+ {
    yylval.string=strdup(yytext); 
    return BIN;
}
[\n] {return NL;}
. {return LEX_ERROR;}
%%

int yywrap(){
    return 1;
}