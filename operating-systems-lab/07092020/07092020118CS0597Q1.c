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
    Created: 31 August 2020 Mon 14:46:02
*/

// address of parent and child variable are printed same 
// because the printed address is virtual address and not actual address to physical memory
// virtual addresses are mapped to different physical memory in the processes 

int global_variable = 21;

int main() {
    int local_variable = 20;
    pid_t p = fork();
    printf("This line will be printed twice if parent and child process has the same program counter after fork is called");
    if(p==0){
        printf("\nI am child process\n");
        printf("Global variable:%d\tLocal variable value:%d\n", global_variable, local_variable);
        printf("Address of Global variable:%p\t Address of local_variable:%p\n", &global_variable, &local_variable);
    }else if(p>0){
        // this wait function will ensure that all the printed local and global variable value and addresses are of the child process
        wait(NULL);
        // these lines are executed after child process returns 0
        printf("\nI am parent process\n");
        printf("Global variable:%d\tLocal variable value:%d\n", global_variable, local_variable);
        printf("Address of Global variable:%p\t Address of local_variable:%p\n", &global_variable, &local_variable);
    }
    return 0;
}