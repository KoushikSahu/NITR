#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/*
    Author: Koushik Sahu
    Created: 31 August 2020 Mon 14:46:02
*/

void createProcessTree(int depth, int degree){
    if(depth>0){
        for(int i=0; i<degree; i++){
            pid_t p = fork();
            if(p==0){
                createProcessTree(depth-1, degree);
                return ;
            }else{
                wait(NULL);
                continue;
            }
        }
    }
    printf("Parent process:%d\tChild process:%d\n", getppid(), getpid());
}

int main() {
	printf("--------------------------------------------------------------------------------------\n");
	printf("Note: If the depth is n, the longest path from root to leaf would have n processes\n");
	printf("Eg: If depth is 1, then there is 1 process no matter what degree is passed\n");
	printf("--------------------------------------------------------------------------------------\n");
	printf("\n");
    int depth, degree;
    printf("Enter the required depth: ");
    scanf("%d", &depth);
    printf("Enter the required degree: ");
    scanf("%d", &degree);
    createProcessTree(depth-1, degree);
    return 0;
}
