#include <hello/hello.h>

#include "cunit.h"

INIT(
  printf("Hello, world from init!\n");
)

CHECK(hello_say) {
  CU_ASSERT_EQUAL(1, 1);
  hello_say();
}

CHECK(hello_say1) {
  CU_ASSERT_EQUAL(1, 1);
  hello_say();
}

CLEANUP(
  printf("Hello, world from cleanup\n");
)

RUN("hello", TEST(hello_say), TEST(hello_say1));
