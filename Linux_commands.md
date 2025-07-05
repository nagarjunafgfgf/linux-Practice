Commands in Linux:
`````````````````
Libraries:
``````````

cc prog.c -o prog -> generate object file with specific executable name instead of a.out if the .c file has main & every defination available

cc -c prog.c -> It will generate object file with same name as file name & it will blindly generate object file with main & definations also

file <filename>.c -> It will shows type & format of file 

file <filename>.o -> It will more infoa bout that file like ELF, no.of bits processor, variant of target h/w, version, strip info etc.

By default file is dynamically linked, if you add -static in command becomes static linked file
Ex: cc -static prog.c -o prog

ldd -> Displays Dynamic dependent library lists

nm -> display different symbols from object or executable file
Ex:nm add.o

    Static library creation:
    ````````````````````````
    1) cc -c fpic <filename>.c -> create objetct files by this command to use for the generation of library (fpic = positional independent code with -f as silent)

    2) ar rcs <userdefinedstaticlibearyname>.a <filename1>.o <filename2>.o  (r-insert, c-create, s-index)
    Ex:
    cc -c -fpic add.c
    ar rcs libstatic.a add.o sub.o mul.o 

    Dynamic library creation:
    `````````````````````````
    1) cc -c -fpic <filename>.c -> create objetct files by this command to use for the generation of library (fpic = positional independent code with -f as silent) (mandatory - it can fit in any memory)
    2) cc -shared -o <userdefinedlibraryname>.so <filename1>.o <filename2>.o 
    Ex:
    cc -c fpic add.c
    cc -shared -o libdynamic.so add.o sub.o mul.o 


    Loadtime Library linking:
    ````````````````````````
    These are three types:
    1) static linking at load time, results in using libstatic & depends on dynamic library for C & linux definations 
    gcc loadtimeLink.c ./libstatic.a

    2) static linking at load time with static keyword, results in using libstatic, C & linux definations statically
    gcc -static loadtimeLink.c ./libstatic.a

    3) dynamic linking at load time, results in using libstatic, C & linux definations dynamically(i.e., no definations present inside executable)
    gcc loadtimeLink.c ./libstatic.a

export LD_LIBRARY_PATH=/path/to/library:$LD_LIBRARY_PATH -> Set the environment variable to include the directory temporarily

sudo cp libdynamic.so /usr/lib/
sudo ldconfig                       -> Copying to standard library

process:
````````
ps -> Jobs which are available running in particular terminal

ps -e -> Jobs which are available running in system

ps -l/la -> Dispaly jobs in long listed format

ps -e | grep tty1 -> dispalys running jobs of terminal1(This can be run in other terminal to background running process's of terminal1 (grep - global regular expression))

./a.out & -> Makes the process should run in background (This type of process's are called daemon process's)
[JOBID] <PID>
Ex: [1] 7684
If you make one more process run in background
[2] <PID>

fg -> brings the last background running process into foreground (In the above case [2] <PID> will come to foreground)

fg <JOBid> -> according to job id, the particular process wil =l get back on foreground.

vi proc/sys/kernal/pid-max -> dispalys the range of PID's can hold by this linux