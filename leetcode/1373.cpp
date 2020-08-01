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

    int maxSumBST(node* root) {
        static int max_sum=INT_MIN;
        if(root==NULL)
        	return 0;
        int currSum = 0;
        currSum += root->data+maxSumBST(root->left)+max_sum(root->right);
        if(max_sum<currSum)
        	max_sum=currSum;
        ret
    }
int main()
{
	node *root = buildBST();
	BFSwithNewLine(root);
	inOrderPrint(root);

	maxSumBST(root);
	return 0;
}