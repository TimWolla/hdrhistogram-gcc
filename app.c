#include <dlfcn.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int foo, bar;

	void *handle = dlopen("./lib.so", RTLD_LAZY);


	int64_t (*hdr_test)(int *, int *) = dlsym(handle, "hdr_test");

	int64_t count = hdr_test(&foo, &bar);

	printf("%ld\n", count);
}
