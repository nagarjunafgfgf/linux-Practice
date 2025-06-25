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
