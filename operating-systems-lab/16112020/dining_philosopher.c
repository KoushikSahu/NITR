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
#include <semaphore.h>
#define nxM 5

/*
    Author: Koushik Sahu
    Created: 16 Nov 2020 14:17:46
*/

sem_t mutex[nxM];

void* eat(void* arg){
    int phid = (int)arg;
    int left = phid, right = (phid+1)%nxM;
    if(phid%2==0){
        sem_wait(&mutex[right]);
        sem_wait(&mutex[left]);
        printf("Philosopher %d picked up %d and %d chopstick and started eating\n", phid, right, left);
        sem_post(&mutex[right]);
        sem_post(&mutex[left]);
    }else{
        sem_wait(&mutex[left]);
        sem_wait(&mutex[right]);
        printf("Philosopher %d picked up %d and %d chopstick and started eating\n", phid, left, right);
        sem_post(&mutex[left]);
        sem_post(&mutex[right]);
    }
}

int main() {
    for(int i=0; i<nxM; i++) sem_init(&mutex[i], 0, 1);
    pthread_t tid[nxM];
    for(int i=0; i<nxM; i++){
        pthread_create(&tid[i], NULL, eat, (void*)i);
    }
    for(int i=0; i<nxM; i++){
        pthread_join(tid[i], NULL);
    }
    printf("All philosophers were able to eat without deadlock\n");
    return 0;
}