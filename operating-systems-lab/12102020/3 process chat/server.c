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
    Created: 19 Oct 2020 10:40:28
*/

int main() {
    while(1){
        mkfifo(FIFO, 0666);
        int fd = open(FIFO, O_RDONLY);
        char msg[200];
        int num = read(fd, msg, 200);
        msg[num] = '\0';
        unlink(fd);
        mkfifo(FIFO1, 0666);
        int fd1 = open(FIFO1, O_WRONLY);
        write(fd1, msg, strlen(msg));
        mkfifo(FIFO2, 0666);
        int fd2 = open(FIFO2, O_WRONLY);
        write(fd2, msg, strlen(msg));
        mkfifo(FIFO3, 0666);
        int fd3 = open(FIFO3, O_WRONLY);
        write(fd3, msg, strlen(msg));
    }
    return 0;
}