This repo is about linux programming

Operating System:
`````````````````
- Operating System (OS) is the software program that manages the hardware of computer.
- The Hardware such as Input, output peripherals, Memory, CPU are all managed by the OS.
Few examples of OS are Windows, Linux, Mac, Android and many others.

Linux:
``````
What is LINUX?
Linux is a family of open source OS.
Linux source code is freely available.
Users are free to download, modify and enhance the OS.

The Linux OS components are
1)Kernel – The kernel is a computer program at the core of   computer's operating system, and manages the hardware.
2)Networking – Provides the feature to communication across different computers.
3)Security – Is a mechanism of providing  protection to  computer system resources such as CPU, memory, disk and others. It provides access control for unauthorised user from accessing system resource, and hence providing security.
4)GUI (User inferface) – The graphics version of Linux provides user interface


1. Linux is a very secured OS compared to other OS like Windows
2. Linux is Open source, hence it is low cost maintainence OS.
3. Linux is highly stable, and it is very less prone to system crashes.
4. Linux runs on most modern Processor(hardware)
5. Linux systems provides a ease of customisation their product development.
6. Linux has a wide community of developers Globally, hence the support we get for 
   Linux is very good when compared to any other OS.
7. The Linux systems are used in wide variety of applications like
   Super computers, Smart watches, smart TV, Set-Top-Box, Servers, Infotainment industry, Smart Cars,
   IoT devices, Routers, Railway Signalling and many more. 

Did you know - NASA also uses Linux in their Space station for better reliability.

- From basics to advanced Linux systems programming, with lots of hands on 'C' programming demos.
- File operation, System calls, Library functions, code compiling using GNU-GCC, Blocking and Non Blocking calls, Atomic operations, Race condition, User mode and Kernel mode.
- Process Management - Process creation, termination, Fork() system call, child-parent process, command line argument of process, Memory Layout of Process.
- Signals - signal handlers, sending signals to process, Default signal handlers.
- Memory Management - Process Virtual Memory management, Memory segments(code, data, stack, Heap)
- Posix Threads - Thread creation, thread termination, Thread ID, Joinable and detachable Threads.
- Thread Synchronisation - Mutex, Condition Variables
- Inter Process Communication (IPC)- Pipes, FIFO, Posix Message Queue, Posix semaphore, Posix shared memory.

* All programs explained during this course are in C.
* Ubuntu PC is used to run the C program(User can use any Linux distribution).
* GCC compiler is used to compile the code.

DEMO:
````
The open source compiler we use to compile the code is GCC.
We will look into a First demo ‘C’ program to write a simple program, and make use of standard Librabry and call library functions.
The Terminal is used to compile the code using gcc.
The command used to compile code is
eg: If the source code is ‘lib_ex.c’ and required out file is  ‘lib_ex.out’ then below command is used to compile the C code.
      gcc lib_ex.c -o lib_ex
      -o is used to create out file by name lib_ex.out
For more details on usage on gcc type ‘man gcc’ on terminal


References:
```````````
- The design of Unix operating system by Maurice J Bach
- Te linux programming interface ny Michael Kerrisk
- Advanced Programming in the Unix environment by W.Richard Stevens


some Q & A:
```````````
Q. What is Thread Local Storage (TLS) or Thread Private Data?
A.  Thread Local storage is the part of memory of each thread, in which the variables are accessed by all functions belonging to that thread. It acts like a variables that are global and visible only to specific thread where it is defined.

   Functions/data structures involved in creating TLS are
   pthread_key_t   key
   pthread_key_create()
   pthread_setspecific()
   pthread_getspecific()

Q.  What are holes in Files?
A.  A hole in a file area  are represented by '0'.   Holes are created when user writes data beyond the length of the file (beyond file size). The space between new data and old file size data will be filled with zero's and are called Holes.

Q.  Below question asked by one of the student.

I've written a simple program to get the current offset. It always prints '0', as if the offset is per process. I've open the log.txt in vim and was changing the cursor and was also adding the new symbols. Do you know what I'm missing here?

offset1.c
`````````
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
   printf("\noffset1 sleeping\n");
   sleep(3);
   ssize_t fd = open("log.txt", O_RDWR);
   off_t offset;
   offset = lseek(fd, 0, SEEK_CUR);
   if (offset == (off_t)-1)
   {
      perror("lseek");
      exit(1);
   }
   printf("\noffset1 finished: (%ld)\n", offset);
   printf("\noffset1 current position: (%ld)\n", offset);
}

offset2.c
`````````
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
   ssize_t fd = open("log.txt", O_RDWR);
   off_t offset;
   offset = lseek(fd, 10, SEEK_SET);
   if (offset == (off_t)-1)
   {
      perror("lseek");
      exit(1);
   }
   printf("\noffset2 current position: (%ld)\n", offset);
   printf("\noffset2 sleeping\n");
   sleep(3);
   printf("\noffset2 finished\n");
}

Below output recorded after running both above programs simultaneoulsy

offset1 sleeping

offset2 current position: (10)

offset2 sleeping

offset1 finished: (0)

offset1 current position: (0)

offset2 finished

Explanation:

Yes the Offset works on Per process basis, Refer to Lecture 17 and 18.

1. Here the 2 programs acts as 2 separate process.
2. Each Process will have dedicated file descriptor table.
3. There is one system wide 'open file table'.
4. Now when each process open same file, each process has entry in its own 'file descriptor table'
5. And each process creates its own entry in 'open file table'. Hence Offset, mode in which file is opened is specific to each Process. (Say row1 in open file table has entry for process 1, row2 in open file table has entry for process 2, finally the inode pointer of both entries will point to same inode table)

Q . What is a 'Nice' Value?
A. Every process has its own priority. by default its value is '0', this value varies from -20 to +19.
-20 is highest priority, +19 is lowest priority.

Q. How to check the 'Nice' value of a process?
A.  'Nice' value can be found using ps, top, htop command. 'NI' column represents the Niceness value
eg:  run 'htop' on terminal, the value under column 'NI' gives nice value of the given process

Q. How to run a process(say proc1) with a given nice value? ex: run a process with nice value = -5
A. nice --5 ./proc1
Explanation to set nice value run
nice -(nice value) program_name

Q. How to run a process(say proc1) with a given nice value? ex: run a process with nice value = +10
A. nice -10 ./proc1

Q. How to change nice value of running process(with PID say 3212)? eg say a process(with PID 3212) is running with nice value = +5, now change the process nice value to -2
A. Use renice command shown below
renice -n 5 -p 3212

Q. Which scheduling Algorithm is used for Process scheduling in Linux?
A.  Completely Fair Scheduler(CFS) is used as default scheduling Algorithm.

Q. What is a Time slice in OS?
A.  The amount of time which a scheduler gives for a process to run on the Processor(CPU) is called time slice.

Q. Name few scheduling Algorithm?
A. First come first serve,  priority based scheduler, Shortest remaining time, Round Robin, CFS

Q. What is blocking a signal ?
A. Blocking a signal means telling the Linux OS to hold the signal and  deliver it later when signal is Unblocked.

Q. How to block a signal?
A. sigprocmask() is used to 'BLOCK' and 'UNBLOCK' using the first parameter SIG_BLOCK or SIG_UNBLOCK respectively.

Q. can all signals in linux be ignored?
A. No. There are few signals that cannot be ignored ex: SIGKILL.

Q. How to generate SIGALRM signal?
A. alarm() system call generates SIGALRM signal.

Q. what are condition variables?
A. Condition variables along with mutex,  are used to signal the changes from one thread to other thread.

pthread_cond_signal() used in one thread and pthread_cond_wait() used in other waiting thread to implement above.

Interview Q & A:
Here I have added the most common interview question used to test the Linux system Programming knowledge.

1. Thread1 has string "ABCD", Thread2 has string "1234"  , the desired output is "A1B2C3D4"
Write a C program in Linux to achieve the above.
2. Assume we have one Server process and 5 different Client process running.

objective: Server has data/message( say 100 bytes) and each data/message is to be delivered to specific client process, how do you achieve it?
3. On what criteria the different IPC are chosen?
4. Which is the fastest IPC among all IPC's ?
5. What are Daemon process in Linux?
6. Difference between Process and threads?
7. Once we fork a child process from Parent process, what are common things shared between parent and child process?
8.  What are system calls and explain how it works.
9. What is Swap memory and what is its importance.
10. What are the different file permissions?
11. What are Environment Variables.
12. what is KILL command in Linux used for?
13. what are static and shared Libraries?
14. What is difference between Pipes and FIFO?
15. When we move a file, what happens  wrt to inode of  files?
16. what tools are used to analyze memory leaks in Linux?
17. What is a soft link and hard link. How the inode is affected between these files?