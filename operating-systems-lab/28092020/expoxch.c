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

/*
    Author: Koushik Sahu
    Created: 28 Sep 2020 15:15:26
*/

int evalFact(int n){
    if(n==0 || n==1) return 1;
    return evalFact(n-1) + evalFact(n-2);
}

float evalExp(float x, int t){
    float ans = 0;
    for(int i=0; i<t; i++){
        ans += powf(x, i) / (float)evalFact(i);
    }
    return ans;
}

int main(int argc, char* argv[]) {
    float x = atof(argv[1]);
    int t = atoi(argv[2]);
    float ans = evalExp(x, t);
    printf("%f\n", ans);
    return 0;
}