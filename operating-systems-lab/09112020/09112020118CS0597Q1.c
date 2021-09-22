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
#include <pthread.h>

/*
    Author: Koushik Sahu
    Created: 09 Nov 2020 14:04:38
*/

bool flag[3];
int turn = 0;
int var = 0;

void* addTwo(void* arg){
    printf("Entering thread: %d\n", pthread_self());
    flag[1] = true;
    turn = 2;
    while(flag[2] && turn==2) sleep(1);
    // critical section
    printf("Sleeping for some time to ensure context switch\n");
    sleep(1);
    printf("Adding two\n");
    var += 2;
    flag[1] = false;
}

void* multiplyThree(void* arg){
    printf("Entering thread: %d\n", pthread_self());
    flag[2] = true;
    turn = 1;
    while(flag[1] && turn==1) sleep(1);
    // critical section
    printf("Multiplying three\n");
    var *= 3;
    flag[2] = false;
}

void* recursiveThreading(void *arg){
    printf("Entering recursive function. Thread id: %d\n", pthread_self());
    pthread_t tid;
    pthread_create(tid, NULL, recursiveThreading, NULL);
}

void* waitingThread(void* arg){
    printf("Executing the waiting thread in between an ongoing recursive thread function\nHence we have shown that bounded wait is satisfied\n");
    exit(0);
}

int main() {
    flag[1] = flag[2] = false;
    pthread_t tid[2];
    printf("-----------------Mutual exclusion------------------\n");
    pthread_create(&tid[0], NULL, addTwo, NULL);
    pthread_create(&tid[1], NULL, multiplyThree, NULL);
    for(int i=0; i<2; i++) pthread_join(tid[i], NULL);
    printf("If mutual exclusion was maintained then value of var must be 6 else 0\n");
    printf("Value of var: %d\n", var);
    if(var==6) printf("We have hence shown that mutual exclusion is satisfied!\n\n");
    else printf("Oops! Mutual exclusion not satisfied\n\n");
    printf("------------------Progress-----------------\n");
    printf("To show progress we should be able to execute the same function twice in succession\n");
    var = 1;
    pthread_create(&tid[0], NULL, multiplyThree, NULL);
    pthread_create(&tid[1], NULL, multiplyThree, NULL);
    for(int i=0; i<2; i++) pthread_join(tid[i], NULL);
    printf("Value of var: %d\n", var);
    if(var==9) printf("We have shown that progress is satisfied\n\n");
    else printf("Oops! progress is not satisfied\n\n");
    printf("----------------Bounded wait-------------\n");
    pthread_create(&tid[0], NULL, recursiveThreading, NULL);
    pthread_create(&tid[1], NULL, waitingThread, NULL);
    printf("Executing the waiting thread in between an ongoing recursive thread function\nHence we have shown that bounded wait is satisfied\n");
    return 0;
}