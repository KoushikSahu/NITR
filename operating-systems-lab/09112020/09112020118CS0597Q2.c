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
#define nxM 1001

/*
    Author: Koushik Sahu
    Created: 09 Nov 2020 13:28:00
*/

int n, a[nxM];

struct Pair{
    int low, high;
};

void merge(int low, int mid, int high){
    int l = mid-low+1;
    int r = high-mid;
    int left[l], right[r];
    for(int i=low; i<=mid; i++){
        left[i-low] = a[i];
    }
    for(int i=mid+1; i<=high; i++){
        right[i-mid-1] = a[i];
    }
    int l_ptr = 0, r_ptr = 0, ptr=low;
    while(l_ptr<l && r_ptr<r){
        if(left[l_ptr]<=right[r_ptr]){
            a[ptr++] = left[l_ptr++];
        }else{
            a[ptr++] = right[r_ptr++];
        }
    }
    while(l_ptr<l){
        a[ptr++] = left[l_ptr++];
    }
    while(r_ptr<r){
        a[ptr++] = right[r_ptr++];
    }
}

void* mergeSort(void* arg){
    struct Pair* p = arg;
    int low = p->low;
    int high = p->high;
    if(low<high){
        int mid = low + (high-low)/2;
        pthread_t tid[2];
        struct Pair* p1 = (struct Pair*)malloc(sizeof(struct Pair));
        p1->low = low;
        p1->high = mid;
        pthread_create(&tid[0], NULL, mergeSort, (void*)p1);
        struct Pair* p2 = (struct Pair*)malloc(sizeof(struct Pair));
        p2->low = mid+1;
        p2->high = high;
        pthread_create(&tid[1], NULL, mergeSort, (void*)p2);
        for(int i=0; i<2; i++) pthread_join(tid[i], NULL);
        merge(low, mid, high);
    }
}

int main() {
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter %d elements of the array\n", n);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    struct Pair* p = (struct Pair*)malloc(sizeof(struct Pair));
    p->low = 0;
    p->high = n-1;
    mergeSort((void*)p);
    printf("Array after sorting: ");
    for(int i=0; i<n; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}