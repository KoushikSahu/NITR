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
    Created: 21 Sep 2020 14:54:00
*/

int global_var = 20;

int main() {
    printf("Value of global_var is %d and address is %p\n", global_var, &global_var);
    printf("Since both the addresses are different they cannot be sharing the same address space. If the address space were same then re definiton of variable wouldn't be allowed or then the address of both should be same\n");
    return 0;
}