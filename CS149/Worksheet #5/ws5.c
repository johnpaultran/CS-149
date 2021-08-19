// Shayanna Gatchalian & John Paul Tran
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) 
{
    int process1 = fork();
    int process2 = fork();
    
    // 2^2 = 4 processes
    if (process1 < 0 || process2 < 0) { // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else {
        printf("hello world from PID %d!\n", (int) getpid());
    }
    return 0;
}