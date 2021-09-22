#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

const int SIZE = 10;

int main() {
    char non_terminal;
    int count;
    char productions[10][SIZE];
    printf("Number of productions: ");
    scanf("%d", &count);
    printf("Enter the grammar as E->E-A: \n");
    for(int i=0; i<count; i++){
        scanf("%s", productions[i]);
    }
    for(int i=0; i<count; i++){
        int index = 3;
        printf("Grammar: %s", productions[i]);
        non_terminal = productions[i][0];
        bool isLeftRecursive = false;
        for(int j=0; j<strlen(productions[i]); j++){
            if(productions[i][j]=='>' || productions[i][j]=='|'){
                if(productions[i][j+1]==non_terminal) isLeftRecursive = true;
            }
        }
        if(isLeftRecursive) printf(" is left recursive\n");
        else printf(" is not left recursive\n");
    }
    return 0;
}