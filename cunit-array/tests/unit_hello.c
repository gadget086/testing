#include <sys/types.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <stdlib.h>
#include <hello/hello.h>
#include <err.h>

int init_test(void)
{
  printf("Hello, world from init!\n");
  return 0;
}

void test_hello_say(void) {
  CU_ASSERT(1==2);
  hello_say();
}

void test_hello_say2(void) {
  CU_ASSERT_EQUAL(1, 1);
  CU_ASSERT_EQUAL(1, 2);
  hello_say();
}

int cleanup_test(void)
{
  printf("Hello, world from cleanup\n");
  return 0;
}

void fireball(void) { \
	CU_cleanup_registry(); \
	exit(CU_get_error()); \
}

int main(void) 
{ 
	CU_pSuite       tsuite = NULL; 
	//unsigned int    fails; 
	if (!(CUE_SUCCESS == CU_initialize_registry())) { 
	  errx(666, "failed to initialise test registry"); 
	  return EXIT_FAILURE; 
	}

	tsuite = CU_add_suite("hello", init_test, cleanup_test); \
	if (NULL == tsuite) 
	{
        fireball(); 
    }

    if((NULL == CU_add_test(tsuite, "test_hello_say",test_hello_say)) ||
       (NULL == CU_add_test(tsuite, "test_hello_say2",test_hello_say2))) 
    {
        fireball(); 
    }
	//CU_basic_set_mode(CU_BRM_VERBOSE); 
	CU_basic_run_tests(); 
	//fails = CU_get_number_of_tests_failed(); 
	//warnx("%u tests failed", fails); 
	CU_cleanup_registry(); 
	return CU_get_error(); 
}
