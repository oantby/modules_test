#include <iostream>
using namespace std;

extern "C" {

void thing(int *r, bool go = false) {
	#ifdef DEBUG
	cerr << "Invoking " << __FUNCTION__ << " from " << __FILE__ << endl;
	#endif
	go && (*r = 4);
}

}