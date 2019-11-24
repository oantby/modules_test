#include <iostream>
#include <dlfcn.h>
using namespace std;

int thing(int a, string b, double c) {
	cout << a << '\n' << b << '\n' << c << '\n';
	return a/c;
}

template <typename... Ts>
void invokeHook(string hook, Ts... args) {
	int (*f)(Ts...) = thing;
	if (hook == "thing") {
		cout << f(args...) << '\n';
	}
}

int main() {
	invokeHook("thing", 5, string("hello"), 1.24);
	return 0;
}