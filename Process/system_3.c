// this function will be called by another function through system() library call
#include <stdio.h>
#include <unistd.h>
int main()
{
    printf("in called function\n");
    sleep(2);
    printf("called function terminated\n");
}