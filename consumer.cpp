#include <iostream>
#include <dlfcn.h>
using namespace std;

int main() {
	void *h = dlopen("/Users/logan/dll.so", RTLD_LAZY);
	if (!h) {
		cerr << "Failed to load so" << endl;
		return 1;
	}
	dlerror();
	int (*ktt)(void) = (int(*)(void))dlsym(h, "kill_the_thing");
	void *e = dlerror();
	if (e) {
		cerr << e << endl;
		return 2;
	}

	cout << ktt() << endl;
	return 0;
}