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
    int result = do_operaiton(add,5,34);
    puts("5+34=" result);
    int result2 = do_operation(mult,2,3);
    puts("2*3="result2);
    return 0;
}
