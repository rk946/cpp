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
class LinkedList{
public:
	node * head;
	node *tail ;
};

LinkedList flattenBST(node *root)
{
	LinkedList l;
	if(root==NULL)
	{
		l.head = l.tail = NULL;
		return l;
	}
	if(root->left ==NULL and root->right ==NULL)
	{
		l.head=l.tail=rootl
		return l;
	}
	if(root->left!=NULL && root->right==NULL)
	{
		LinkedList left = flattenBST(root->left);
		l.head = left.head;
		left.tail = root;
		l.tail = left.tail;
		return l
	}
	if(root->right!=NULL and root->left==NULL)
	{
		LinkedList right = flattenBST(root->right);

	}
}
int main()
{
	node *root = buildBST();
	BFSwithNewLine(root);
	cout << endl;
	inOrderPrint(root);
	cout << endl;
	LinkedList l = flattenBST(root);
	node * temp = l.head;
	while(temp!=NULL)
	{
		cout << temp->data;
		temp=temp->next;
	}
	return 0;
}