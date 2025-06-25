// process ID and Parent process ID
 #include <stdio.h>
 #include <unistd.h>
 #include <sys/types.h>

 int main()
 {
    printf("program execute in memory as a process\n");
    printf("process ID is %d\n", getpid());
    printf("parent process ID is %d\n", getppid());
    sleep(5);
    printf("the program is terminated from memory and the process no longer exists\n");
 }