%{
#include "y.tab.h"
%}

%%
[a] {
    return A;
}
[b] {
    return B;
}
[c] {
    return C;
}
[\n] {
    return NL;
}
. {
    return LEX_ERROR;
}
%%

int yywrap(){
    return 1;
}