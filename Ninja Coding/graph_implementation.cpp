#include<iostream>
#include<queue>
using namespace std;

void printBFS(int ** edges,int n,int sv,bool* visited)
{
	queue<int> pendingVertices;
	pendingVertices.push(sv);
	while(!pendingVertices.empty())
	{
		int temp=pendingVertices.front();
		pendingVertices.pop();
		cout<<temp<<" ";
		for(int i=0;i<n;i++)
		{
			if(i==temp)
			{
				continue;
			}
			if(edges[temp][i]==1 && !visited[i])
			{
				visited[i]=true;
				pendingVertices.push(i);
			}
		}
	}
}

void printDFS(int ** edges,int n,int sv,bool* visited)
{
	cout<<sv<<" ";
	visited[sv]=true;
	for(int  i=0;i<n;i++)
	{
		if(i==sv)
		{
			continue;
		}
		if(edges[sv][i]==1)
		{
			if(!visited[i])
			{
				visited[i]=true;
				printDFS(edges,n,i,visited);
			}
		}
	}
}

void BFS(int** edges,int n)
{
	bool* visited=new bool[n];
	for(int i=0;i<n;i++)
	{
		visited[i]=false;
	}
	for(int i=0;i<n;i++)
	{
		if(!visited[i])
		{
			printBFS(edges,n,i,visited);
		}
	}
	delete [] visited;
}

void DFS(int** edges,int n)
{
	bool* visited=new bool[n];
	for(int i=0;i<n;i++)
	{
		visited[i]=false;
	}
	for(int i=0;i<n;i++)
	{
		if(!visited[i])
		{
			printDFS(edges,n,i,visited);
		}
	}
	delete [] visited;
}

int main()
{
	int n,e;
	cin>>n>>e;
	int ** edges=new int* [n];
	for(int i=0;i<n;i++)
	{
		edges[i]=new int[n];
		for(int j=0;j<n;j++)
		{
			edges[i][j]=0;
		}
	}
	for(int i=0;i<e;i++)
	{
		int f,s;
		cin>>f>>s;
		edges[f][s]=1;
		edges[s][f]=1;
	}
	cout<<"DFS implementation:\n";
	DFS(edges,n);
	cout<<"\nBFS implementation\n";
	BFS(edges,n);
	
	return 0;
}
