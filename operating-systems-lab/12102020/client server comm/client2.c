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
#define FIFO_S "FIFO_S.txt"
#define FIFO_C2 "FIFO_C2.txt"

/*
    Author: Koushik Sahu
    Created: 12 Oct 2020 15:02:11
*/

char msg[200], s[200];
int num, fd;

int main() {
    pid_t p = fork();
    if(p==0){
        do{
            gets(s);
            mkfifo(FIFO_S, 0666);
            fd = open(FIFO_S, O_WRONLY);
            sprintf(msg, "Hello from %d client %c", getpid(), 'B');
            write(fd, msg, strlen(msg));
        }while(1);
    }else if(p>0){
        do{
            mkfifo(FIFO_C2, 0666);
            fd = open(FIFO_C2, O_RDONLY);
            read(fd, msg, 200);
            puts(msg);
            unlink(FIFO_C2);
        }while(1);   
    }
    return 0;
}