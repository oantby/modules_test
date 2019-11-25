#include <iostream>
#include <dlfcn.h>
#include <map>
using namespace std;

map<const char *, void *> modules;
void loadModules();

template <typename... Ts>
void invokeHook(string hook, Ts... args) {
	
	for (const pair<const char *, void *> m : modules) {
		void(*f)(Ts...) = (void(*)(Ts...))dlsym(m.second, hook.c_str());
		
		if (!f) {
			// module doesn't implement hook
			#ifdef DEBUG
			cerr << "Hook \"" << hook << "\" not found for module " << m.first << endl;
			cerr << dlerror() << endl;
			#endif
			continue;
		}
		f(args...);
	}
}

int main() {
	loadModules();
	int v = 21;
	invokeHook("thing", &v, true);
	v = 10;
	invokeHook("thing", &v, true);
	cout << v << endl;
	return 0;
}

void loadModules() {
	const char *modulesList[] = {"./1.so", "./2.so", "./3.so", "./4.so", "./5.so"};
	for (const char *m : modulesList) {
		void *h = dlopen(m, RTLD_LAZY);
		if (!h) {
			cerr << "Failed to load module \"" << m << "\": " << dlerror() << endl;
			continue;
		}
		modules[m] = h;
	}
}