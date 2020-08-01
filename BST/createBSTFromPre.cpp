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

node * createTree(vector<int>pre, vector<int> in, int s, int e)
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
	
	root->left = createTree(pre,in,s,index-1);
	root->right = createTree(pre,in, index+1,e);
	return root;
}
node * createBSTFromPre(vector<int> pre)
{
	vector<int> in =pre;
	sort(in.begin(),in.end());

	for(int i=0;i<in.size();i++)
		cout << in[i]<<" ";
	cout <<endl;
	return createTree(pre,in,0,in.size()-1);

	// return root;
}

int main()
{
	vector<int> pre{5,3,1,7,6,8};
	node *root = createBSTFromPre(pre);
	BFSwithNewLine(root);
	cout <<endl;
	inOrderPrint(root);
	return 0;
}