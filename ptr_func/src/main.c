#include <config.h>
#include <stdio.h>

typedef int (*operation_ptr)(int,int);

int add(int a, int b) {return a+b;}
int mult(int a, int b) {return a*b;}

int do_operation(operation_ptr op, int x, int y)
{
    return op(x,y);
}

int main(int argc, char **argv)
{
    puts("test of function pointer");
    int result = do_operation(add,5,34);
    printf("5+34=%d\n", result);
    int result2 = do_operation(mult,2,3);
    printf("2*3=%d\n", result2);
    return 0;
}
