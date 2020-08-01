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
node*lca=NULL;
node * LCA(node *root, int p, int q)
{
	if(root==NULL)
		return root;
	if(root->data == p or root->data==q )
		{
			return root;
		}
	node * left = LCA(root->left,p,q);
	node * right = LCA(root->right,p,q);

	if(left!=NULL and right!=NULL)
		return root;
	else if(left==NULL and right!=NULL)
		return right;
	else if(left!=NULL and right==NULL)
		return left;
	else 
		return NULL;


}
int distanceFromRoot(node *root, int p, int level)
{
	if(root==NULL)
		return -1;
	if(root->data==p)
		return level;
	int a = distanceFromRoot(root->left,p,level+1);
	int b = distanceFromRoot(root->right,p,level+1);
	if(a!=-1)
		return a;
	if(b!=-1)
		return b;
	return -1;


}
int distanceBetweenPandQ(node*root,int p, int q)
{
	int d;
	int a=distanceFromRoot(root,p,0);
	int b=distanceFromRoot(root, q,0);
	node *lca = LCA(root,p,q);
	int c = distanceFromRoot(root,lca->data,0);
	d=a+b-(2*c);
	return d;

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
	printAllLevels(root);
	cout<<endl;
	BFS(root);
	cout<<endl;
	BFSwithNewLine(root);
	int p,q;
	cin>>p>>q;
	node *lca = LCA(root,p,q);
	cout << lca->data;

	cout << endl;

	cout << "distance between "<<p<<" and "<<q <<" = "<<distanceBetweenPandQ(root,p,q);
	return 0;
}