//To solve the problem of size allocation
//two types of memory stack and heap memory
//when program starts stack memory is allocated
//Heap memory is very big
//int n;cin>>n,int a[n] may not work because of insufficient stack memory
//dynamic memory allocation occurs in heap memory
#include <iostream>
using namespace std;

int main() {
	int * p = new int;		//8 bytes on stack and 4 bytes on heap
							//new int gives address of int in heap
	*p = 10;
	cout << *p << endl;		//prints 10

	double *pd = new double;

	char* c = new char;

	int* pa = new int[50];		//stores the address of first index
								//200 bytes on heap and 8 bytes on stack
	int n;
	cout << "Enter num of elements" << endl; 
	cin >> n;

	int* pa2 = new int[n];		//we can do this compile time VERY  IMPORTANT
	for (int i = 0; i < n; i++) {
		cin >> pa2[i];			//pa2[i] means *(par+i)
	}

	int max = -1;
	for (int i = 0; i < n; i++) {
		if (max < a[i]) {
			max = a[i];
		}
	}
	cout << max << endl;
}

