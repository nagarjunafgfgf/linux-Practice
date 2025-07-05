// this function will call system_3() by bash library call
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
    printf("in calling process started execution\n");
    sleep(2);
    system("./system3");
    printf("in calling process\n");
    sleep(2);
    printf("calling process terminated\n");
}