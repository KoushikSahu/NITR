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
    Created: 02 Nov 2020 13:29:25
*/

int m, n, a[mxN][mxN], b[mxN][mxN], c[mxN][mxN];

void* addRow(void* row_num){
    int row_no = (int)row_num;
    for(int i=0; i<n; i++){
        c[row_no][i] = a[row_no][i] + b[row_no][i];
    }
}

int main() {
    printf("Enter the number of rows(m): ");
    scanf("%d", &m);
    printf("Enter the number of columsn(n): ");
    scanf("%d", &n);
    printf("Enter the first matrix\n");
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter the second matrix\n");
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &b[i][j]);
        }
    }
    pthread_t tid[m];
    for(int i=0; i<m; i++){
        pthread_create(&tid[i], NULL, addRow, (void *)i);
    }
    for(int i=0; i<m; i++){
        pthread_join(tid[i], NULL);
    }
    printf("Result of adding the matrices is\n");
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    return 0;
}