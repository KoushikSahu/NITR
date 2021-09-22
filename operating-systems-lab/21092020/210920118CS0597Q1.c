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
    Created: 21 Sep 2020 13:30:12
*/

int main() {
    int fd[2];
    int response = pipe(fd);
    if(response==-1) exit(0);
    char line[100];
    pid_t p = fork();
    if(p<0) exit(0);
    else if(p>0){
        char c_pid[100];
        sprintf(c_pid, "%d", p);
        char hello[] = "Hello ";
        strcat(hello, c_pid);
        write(fd[1], hello, strlen(hello));
        wait(NULL);
        read(fd[0], line, 100);
        printf("%s\n", line);
    }else{
        read(fd[0], line, 100);
        printf("%s\n", line);
        char p_pid[10];
        sprintf(p_pid, "%d", getppid());
        char hello[] = "Hello ";
        strcat(hello, p_pid);
        write(fd[1], hello, strlen(hello));
    }
    return 0;
}