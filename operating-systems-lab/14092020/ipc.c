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
    Created: 14 Sep 2020 14:52:02
*/

int n, fd[2];
pid_t pid;
char buf[20], *msg = "Hello world";

int main() {
    if(pipe(fd)==-1) exit(1);
    else printf("PIPE created successfully\n");
    if((pid=fork())<0){
        exit(1);
    }else if(pid>0){
        close(fd[0]);
        write(fd[1], msg, strlen(msg));
    }else{
        close(fd[1]);
        read(fd[0], buf, 20);
        puts(buf);
    }
    return 0;
}