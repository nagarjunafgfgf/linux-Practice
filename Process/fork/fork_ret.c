#include <stdio.h>
#include <unistd.h>
int main()
{
    int ret;
    printf("hello\n");
    ret = fork();
    printf("ret: %d\n", ret);
}