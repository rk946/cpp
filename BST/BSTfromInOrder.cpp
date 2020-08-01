#include<iostream>
#include<queue>
#include<algorithm>
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
		l.head=l.tail=root;
		return l;
	}
	if(root->left!=NULL && root->right==NULL)
	{
		LinkedList left = flattenBST(root->left);
		l.head = left.head;
		left.tail->right = root;
		l.tail = root;
		return l;
	}
	if(root->right!=NULL and root->left==NULL)
	{
		LinkedList right = flattenBST(root->right);
		l.tail = right.tail;
		root->right = right.head;
		l.head=root;
		return l;

	}
	LinkedList left = flattenBST(root->left);
	LinkedList right = flattenBST(root->right);
	left.tail->right  = root;
	right.head->left = root;
	root->right = right.head;
	l.head = left.head;
	l.tail = right.tail;

	return l;


}
node * buildTreeFromPreandIn(vector<int> in, int s, int e)
{

}

int indexOf(int key, std::vector<int> in)
{
	for(int i=0;i<in.size();i++)
	{
		if(in[i]==key)
			return i;
	}
	return -1;
}
node * buildBSTFromPre(vector<int> pre)
{
	vector<int> in = pre;
	sort(in.begin(),in.end());
	node * root = new node(pre[0]);
	root->left = buildTreeFromPreandIn(in,0,indexOf(pre[0],in));
	root->right = buildTreeFromPreandIn(in,indexOf(pre[0],in),pre.size());
	



}
int main()
{
	vector<int> pre{5,3,1,7,6,8};
	node * root = buildBSTFromPre(pre);

	return 0;
}