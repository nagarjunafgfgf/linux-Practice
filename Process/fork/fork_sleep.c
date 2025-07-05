#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <stdlib.h>

int main() 
{ 
    if(fork()== 0)
    {
        sleep(5);
        printf("child Process\n");
        printf("child pid = %d ppid = %d\n",getpid(),getppid());
        printf("child exit\n");

    }else
    {
        printf("parent Process\n");
        printf("parent pid = %d ppid = %d\n",getpid(),getppid());  
        sleep(3);
        printf("parent exit\n");
    }
  
    return 0; 
} 
