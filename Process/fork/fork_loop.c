#include <stdio.h>
#include <unistd.h>
int main()
{
    if (fork() == 0)
    {
        printf("pid:%d  ppid:%d\n", getpid(),getppid());
    }
    else
    {
        if (fork() == 0)
        {
            printf("pid:%d  ppid:%d\n", getpid(),getppid());
        }
        else
        {
            if (fork() == 0)
            {
                printf("pid:%d  ppid:%d\n", getpid(),getppid());
            }
            else
            {
                // while(1);
            }
        }
    }
}