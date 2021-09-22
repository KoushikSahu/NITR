#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

/*
    Author: Koushik Sahu
    Created: 28 Sep 2020 15:07:08
*/

pid_t p;

int main(int argc, char* argv[]) {
    p = fork();
    if(p>0){
        wait(NULL);
        printf("Parent (PID=%d): done\n", getppid());
    }else if(p<0){
        printf("Couldn't create child process\n");
        exit(0);
    }else{
        char* args[] = {"./expoxch.out", argv[1], argv[2], NULL};
        execvp(args[0], args);
    }
    return 0;
}