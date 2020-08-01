#include<iostream>
#include<queue>
using namespace std;

class node{
public: 
	int data;
	node*left;
	node * right;
	node(int d)
	{
		data =d;
		left=NULL;
		right=NULL;
	}
};

node * buildTree(int *a, int s, int e)
{
	if(s>e)
		return NULL;
	int m=(s+e)/2;
	node * root = new node(a[m]);
	root->left = buildTree(a,s,m-1);
	root->right = buildTree(a,m+1,e);
	return root;
}


void BFS(node *root)
{
	if(root==NULL)
		return;
	queue<node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty())
	{
		node*f = q.front();
		cout << f->data<< " ";
		q.pop();
		
		{
			if(f->left!=NULL)
				q.push(f->left);
			if(f->right!=NULL)
				q.push(f->right);
		}
		if(q.front()==NULL)
		{
			cout << endl;
			q.pop();
			if(!q.empty())
			q.push(NULL);
			
		}
	}
	
}
//int in[]={20,2,1,10,10,3,-25,4};
	// int pre[] = {10,2,20,10,10,-25,3,1};
int maxSum(node *root)
{
	if(root==NULL)
		return 0;
	int sum=0;
	int leftSum = maxSum(root->left);
	int rightSum = maxSum(root->right);
	
	int a,b,c,d;
	if(root->data>0)
	{
		a=root->data;
		b = root->data+leftSum;
		c=root->data+rightSum;
		d = root->data+leftSum+rightSum;
		return max(max(a,b),max(c,d));
	}
	else
		return max(leftSum,rightSum);

}
int main()
{
	int a[100];
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	node * root = buildTree(a,0,n-1);
	BFS(root);
	cout<<endl;
	cout<<maxSum(root)<<endl;
	return 0;
}