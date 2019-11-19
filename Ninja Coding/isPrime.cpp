#include <iostream>
#include<cmath>
using namespace std;

bool isPrime(int x)
{
	if(x==1)
	return false;
	for(int i=2;i<(int)(sqrt(x))+1;i++)
	{
		if(x%i==0)
		{
			return false;	
		}
	}
	return true;
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int start,end;
		cin>>start>>end;
		for(int j=start;j<=end;j++)
		{
			if(isPrime(j))
			{
				cout<<j<<"\n";
			}
		}
	}
	return 0;
}
