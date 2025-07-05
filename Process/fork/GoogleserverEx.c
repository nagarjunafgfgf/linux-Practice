#include <stdio.h>
#include <unistd.h>
int main()
{
    printf("hi\n");
    fork();
    fork();
    fork();
    printf("hello\n");
    while(1);
}