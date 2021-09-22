%{
    #include <stdio.h>
    #include <stdbool.h>

    bool is_identifier = false;
%}

%%
^[_a-zA-Z][_a-zA-Z0-9]*[_a-zA-Z0-9]$ {
    is_identifier = true;
}

.* ;

\n {
    return 1;
}
%%

int yywrap(){
}

int main(){
    yylex();
    if(is_identifier){
        printf("Valid identifier name\n");
    }else{
        printf("Invalid idenifier name\n");
    }
    return 0;
}