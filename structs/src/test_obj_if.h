#ifndef TEST_OBJ_IF_H
#define TEST_OBJ_IF_H

#include <stdint.h>

typedef struct TEST_OBJ_s
{
    uint32_t (*start)(uint8_t enable, uint8_t num);
    void (*stop)(void);

} TEST_OBJ;

extern TEST_OBJ *getInstance(void);

#endif