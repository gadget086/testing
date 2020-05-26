#include <stdlib.h>
#include <stdio.h>

typedef struct {
	char * name;
	void (*func)(void);
} Test;

#define CHECK(name) void test_ ## name(void)
#define TEST(name) {#name, test_ ## name}

CHECK(hello){
    printf("Hello from inside function!\n");
}
int main(int argv, char **args) {
    Test hello = TEST(hello);
    printf("Name: %s\n", hello.name);
    hello.func();
    return 0;
}
