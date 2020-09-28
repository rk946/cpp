#include<iostream>
#include<bits/stdc++.h>
using namespace std;

 void pathsum(TreeNode* root, int sum, vector<int> currsum, int &count)
    {
        if(root==NULL)
            return;
       
       
        currsum.push_back(0);
         int n=currsum.size();
        for(int i=0;i<n;i++)
        {
             currsum[i]+=root->val;
            if(currsum[i]==sum)
            {
                count++;
                currsum[i]=0;
            }
            else if(currsum[i]>sum)
                currsum[i]=0;
        }
        pathsum(root->left,sum,currsum,count);
        pathsum(root->right,sum,currsum,count);
        
        
    }
    int pathSum(TreeNode* root, int sum) {
        int count=0;
        vector<int> currsum;
        pathsum(root,sum,currsum,count);
        return count;
    }


int main()
{
 

	return 0;
}