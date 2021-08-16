#include<iostream>
#include<bits/stdc++.h>
using namespace std;


  // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };


 void inOrder(TreeNode* root, vector<int> &res)
    {
        if(root==NULL)
            return;
        inOrder(root->left,res);
        res.push_back(root->val);
        inOrder(root->right,res);
        
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inOrder(root,res);
        int n=res.size();
     	for(int i=0;i<n;i++)
     		cout << res[i] <<" , ";
     	cout << endl;

     	vector<int> res1;
        stack<TreeNode*> s;
        TreeNode*current=root;
        while(!s.empty() or current!=NULL)
        {
        	while(current!=NULL)
        	{
        		s.push(current);
        		current=current->left;
        		
        	}
        	current = s.top();
        	res1.push_back(current->val);
        	s.pop();
        	current = current->right;

        }
        n=res1.size();
        cout << "size = "<<n<<endl;
        for(int i=0;i<n;i++)
     		cout << res1[i] <<" , ";
     	cout << endl;
        
        return res;
        
    }


int main()
{
 	TreeNode*root=new TreeNode(1);
 	root->right = new TreeNode(2);
 	root->right->left = new TreeNode(3);
	inorderTraversal(root);
	return 0;
}