// whenever SIGINT, SIGTERM caught, We are ignoring the default action with SIG_IGN
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main (void)
{

    printf("\n process ID is(%d)\n",getpid());
    if (signal (SIGINT, SIG_IGN) == SIG_ERR) {
        fprintf (stderr, "Cannot ignore SIGHUP!\n");
        exit (EXIT_FAILURE);
    }


    if (signal (SIGTERM, SIG_IGN) == SIG_ERR) {
        fprintf (stderr, "Cannot handle SIGTERM!\n");
        exit (EXIT_FAILURE);
    }
    while(1);
}
