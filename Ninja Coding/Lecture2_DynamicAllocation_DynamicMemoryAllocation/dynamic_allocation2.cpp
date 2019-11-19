#include <iostream>
using namespace std;

int main() {

	int *p = new int;
	delete p;			//delete is important to delete memory allocated on heap because there is no scope for this memory
						//otherwise system will crash
						//delete p does not delete p but the integer it is pointing
	p = new int;
	delete p;

	p = new int[100];
	delete [] p;

	/*
	while (true) {
		int *p = new int;
	}
	
	while (true) {
		int i = 10;
	}
*/

}

