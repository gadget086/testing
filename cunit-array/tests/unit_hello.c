#include <sys/types.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <stdlib.h>
#include <hello/hello.h>
#include <err.h>

typedef struct {
	char * name;
	void (*func)(void);
} Test;

#define TEST(name) {#name, test_ ## name}

int init_test(void)
{
  printf("Hello, world from init!\n");
}

void test_hello_say(void) {
  CU_ASSERT_EQUAL(1, 1);
  CU_ASSERT_EQUAL(1, 2);
  hello_say();
}
int cleanup_test(void)
{
  printf("Hello, world from cleanup\n");
}

void fireball(void) { \
	CU_cleanup_registry(); \
	exit(CU_get_error()); \
}

int main(void) 
{ 
	CU_pSuite       tsuite = NULL; 
	unsigned int    fails; 
	if (!(CUE_SUCCESS == CU_initialize_registry())) { 
	  errx(666, "failed to initialise test registry"); 
	  return EXIT_FAILURE; 
	}
	tsuite = CU_add_suite(suite, init_test, cleanup_test); \
	if (NULL == tsuite) 
	  fireball(); 
	do { 
	  Test arr[] = {TEST(hello_say}; 
	  for(int i = 0; i < sizeof(arr)/sizeof(Test); i++) { 
            if(NULL == CU_add_test(tsuite, arr[i].name, arr[i].func)) 
	      fireball(); 
	  } 
	}while(0); 
	CU_basic_run_tests(); 
	fails = CU_get_number_of_tests_failed(); 
	warnx("%u tests failed", fails); 
	CU_cleanup_registry(); 
	return fails; 
}
