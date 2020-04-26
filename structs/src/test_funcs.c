#include <stdio.h>
#include "test_if.h"
#include "test_obj_if.h"

uint32_t TEST_Start(uint8_t enable, uint8_t num)
{
    uint32_t x;

    x = enable + num;
    printf("Hello World\n");

    return x;
}

void TEST_Stop(void)
{
    printf("Stop the music!\n");
}