#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]*/


 // * Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };




  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
  		vector<vector<int>>res;
  		queue<TreeNode*> q;
  		q.push(root);
  		q.push(NULL);
  		vector<int> level;
  		int i=0;
  		while(!q.empty())
  		{
  			TreeNode*temp = q.front();
  			q.pop();
  			if(temp==NULL)
  			{
  				if(i&1)
  					reverseLevel(level);
  				res.push_back(level);
  				
  				level.clear();
  				i++;
  				if(!q.empty())
				q.push(NULL);
  				
  			}
  			else
  			{
  				level.push_back(temp->val);

  				if(temp->left!=NULL)
  						q.push(temp->left);
  				if(temp->right!=NULL)
  						q.push(temp->right);
  				
  			}

  		}
  		return res;
        
    }


    void BFSwithNewLine(TreeNode *root)
{
	queue<TreeNode*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty())
	{
		TreeNode * f = q.front();
		if(f==NULL)
		{
			cout << endl;
			q.pop();
			if(!q.empty())
				q.push(NULL);
		}
		else{
			cout << f->val << " ";
			q.pop();
if(f->left!=NULL)
			q.push(f->left);
		if(f->right!=NULL)
			q.push(f->right);
		}


	}
}
 

int main()
{
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right->left = new TreeNode(6);
 	root->right->right = new TreeNode(7);

 	cout << "BFS : "<<endl;
 	BFSwithNewLine(root);
 	cout << endl;
 	
 	vector<vector<int>>res = zigzagLevelOrder(root);
 	
 	int n = res.size();
 	for(int i=0;i<n;i++)
 	{
 		int length = res[i].size();
 		for(int j=0;j<length;j++)
 		{
 			cout << res[i][j] << " ";
 		}
 		cout << endl;
 	}
	
	return 0;
}