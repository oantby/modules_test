#include <dlfcn.h>

extern "C" void twoDoThing() {
	void (*f)() = (void (*)())dlsym(RTLD_DEFAULT, "sayOne");
	f();
}