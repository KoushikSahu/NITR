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
    Created: 21 Sep 2020 14:51:00
*/

int global_var = 10;

int main() {
    printf("Value of global_var is %d and address is %p\n", global_var, &global_var);
    char *args[] = {"./210920118CS0597Q3_2", NULL}; 
    execvp(args[0], args);
    printf("foobar\n"); // this statement wouldn't be excuted as the address space is changed
    return 0;
}