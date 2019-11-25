#include <iostream>
using namespace std;

extern "C" {

void thing(int *r, bool go = false) {
	#ifdef DEBUG
	cerr << "Invoking " << __FUNCTION__ << " from " << __FILE__ << endl;
	#endif
	go && (*r = 3);
}

void identify() {
	cout << "I'm module 3.  I set values to 3!" << endl;
}

}