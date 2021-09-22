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
    Created: 12 Oct 2020 15:02:11
*/

char msg[200];
int num, fd1, fd2, fd3;

int main() {
    do{
        mkfifo(FIFO_S, 0666);
        fd1 = open(FIFO_S, O_RDONLY);
        int num = read(fd1, msg, 200);
        int pid;
        char client;
        sscanf(msg, "Hello from %d client %c", &pid, &client);
        if(client=='A'){
            printf("Client A says: Hello from %d\n", pid);
            mkfifo(FIFO_C1, 0666);
            fd2 = open(FIFO_C1, O_WRONLY);
            sprintf(msg, "Hi %d", pid);
            write(fd2, msg, strlen(msg)); 
        }else{
            printf("Client B says: Hello from %d\n", pid);
            mkfifo(FIFO_C2, 0666);
            fd3 = open(FIFO_C2, O_WRONLY);
            sprintf(msg, "Hi %d", pid);
            write(fd3, msg, strlen(msg));
        }
        unlink(FIFO_S);
    }while(1);
    return 0;
}