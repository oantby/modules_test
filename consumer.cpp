#include <dlfcn.h>

int main() {
	void *h1 = dlopen("./1.so", RTLD_LAZY);
	void *h2 = dlopen("./2.so", RTLD_LAZY);
	void (*f)(void) = (void(*)(void))dlsym(h2, "twoDoThing");
	f();
	dlclose(h1);
	dlclose(h2);
	return 0;
}