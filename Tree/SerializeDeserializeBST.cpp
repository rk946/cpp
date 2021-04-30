#include<iostream>
#include<bits/stdc++.h>
using namespace std;


 // * Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };


    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL)
            return "";
        
        string s = to_string(root->val);
        s+=serialize(root->left);
        s+=serialize(root->right);
        return s;
        
    }

TreeNode* createTree(int *in, int * pre, int s,int e)
{
	
	static int i=0;
	if(s>e)
		return NULL;
	int index=-1;
	TreeNode * root = new TreeNode(pre[i]);
	for(int j=s;j<=e;j++)
		{
			if(pre[i]==in[j])
				{
					index = j;
					break;
				}
	}
	i++;
	
	root->left = createTree(in,pre,s,index-1);
	root->right = createTree(in,pre,index+1,e);
	return root;
}
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        int n = data.length();
        if(n==0)
            return NULL;
        int pre[n],in[n];
        for(int i=0;i<n;i++)
        {
            pre[i]=data[i]-'0';
            in[i] = pre[i];
        }
        sort(in, in+n);


        cout << "pre order traversal : "<<endl;
        
        return createTree(in,pre,0,n-1);
    }

    void printTree(TreeNode*root)
    {
        if(root==NULL)
            return;
        cout << root->val;
        printTree(root->left);
        printTree(root->right);
    }

    int main()
    {
        TreeNode*root = new TreeNode(10);
        root->left = new TreeNode(5);
        root->left->right = new TreeNode(8);
        root->right = new TreeNode(15);
        root->right->left=new TreeNode(12);
        
        string s = serialize(root);
        cout << s <<endl;
        TreeNode*newRoot = deserialize(s);
        printTree(newRoot);
        return 0;
    }