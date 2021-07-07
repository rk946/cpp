#include<iostream>
#include<queue>
using namespace std;
//The diameter of a tree (sometimes called the width)
// is the number of nodes on the longest path between two end nodes.
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
	return 1+max(height(root->left),height(root->right));
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

//The diameter of a tree (sometimes called the width)
// is the number of nodes on the longest path between two end nodes.

int diameter(node *root){
	if(root==NULL)
		return 0;
	int d1,d2,d3;
	d1= height(root->left)+height(root->right);
	d2 = diameter(root->left);
	d3=diameter(root->right);
	return max(max(d1,d2),d3);


}
class Pair{
	public:
		int height;
		int diameter;
};
Pair diameterFast(node *root){
	Pair p;
	if(root==NULL)
	{
		p.height=0;p.diameter=0;
		return p;
	}
	
	
	Pair d2 = diameterFast(root->left);
	Pair d3 = diameterFast(root->right);

	int d1= d2.height+d3.height;
	p.diameter = max(max(d1,d2.diameter),d3.diameter);
	p.height = max(d2.height,d3.height)+1;
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
	// cout<<endl;
	BFSwithNewLine(root);
	cout << endl;
	// cout << count(root);
	// cout << endl;
	// cout << sum(root);
	// cout <<endl;
	cout << diameterFast(root).height;
	cout << diameterFast(root).diameter;
	return 0;
}