#include<iostream>
#include<algorithm>
using namespace std;

class edge
{
	public:
		int source;
		int dest;
		int  weight;
};

bool compare(edge e1,edge e2)
{
	return e1.weight<e2.weight;  //ascending order
}

int findParent(int v,int *parent)
{
	if(parent[v]==v)
	{
		return v;
	}
	return findParent(parent[v],parent);
}

void kruskals(edge* input,int n,int E)
{
	//sort the input array in ascending order based on weights
	sort(input,input+E,compare);
	edge * output=new edge[n-1];
	int * parent=new int[n];
	for(int i=0;i<n;i++)
	{
		parent[i]=i;
	}
	int count=0;
	int i=0;
	while(count!=n-1)
	{
		edge currentEdge=input[i];
		
		//check if we can add currentEdge in MST or not
		
		int source_parent=findParent(currentEdge.source,parent);
		int dest_parent=findParent(currentEdge.dest,parent);
		if(source_parent!=dest_parent)
		{
			output[count]=currentEdge;
			parent[source_parent]=dest_parent;
			count++;
		}
		i++;
	}
	for(int i=0;i<n-1;i++)
	{
		cout<<min(output[i].source,output[i].dest)<<max(output[i].source,output[i].dest)<<output[i].weight<<"\n";
	}
}

int main()
{
	int n,E;
	cin>>n>>E;
	edge * input=new edge[E];
	for(int i=0;i<E;i++)
	{
		cin>>input[i].source>>input[i].dest>>input[i].weight;
	}
	kruskals(input,n,E);
}
