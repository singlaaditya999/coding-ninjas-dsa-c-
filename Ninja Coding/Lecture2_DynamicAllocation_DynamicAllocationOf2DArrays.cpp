//Creatin 2D Arrays
//collection of int* type of rows
//to create array of int* we creaate array of int**
#include <iostream>
using namespace std;

int main() {
	int m, n;
	cin >> m >> n;
	int** p = new int*[m];
	for (int i = 0; i < m; i++) {
		p[i] = new int[i + 1];
		for (int j = 0;j <n; j++) {
			cin >> p[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		delete [] p[i];		//delete array
	}
	delete [] p;
}

