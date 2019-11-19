#include<iostream>
#include<queue>
#include "TreeNode.h"

using namespace std;

TreeNode <int> * TakeInputLevelWise()
{
	int rootData;
	cout<<"Enter valu of root:";
	cin>>rootData;
	
	TreeNode <int> * root=new TreeNode<int> (rootData);
	
	queue <TreeNode<int>*> pendingNodes;
	
	pendingNodes.push(root);
	
	while(pendingNodes.size()!=0)
	{
		TreeNode<int>* front=pendingNodes.front();
		pendingNodes.pop();
		cout<<"Enter the no. of children of"<<front->data;
		int numChild;
		cin>>numChild;
		for(int i=0;i<numChild;i++)
		{
			int childData;
			cout<<"Enter the i th data of"<<front->data<<":";
			cin>>childData;
			TreeNode<int>* child=new TreeNode<int>(childData);
			front->children.push_back(child);
			pendingNodes.push(child);
		}
	}
	return root;
}

void print(TreeNode<int>* root)
{
	if (root==NULL)
	{
		return ;
	}
	
	cout<<root->data<<":";
	
	for(int i=0;i< root->children.size();i++)
	{
		cout<<root->children[i]->data<<",";
	}
	cout<<endl;
	for(int i=0;i<root->children.size();i++)
	{
		print(root->children[i]);
	}
	return;
}

int main()
{
	TreeNode<int>* root=TakeInputLevelWise();
	print (root);
	return 0;
}
