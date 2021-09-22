%{
#include "y.tab.h"
%}

%%
a {return A;}
i {return I;}
b {return B;}
t {return T;}
e {return E;}
\n {return NL;}
. {return yytext[0];}
%%

int yywrap(){
    return 1;
}