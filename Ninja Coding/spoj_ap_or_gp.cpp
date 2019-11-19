#include <iostream>
using namespace std;

bool checkExpArith(double exp[])
{
	double diff=exp[1]-exp[0];
	cout<<exp[1]-exp[0]<<"\n";
	cout<<diff<<"\n";
	if(diff==exp[2]-exp[1])
	{
		cout<<exp[2]-exp[1]<<"\n";
		return true;
	}
	else
	{
		cout<<exp[2]-exp[1]<<"\n";
		return false;	
	}
}

bool checkExpGP(double exp[])
{
	double multi=exp[1]/exp[0];
	if(multi==exp[2]/exp[1])
		return true;
	else
		return false; 
}

int main() {
	int testCases;
	for(int i=0;i<testCases;i++)
	{
		double  exp[3];
		for(int i=0;i<3;i++)
		{
			cin>>exp[i];
		}
		if(checkExpArith(exp) && checkExpGP(exp))
			cout<<"Both"<<"\n";
		else if(checkExpArith(exp))
			cout<<"Arithmetic"<<"\n";
		else if(checkExpGP(exp))
			cout<<"Geometric"<<"\n";
		else cout<<"None"<<"\n";
	}
	// your code goes here
	return 0;
}
