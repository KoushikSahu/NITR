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
    Created: 01 Nov 2020 11:13:41
*/

void* printHello(void* threadid){
    long tid = *(long*) threadid;
    printf("Hello world! It's me, thread #%ld\n", tid);
    return 0;
}

int main(int argc, char* argv[]) {
    pthread_t thread0;
    int rc;
    long t = 0;
    printf("In main: creating thread %ld\n", t);
    rc = pthread_create(&thread0, NULL, printHello, &t);
    if(rc){
        printf("Error! return code is %d\n", rc);
        exit(-1);
    }
    pthread_exit(0);
}