#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

const int SIZE = 10;

int main() {
    char non_terminal, alpha, beta;  
    int count;  
    char productions[10][SIZE];  
    int index=3;
    printf("Enter Number of Production: ");  
    scanf("%d",&count);  
    printf("Enter the grammar as E->E-A:\n");
    for(int i=0;i<count;i++){
        scanf("%s", productions[i]);  
    }
    for(int i=0; i<count; i++){
        printf("\nGrammar: %s", productions[i]);  
        non_terminal = productions[i][0];
        if(non_terminal==productions[i][index]) {  
            alpha=productions[i][index+1];  
            printf(" is left recursive\n");  
            while(productions[i][index]!=0 && productions[i][index]!='|')
                index++;          
            if(productions[i][index]!=0) {  
                beta = productions[i][index+1];
                printf("Grammar without left recursion:\n");
                printf("%c->%c%c\'", non_terminal, beta, non_terminal);
                printf("\n%c\'->%c%c\'|E\n", non_terminal, alpha, non_terminal);
            }
            else{
                printf(" can't be reduced\n");  
            }
        }else{
            printf(" is not left recursive\n");  
        }
        index = 3;
    }
    return 0;
}