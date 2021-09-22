%{
#include "calc.h"
extern int yylex();
%}

%union {
	char* s;
}

/* declare tokens */
%token <s> VAR
%token EOL

/* specify precedence and associativity */
%left '+' '-'
%left '*' '/'
%right '^'
%nonassoc UMINUS

%type <s> exp

%%
line	: line stmt EOL	
     	| stmt EOL
	| error EOL		{ yyerror("Grammar error"); }
	;
stmt	: exp '=' exp		{ gen('=', $1, $3); }
     	;
exp	: exp '+' exp		{ $$ = gen('+', $1, $3); }
    	| exp '-' exp		{ $$ = gen('-', $1, $3); }
	| exp '*' exp		{ $$ = gen('*', $1, $3); }
	| exp '/' exp		{ $$ = gen('/', $1, $3); }
	| exp '^' exp		{ $$ = gen('^', $1, $3); }
	| '-' exp %prec UMINUS	{ $$ = gen('-', $2, NULL); }
	| '(' exp ')'		{ $$ = $2; }
	| VAR			{ $$ = $1; }
	;
%%

