%option yylineno
%{
#include "calc.h"
#include "calc.tab.h"
%}

%%
"="	|
"+"	|
"-"	|
"*"	|
"/"	|
"^"	|
"("	|
")"		{ return yytext[0]; }
[a-zA-Z0-9]+	{ yylval.s = strdup(yytext); return VAR; }
\n+		{ return EOL; }
[ \t]+		;
.		{ yyerror("Invalid character %c", *yytext); }
%%

