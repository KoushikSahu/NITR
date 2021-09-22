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



int main() {
    int i;
    pid_t p = fork();
    if(p>0){
        wait(NULL);
        printf("\nI am parent of PID %d", p);
        sleep(3);
        return 0;
    }else if(p==0){
        for(int i=0; i<5; i++){
            printf("\nMy PID is %d", getpid());
            printf("\nMy parent PID is %d", getppid());
            sleep(1);
        }
    }
    return 0;
}