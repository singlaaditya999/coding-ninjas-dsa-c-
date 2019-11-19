//vectors are like dynamic array without size constraint
//vector is a template
#include <iostream>
#include <vector>
using namespace std;

int main() {
	//vector<int> * vp = new vector<int>(); 		dynamic allocation
	vector<int> v;						//static allocation

	for (int i = 0; i < 100; i++) {
		cout << "cap:" << v.capacity() << endl;		//capacity () gives size of underlying array capacity doubled when size<capacity
		cout << "size:" << v.size() << endl;		//size increases by 1
		v.push_back(i + 1);
	}

	v.push_back(10);		//inserted in the end
	v.push_back(20);		//checks current size etc.
	v.push_back(30);		//direct change wont change size
		//on each push back capacity is doubled
	v[1] = 100;				//can be treated just like array

	// dont use [] for inserting elements ,use it to get value or update
	//v[3] = 1002;
	//v[4] = 1234;

	v.push_back(23);
	v.push_back(234);

	v.pop_back();		//removes the last element

	/*
	for (int i = 0; i < v.size(); i++) {	loop to print elements
		cout << v[i] << endl;				[] because within range
	}


	cout << v[0] << endl;
	cout << v[1] << endl;
	cout << v[2] << endl;
	cout << v[3] << endl;
	cout << v[4] << endl;
	cout << v[5] << endl;
	cout << v[6] << endl;

	cout << "Size: " << v.size() << endl;		gives the size of vector

	cout << v.at(2) << endl;		gives the value at position index 2
	cout << v.at(6) << endl;
	*/
}

