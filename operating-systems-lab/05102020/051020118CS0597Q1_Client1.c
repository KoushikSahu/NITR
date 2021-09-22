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
#define FIFO_NAME "ipc.txt"

/*
    Author: Koushik Sahu
    Created: 05 Oct 2020 13:39:25
*/

int num, fd;
char s[300];

int main() {
    mkfifo(FIFO_NAME, 0666);
    printf("Waiting for readers...\n");
    fd = open(FIFO_NAME, O_WRONLY);
    printf("Got a reader. Please type the message\n");
    do{
        gets(s);
        if((num=write(fd, s, strlen(s)))==-1){
            perror("Error occured in writing\n");
        }else{
            printf("Wrote %d bytes\n", num);
        }
    }while(strcmp(s, "bye")!=0);
    return 0;
}