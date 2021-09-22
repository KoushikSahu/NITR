%{
#include "y.tab.h"
%}

%%
[0-9]+ {yylval=atoi(yytext);
return NUMBER;}
"+" {return ADD;}
"*" {return MUL;}
\n {return NL;}
. {return yytext[0];}
%%

int yywrap(){
    return 1;
}