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
#define FIFO_C1 "FIFO_C1.txt"
#define FIFO_C2 "FIFO_C2.txt"

/*
    Author: Koushik Sahu
    Created: 12 Oct 2020 13:29:42
*/

char s[300];
int num, fd;

int main() {
    mkfifo(FIFO_S, 0666);
    printf("Waiting for writers..\n");
    fd = open(FIFO_S, O_RDONLY);
    printf("got a writer\n");
    if((num=read(fd, s, 300))==-1){
        perror("error");
    }else{
        s[num] = '\0';
        printf("%s\n", s);
    }
    return 0;
}