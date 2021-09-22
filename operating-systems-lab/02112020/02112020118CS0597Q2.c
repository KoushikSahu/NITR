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
#define mxN 1001 

/*
    Author: Koushik Sahu
    Created: 02 Nov 2020 13:44:31
*/

int m, n, k, a[mxN][mxN], b[mxN][mxN], c[mxN][mxN];

struct Pair{
    int first, second;
};

void* evalCol(void* p){
    struct Pair* rc = (struct Pair*)p;
    for(int i=0; i<n; i++){
        c[rc->first][rc->second] += a[rc->first][i] * b[i][rc->second];
    }
}

void* evalRow(void* row){
    int row_num = (int)row;
    pthread_t tid[k];
    for(int i=0; i<k; i++){
        struct Pair* p = (struct Pair*)malloc(sizeof(struct Pair));
        p->first = row_num;
        p->second = i;
        pthread_create(&tid[i], NULL, evalCol, (void*)p);
    }
    for(int i=0; i<k; i++){
        pthread_join(tid[i], NULL);
    }
}

int main() {
    printf("Enter the number of rows in first matrix(m): ");
    scanf("%d", &m);
    printf("Enter the number of columns in first matrix(n): ");
    scanf("%d", &n);
    printf("Enter the first matrix\n");
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &a[i][j]);
        }
    }
    int tmp;
    printf("Enter the number of rows in second matrix(n): ");
    scanf("%d", &tmp);
    // TODO: check tmp == n
    printf("Enter the number of columns in second matrix(k): ");
    scanf("%d", &k);
    printf("Enter the second matrix\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++){
            scanf("%d", &b[i][j]);
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<k; j++){
            c[i][j] = 0;
        }
    }
    pthread_t tid[m];
    for(int i=0; i<m; i++){
        pthread_create(&tid[i], NULL, evalRow, (void *)i);
    }
    for(int i=0; i<m; i++){
        pthread_join(tid[i], NULL);
    }
    printf("Result after multiplication\n");
    for(int i=0; i<m; i++){
        for(int j=0; j<k; j++){
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    return 0;
}