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

node* createTree(int *in, int * pre, int s,int e)
{
	
	static int i=0;
	if(s>e)
		return NULL;
	int index=-1;
	node * root = new node(pre[i]);
	for(int j=s;j<=e;j++)
		{
			if(pre[i]==in[j])
				{
					index = j;
					break;
				}
	}
	i++;
	
	root->left = createTree(in,pre,s,index-1);
	root->right = createTree(in,pre,index+1,e);
	return root;
}
vector<int> res;
int max_level=-1;
void helper(node*root,int level)
{
	if(root==NULL)
		return;
	if(level>max_level)
	{
		max_level=level;
		res.push_back(root->data);
	}
	
	helper(root->left,level+1);
	helper(root->right,level+1);
}
void rightViewOfTree(node*root)
{
	helper(root,0);


}
int main()
{
	int in[]={3,2,8,4,1,6,7,5};
	int pre[] = {1,2,3,4,8,5,6,7};
	int n=sizeof(pre)/sizeof(int);
	node * root =createTree(in,pre,0,n-1);
	BFS(root);
	rightViewOfTree(root);
	// cout << res.size();
	for(int i=0;i<res.size();i++)
		cout << res[i];
	return 0;
}