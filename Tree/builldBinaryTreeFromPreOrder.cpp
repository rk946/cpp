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

class lnode{
public:
	int data;
	lnode * next;
	lnode * prev;
	lnode(int d)
	{
		data=d;
		next=NULL;
		prev=NULL;
	}
};

void insertAtTail(lnode *&head, int data){

	if(head==NULL)
	{
		head=new lnode(data);
		return;
	}
	lnode *temp = head;
	while(temp->next!=NULL)
	{

		temp = temp->next;
	}

	lnode * temp2 = new lnode(data);
	temp2->prev = temp;
	temp->next = temp2;

}

void printDLL(lnode*head)
{
	while(head!=NULL)
	{
		cout << head->data<< " ";
		head=head->next;
	}
	cout <<endl;
}
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
void createDLLFromTree(node *root, lnode *&head)
{
	if(root==NULL)
		return;
	createDLLFromTree(root->left,head);
	insertAtTail(head,root->data);
	createDLLFromTree(root->right,head);

}

node * buildTreefromPre(vector<int> pre)
{
	static int index=0;
	if(pre[index]==-1)
	{
		index++;
		return NULL;
	}
	node * root = new node(pre[index++]);
	root->left = buildTreefromPre(pre);
	root->right = buildTreefromPre(pre);
	return root;
}


int main()
{
	vector<int> pre{10,20,5,-1,-1,9,3,-1,-1,-1,2,-1,6,-1,8,-1,-1};
	node * root = buildTreefromPre(pre);
	printAllLevels(root);
	return 0;
}