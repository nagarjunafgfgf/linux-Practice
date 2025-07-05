#include <stdio.h>
#include <dlfcn.h>
int add(int,int);
int sub(int,int);
int mul(int,int);

int main()
{
    int a, b, opt, ret;
    void *handler;
    int (*ptr)(int,int);
    printf("enter a, b options\n");
    scanf("%d %d", &a, &b);
    printf("1 - add, 2 - sub, 3 - mul\n");
    printf("enter option\n");
    scanf("%d",&opt);
    if(opt == 1)
    {
        handler = dlopen("libdynamic.so",RTLD_LAZY);
        if(handler == 0)
        {
        //   printf("unable to load lib\n");  
          printf("%s\n", dlerror());
          return 0;  
        }
        ptr = dlsym(handler, "add");
        if(ptr == 0)
        {
            // printf("symbol not found\n");
            printf("%s\n", dlerror());
            return 0; 
        }
        ret = (*ptr)(a,b);
        printf("add:%d\n",ret);
        dlclose(handler);
    }
    else if(opt == 2)
    {
       handler = dlopen("libdynamic.so",RTLD_LAZY);
        if(handler == 0)
        {
        //   printf("unable to load lib\n");  
          printf("%s\n", dlerror());
          return 0;  
        }
        ptr = dlsym(handler, "sub");
        if(ptr == 0)
        {
            // printf("symbol not found\n");
            printf("%s\n", dlerror());
            return 0; 
        }
        ret = (*ptr)(a,b);
        printf("sub:%d\n",ret);
        dlclose(handler);
    }
    else if(opt == 3)
    {
        handler = dlopen("libdynamic.so",RTLD_LAZY);
        if(handler == 0)
        {
        //   printf("unable to load lib\n");  
          printf("%s\n", dlerror());
          return 0;  
        }
        ptr = dlsym(handler, "mul");
        if(ptr == 0)
        {
            // printf("symbol not found\n");
            printf("%s\n", dlerror());
            return 0; 
        }
        ret = (*ptr)(a,b);
        printf("mul:%d\n",ret);
        dlclose(handler);
    }
    else
    {
        printf("Invalid option\n");
    }
}