// Static linking
// If you want to run this, generate objects files to all add, sub, mul & this program with cc -c <filename>.c separately
// Then link all with cc arthemetic.o add.o sub.o mul.o
// Then execute

#include <stdio.h>
int add(int, int);
int sub(int, int);
int mul(int, int);

int main()
{
    printf("in main function\n");
    printf("add : %d\n", add(10,5));
    printf("sub : %d\n", sub(10,5));
    printf("mul : %d\n", mul(10,5));
}