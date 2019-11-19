#include <iostream>
using namespace std;

int main() {
	int i = 65;					//integer variable
	char c = i;					//character variable gets ascii value 
	cout << c << endl;			//prints A

	int * p = &i;				//p stores address of i
	char * pc = (char*)p;		//explicit type casting
								//p had 4 bytes of memory 0 0 0 65
	cout << p << endl;			//prints address
	cout << pc << endl;			//prints A because character pointer prints till it gets null pointer

	cout << *p << endl;			// print 65
	cout << *pc << endl;		//on defrencing first byte we get A
	cout << *(pc + 1) << endl;	//Null
	cout << *(pc + 2) << endl;	//Null

	cout << *(pc + 3) << endl;	//Null
								//Because it follows little endian

}

