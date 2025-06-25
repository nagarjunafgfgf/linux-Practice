// this program to demonstrate the different memory segment of process
// this program should not consider as any use case in linux

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//function declaration
int add_num(int num1, int num2);

int g_var = 20;
int g_flag;

//This code will be stored in 'text segment as read only memory'
void main(void)
{
    int num1, num2, sum; // stack frame of 'main' function -stack segment
    char* pstr; //pstr is aprt of stack frame of main()
    char *buf = "welcome"; // "welcome" string is stored in text segment, where as variable pointer buf is stored in stack frame of main
    char stack_buff[20] = {"stackData"}; //stack_buf is stored on stack frame and it contains value "stackData"


    // buf[0] = 'n'; //this will cause segmentation fault where as buf[0] tries to write to text segment, which is read-only
    strcpy(stack_buff, "newString"); //possible as it is stored on stack

    num1 =10; //10 is stored on stack
    num2 =20; //10 is stored on stack
    sum = add_num(num1,num2); //value of sum is stored on stack
    printf("the result of add is %d\n", sum);

    num1 = 100;
    num2 = 200;
    sum = add_num(num1,num2);
    printf("the result of add is %d\n", sum);

    pstr = malloc(20); //Heap segment pstr points to 20 bytes of heap, but location of pstr itself is aprt of stack frame of main()
    strcpy(pstr, "hello");
    printf("string stored is %s\n", pstr);

}

//function argument num1, num2 stored in stack
int add_num(int num1, int num2)
{
    int res = 0; //stack frame of 'add_num' function -stack segment
    static int count = 0; // storied in initialised data segment
    count = count + 1;
    res = num1 + num2;

    printf("\n number of times the function add_num called is %d\n", count);
    return(res);
    // when a function returns, all data belonging to that function will become invalid or we can say that stack frame of function is deleted
    //so stack as a growing when new function is called and shrinks when function return back to calling function

}
