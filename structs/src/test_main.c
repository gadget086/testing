#include <stdio.h>
#include "test_if.h"
#include "test_obj_if.h"

TEST_OBJ *myTest;

int main ()
{
    uint32_t result;
    myTest = getInstance();

    result = myTest->start(1,2);
    printf("%x\n", result);
    myTest->stop();
    return 0;
}