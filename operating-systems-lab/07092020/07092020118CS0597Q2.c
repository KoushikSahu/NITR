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

int n;

int main() {
    printf("Enter the number of processes to be created in chain\n");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        pid_t p = fork();
        if(p==0){
            printf("Parent process:%d\tChild process:%d\n", getppid(), getpid());
            continue;
        }else{
            wait(NULL);
            return 0;
        }
    }
}