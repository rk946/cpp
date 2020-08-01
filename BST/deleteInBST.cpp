#include<iostream>
#include<queue>
using namespace std;
// template<typename T>
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
node * buildBSTTree(node *root, int data)
{
	if(root==NULL)
		return new node(data);
	// node * res;
	if(data<=root->data)
	{
		root->left = buildBSTTree(root->left,data);
	}
	else
	{
		root->right = buildBSTTree(root->right,data);
	}
	return root;
}

node* buildBST()
{
	int d;
	cin>>d;
	node * root=NULL;
	while(d!=-1)
	{
		root = buildBSTTree(root,d);
		cin>>d;
	}
	return root;

}

void inOrderPrint(node *root)
{
	if(root==NULL)
		return;
	inOrderPrint(root->left);
	cout << root->data << ",";
	inOrderPrint(root->right);
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

bool search(node *root, int data)
{
	if(root==NULL)
		return false;
	if(root->data == data)
		return true;
	else if(data <= root->data )
		return search(root->left,data);
	else
		return search(root->right,data);
}

node * deleteInBST(node*root,int data)
{
	if(root==NULL)
		return NULL	;
	if(data<root->data)
	{
		root->left = deleteInBST(root->left, data);
		return root;
	}
	else if(root->data == data)
	{
		if(root->left == NULL and root->right == NULL)
		{
			delete root;
			return NULL;
		}
		if(root->left!=NULL and root->right == NULL)
		{
			node * temp = root->left;
			delete root;
			return temp;
		}
		else if(root->left==NULL and root->right !=NULL)
		{
			node *temp = root->right;
			delete root;
			return temp;
		}
		 // if (root->left!=NULL and root->right!=NULL)
		{
			node *replace = root->right;
			while(replace->left!=NULL)
			{
				replace = replace->left;
			}
			root->data = replace->data;
			root->right = deleteInBST(root->right,replace->data);
			return root;
		}

		



	}
	else{
		root->right = deleteInBST(root->right, data);
		return root;
	}
	return root;

}
int main()
{
	node *root = buildBST();
	BFSwithNewLine(root);
	// inOrderPrint(root);
	cout << endl;
	int n;
	cin >> n;
	while(n!=-1)
	{
		deleteInBST(root,n);
		BFSwithNewLine(root);
		cout << endl;
		cin>>n;
	}
	return 0;
}