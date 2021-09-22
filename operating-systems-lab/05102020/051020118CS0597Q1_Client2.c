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
    Created: 05 Oct 2020 13:46:46
*/

int num, fd;
char s[300];

int main() {
    mkfifo(FIFO_NAME, 0666);
    printf("Waiting for writer...\n");
    fd = open(FIFO_NAME, O_RDONLY);
    do{
        if((num=read(fd, s, 300))==-1){
            perror("Error occured in reader\n");
        }else{
            s[num] = '\0';
            printf("%s\n", s);
        }
    }while(strcmp(s, "bye")!=0);
    unlink(FIFO_NAME);
    return 0;
}