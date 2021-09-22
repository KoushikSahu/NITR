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
#define FIFO1 "fifo1.txt"
#define FIFO2 "fifo2.txt"
#define FIFO3 "fifo3.txt"
#define FIFO "fifo.txt"

/*
    Author: Koushik Sahu
    Created: 18 Oct 2020 19:00:58
*/

int main() {
    pid_t p = fork();
    if(p==0){
        mkfifo(FIFO, 0666);
        int fd = open(FIFO1, O_WRONLY);
    }else{
        
    }
    return 0;
}