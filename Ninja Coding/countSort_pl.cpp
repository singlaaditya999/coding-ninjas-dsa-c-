#include<unordered_map>
#include<climits>
#include<iostream.h>
using namespace std;

int main()
{
	int arr[100];
	int size;
	int maxValue=INT_MIN;
	cout<<"Enter size of input:";
	cin>>size;
	cout<<"\n";
	cout<<"Enter array to be sorted:";
	for(int i=0;i<size;i++)
	{
		cin>>arr[i];
		if(arr[i]>maxValue)
			maxValue=arr[i];	
	}
	cout<<"\nSorted array is:";
	int * sortedArr=new int[10000];
	for(int i=0;i<=maxValue;i++)
		sortedArr[i]=0;
	for(int i=0;i<size;i++)
	{
		sortedArr[arr[i]]++;
	}
	for(int i=0;i<=maxValue;i++)
	{
		for(int j=0;j<sortedArr[i];j++)
		{
			cout<<j<<" ";
		}
	}
	return 0;
}
