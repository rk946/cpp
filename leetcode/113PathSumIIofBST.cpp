#include<iostream>
#include<bits/stdc++.h>
using namespace std;

    void pathsum(TreeNode*root, vector<int> path, vector<vector<int>> &res, int sum, int currsum)
    {
        if(root==NULL)
        {
            return;
        }
        
        
        currsum+=root->val;
        path.push_back(root->val);
        if(root->left==NULL and root->right==NULL and currsum==sum)
        {
            res.push_back(path);
            return;
        }
        pathsum(root->left,path,res,sum,currsum);
        pathsum(root->right,path,res,sum,currsum);
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        pathsum(root,path,res,sum,0);
        return res;
    }

int main()
{
 

	return 0;
}