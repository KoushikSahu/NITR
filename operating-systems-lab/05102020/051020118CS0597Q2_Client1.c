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
#define FIFO_WR "ipc1.txt"
#define FIFO_RD "ipc2.txt"

/*
    Author: Koushik Sahu
    Created: 05 Oct 2020 14:00:53
*/

pid_t p;
int num, fd;
char s[300];

int main() {
    p = fork();
    if(p<0){
        perror("Could not create child process\n");
        exit(0);
    }else if(p>0){
        mkfifo(FIFO_WR, 0666);
        fd = open(FIFO_WR, O_WRONLY);
        do{
            gets(s);
            if((num=write(fd, s, strlen(s)))==-1){
                perror("Error occured in writing\n");
            }
        }while(strcmp(s, "bye")!=0);
        wait(NULL);
    }else{
        mkfifo(FIFO_RD, 0666);
        fd = open(FIFO_RD, O_RDONLY);
        do{
            if((num=read(fd, s, 300))==-1){
                perror("Error occured in reader\n");
            }else{
                s[num] = '\0';
                printf("Client 2 says: %s\n", s);
            }
        }while(strcmp(s, "bye")!=0);
        unlink(FIFO_RD);
    }
    return 0;
}