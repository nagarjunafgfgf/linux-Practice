// running bash commands inside program with the help of syatem() library call
#include <stdio.h>
#include <stdlib.h>
int main()
 {
    printf("in main\n");
    system("pwd");
    system("ls");
    system("cal");
    printf("hi\n");
}