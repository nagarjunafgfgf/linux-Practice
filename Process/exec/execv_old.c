#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() 
{ 
    printf("\nMain program p1.c\n");

    // First argument must be the executable path itself
    char *args[] = { "arg1", "arg2", "arg3", NULL};

    // Try to replace current process
    execv("./new", args);

    // If execv() fails, print the error
    perror("execv failed");

    return 0;
}
