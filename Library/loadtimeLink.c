#include <stdio.h>
int add(int,int);
int sub(int,int);
int mul(int,int);

int main()
{
    int a, b, opt, ret;
    printf("enter a, b options\n");
    scanf("%d %d", &a, &b);
    printf("1 - add, 2 - sub, 3 - mul\n");
    printf("enter option\n");
    scanf("%d",&opt);
    if(opt == 1)
    {
        ret = add(a,b);
        printf("add:%d\n",ret);
    }
    else if(opt == 2)
    {
        ret = sub(a,b);
        printf("sub:%d\n",ret);
    }
    else if(opt == 3)
    {
        ret = mul(a,b);
        printf("mul:%d\n",ret);
    }
    else
    {
        printf("Invalid option\n");
    }
}