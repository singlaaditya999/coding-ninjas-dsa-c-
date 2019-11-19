#include <iostream>
#include<string>
#include<stack>
using namespace std;

void printTransform(char exp[])
{
	char *e=exp;
	stack<char> s;
	while(*e!='\0')
	{
		int x;
		x=*e;
		if(x>=97 && x<=122)
		{
			cout<<*e;
		}
		else if(*e=='(')
		{
			s.push(*e);
		}
		else if(*e==')')
		{
			cout<<s.top();
			s.pop();
			s.pop();
		}
		else{
			s.push(*e);
		}
		e=e+1;
	}
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	for(int i=0;i<=t;i++)
	{
		char exp[400];
		cin.getline(exp,400);
		printTransform(exp);
		cout<<"\n";
	}
	return 0;
}
