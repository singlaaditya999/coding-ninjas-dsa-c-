#include<iostream>
using namespace std;

int convertIntToArray(int * xpt,int x)
{
	int i=0;
	while(x!=0)
	{
		xpt[i++]=x%10;
		x=x/10;
	}
	return  i-1;
}

int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int x;
		cin>>x;
		x++;
		int * xpt=new int [1000000];
		int front=convertIntToArray(xpt,x);
		int j=0;
		while(front-j>j)
		{
			if(xpt[j]<xpt[front-j]){
				xpt[j]=xpt[front-j];
			}
			else if(xpt[j]>xpt[front-j]){
				xpt[j]=xpt[front-j];
				xpt[j+1]+=1;
			}
			j++;
		}
		if(front%2!=0)
			xpt[front/2]=xpt[front/2+1];
		for(int k=front;k>=0;k--)
		cout<<xpt[k];
		cout<<"\n";
		delete[] xpt;
	}
}





















