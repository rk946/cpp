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

    void treetolist(TreeNode *root, vector<int> &res)
    {
        if(root==NULL)
            return;
        treetolist(root->left,res);
        res.push_back(root->val);
        treetolist(root->right,res);
    }
    void merge(vector<int> res1,vector<int> res2,vector<int> &res)
    {
        int m = res1.size();
        int n = res2.size();
        int i=0,j=0;
        while(i<m and j<n)
        {
            if(res1[i]<res2[j])
                res.push_back(res1[i++]);
            else
                res.push_back(res2[j++]);
        }
        while(i<m)
        {
            res.push_back(res1[i++]);
        }
        while(j<n)
        {
            res.push_back(res2[j++]);
        }
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res1;
        treetolist(root1,res1);
        vector<int> res2;
        treetolist(root2,res2);
        vector<int> res;
        merge(res1,res2,res);
        return res;
        
    }


int main()
{
	
	return 0;
}