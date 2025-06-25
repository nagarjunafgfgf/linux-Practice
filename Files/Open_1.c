// File should be created manually
// if open call succeeded, It will return least available file descriptor(3)
// if file is not available, it won't create a file & throws an error as no such file or directory  errno(2)
// If no read permission to user of the file, It throw an error as permission denied with errno(13)

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

void main(){
    int fd;
    fd = open("startup", O_RDONLY);
    if (fd == -1){
        printf("\n open() was failed - errno = (%d)\n",errno);
        perror("ERROR:");
    }
    else
    {
        printf("\n open() system call executed successfully, the file descriptor of opened file is (%d)\n", fd);
    }

}
