%{
#include "y.tab.h"
%}

%%
[Tt] {yylval=1;
return TRUE;
}
[Ff] {yylval=0;
return FALSE;
}
[A-Za-z]{1} {return VAR;}
[~] {return NOT;}
"/\\" {return AND;}
"\\/" {return OR;}
"->" {return IMP;}
"<->" {return IFF;}
[(] {return LEFT;}
[)] {return RIGHT;}
"\n" {return NL;}
%%

int yywrap(){
    return 1;
}