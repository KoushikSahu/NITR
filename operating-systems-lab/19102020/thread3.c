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
    Created: 01 Nov 2020 11:33:42
*/

const int NUM = 5;

void* printHello(void* threadid){
    long tid = *(long *)threadid;
    printf("Hello world! It's me thread #%ld\n", tid);
    return 0;
}

int main() {
    pthread_t threads[NUM];
    int rc;
    long t;
    for(t=0; t<NUM; t++){
        printf("In main: creating thread %ld\n", t);
        rc = pthread_create(&threads[t], NULL, printHello, &t);
        pthread_join(threads[t], NULL);
        if(rc){
            printf("Error! return code is %d\n", rc);
            exit(-1);
        }
    }
    pthread_exit(0);
    return 0;
}