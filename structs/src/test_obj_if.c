#include "test_if.h"
#include "test_obj_if.h"

TEST_OBJ *getInstance(void)
{
    static TEST_OBJ driver = 
    {
        .start = TEST_Start,
        .stop = TEST_Stop
    };

    return &driver;
}

