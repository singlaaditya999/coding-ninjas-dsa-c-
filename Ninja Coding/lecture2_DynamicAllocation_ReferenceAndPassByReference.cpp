//Reference Variable & two ways of going to same memory
//benefit eg. to reflect changes in increment function

#include <iostream>
using namespace std;

void increment(int& i) {	//i pointing to parameter given in main
	i++;					//changes made here will be reflected elsewhere also
}							//share local variables if passing by refernece

// bad practice
//return by reference returning the same a
//that is main a in this function will be used
//Problem is scope issue
//The function will clear this memory
int& f(int n) {
	int a = n;
	return a;
}

// bad practice
//return integer pointer
//that is pointer to variable which no longer exists
int* f2() {
	int i = 10;
	return &i;
}

int main() {
	int* p = f2();

	int i;
	i = 10;

	int& k1 = f(i);


	increment(i);
	cout << i << endl;

	int& j = i;

	i++;
	cout << j << endl;
	j++;
	cout << i << endl;

	int k = 100;
	j = k;
	cout << i << endl;
}

