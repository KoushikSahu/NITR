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
    Created: 21 Sep 2020 15:28:10
*/

int main() {
    int fd[2];
    pipe(fd);
    pid_t p = fork();
    if(p>0){
        p=fork();
        if(p==0){
            dup2(fd[0], 0);
            close(fd[1]);
            char* args[] = {"wc", "-l", NULL};
            execvp(args[0], args);
            return 0;
        }else{
            close(fd[0]);
            close(fd[1]);
            wait(NULL);
        }
    }else{ 
        dup2(fd[1], 1);
        close(fd[0]);
        char* args[] = {"ls", "-l", NULL};
        execvp(args[0], args);
        return 0;
    }
    return 0;
}