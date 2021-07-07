#include<iostream>
#include<queue>
using namespace std;
/*
A non-empty binary tree T is balanced if: 
1) Left subtree of T is balanced 
2) Right subtree of T is balanced 
3) The difference between heights of left subtree and right subtree is not more than 1. 
*/
class node{
public:
	int data;
	node*left;
	node*right;
	node(int d)
	{
		data=d;
		left=NULL;
		right=NULL;
	}
};



node* buildTree()
{
	int d;
	cin>>d;
	if(d==-1)
		return NULL;
	node*root = new node(d);
	root->left = buildTree();
	root->right = buildTree();
	return root;
}

void printTreePre(node * root)
{
	if(root==NULL)
		return;
	cout<<root->data;
	printTreePre(root->left);
	printTreePre(root->right);
}
void printTreeIn(node * root)
{
	if(root==NULL)
		return;
	
	printTreeIn(root->left);
	cout<<root->data;
	printTreeIn(root->right);
}
void printTreePost(node * root)
{
	if(root==NULL)
		return;
	
	printTreePost(root->left);
	printTreePost(root->right);
	cout<<root->data;
}

int height(node *root)
{
	if(root==NULL)
		return 0;
	return max(height(root->left),height(root->right))+1;
}

void printKthLevel(node*root, int k)
{
	if(root==NULL)
		return;
	if(k==1)
	{
		cout<<root->data<<" ";
		return;
	}
	printKthLevel(root->left,k-1);
	printKthLevel(root->right,k-1);

}

void printAllLevels(node *root)
{
	for(int i=1;i<=height(root);i++)
	{
		printKthLevel(root,i);
		cout <<endl;
	}
}

void BFS(node *root)
{
	queue<node*> q;
	q.push(root);
	while(!q.empty())
	{
		node *f = q.front();
		cout<< f->data<< " ";
		q.pop();
		if(f->left!=NULL)
			q.push(f->left);
		if(f->right!=NULL)
			q.push(f->right);
	}
}
void BFSwithNewLine(node *root)
{
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty())
	{
		node * f = q.front();
		if(f==NULL)
		{
			cout << endl;
			q.pop();
			if(!q.empty())
				q.push(NULL);
		}
		else{
			cout << f->data << " ";
			q.pop();
if(f->left!=NULL)
			q.push(f->left);
		if(f->right!=NULL)
			q.push(f->right);
		}


	}
}

class Pair{
public:
	int height;
	bool heightBal;
};
Pair isHeightBalanced(node * root)
{
	Pair p;
	if(root==NULL)
	{
		p.height=0;
		p.heightBal = true;
		return p;
	}

	Pair left = isHeightBalanced(root->left);
	Pair right = isHeightBalanced(root->right);
	p.height = max(left.height,right.height)+1;
	int diff = (left.height - right.height);
	diff = diff>=0?diff:-diff;
	if(left.heightBal == false or right.heightBal==false or diff>=2 )
	{
		p.heightBal = false;
	}
	else
		p.heightBal=true;
	return p;


}
int main()
{
	node * root = buildTree();
/*	cout << "built tree"<<endl;
	printTreePre(root);
	cout<<endl;
	printTreeIn(root);
	cout<<endl;
	printTreePost(root);
	cout<<endl;
	cout << "height "<<height(root)<<endl;*/
	// printAllLevels(root);
	// cout<<endl;
	// BFS(root);
	
	BFSwithNewLine(root);
	cout<<endl;
	Pair p = isHeightBalanced(root);
	cout << "Height = "<<p.height<<endl;
	cout << "is height balanced = "<<p.heightBal <<endl;
	return 0;
}