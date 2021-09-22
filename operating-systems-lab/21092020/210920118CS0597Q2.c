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
    Created: 21 Sep 2020 14:20:49
*/

int n, first_num;

int main() {
    printf("Enter the number of processes to be created in chain\n");
    scanf("%d", &n);
    printf("Enter the first number\n");
    scanf("%d", &first_num);
    int fd[2];
    int response = pipe(fd);
    char first[100];
    sprintf(first, "%d", first_num);
    write(fd[1], first, strlen(first));
    if(response==-1) exit(0);
    for(int i=0; i<n; i++){
        pid_t p = fork();
        if(p==0){
            char number[100];
            read(fd[0], number, 100);
            int num = atoi(number);
            // printf("%d\n", num);
            if(num-n+1==first_num){
                num += 1;
                printf("Finally: %d\n", num);
            }else{
                num += 1;
                sprintf(number, "%d", num);
                write(fd[1], number, strlen(number));
            }
            continue;
        }else{
            wait(NULL);
            exit(0);
        }
    }
}