#include<iostream>
#include<queue>
using namespace std;

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
int count(node *root)
{
	if(root==NULL)
		return 0;
	return 1+count(root->left)+count(root->right);
}
int sum(node *root)
{
	if(root==NULL)
		return 0;
	return root->data+sum(root->left)+sum(root->right);
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
	// cout<<endl;
	BFSwithNewLine(root);
	cout << endl;
	cout << count(root);
	cout << endl;
	cout << sum(root);
	cout <<endl;
	return 0;
}