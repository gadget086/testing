#include <sys/types.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <stdlib.h>
#include <err.h>

typedef struct {
	char * name;
	void (*func)(void);
} Test;

#define __PRE_POST_TEST(sig, code) \
sig {\
	code\
	return 0;\
}

#define INIT(code)\
	__PRE_POST_TEST(int init_test(void), code)
#define CLEANUP(code)\
	__PRE_POST_TEST(int cleanup_test(void), code)

#define CHECK(name) void test_ ## name(void)
#define TEST(name) {"name", test_ ## name}

#define RUN(suite, ...) \
void fireball(void) { \
	CU_cleanup_registry(); \
	exit(CU_get_error()); \
} \
int \
main(void) \
{ \
	CU_pSuite       tsuite = NULL; \
	unsigned int    fails; \
	if (!(CUE_SUCCESS == CU_initialize_registry())) { \
	  errx(666, "failed to initialise test registry"); \
	  return EXIT_FAILURE; \
	}\
	tsuite = CU_add_suite(suite, init_test, cleanup_test); \
	if (NULL == tsuite) \
	  fireball(); \
	do { \
	  Test arr[] = {__VA_ARGS__}; \
	  for(int i = 0; i < sizeof(arr)/sizeof(Test); i++) { \
            if(NULL == CU_add_test(tsuite, arr[i].name, arr[i].func)) \
	      fireball(); \
	  } \
	}while(0); \
	CU_basic_run_tests(); \
	fails = CU_get_number_of_tests_failed(); \
	warnx("%u tests failed", fails); \
	CU_cleanup_registry(); \
	return fails; \
}
