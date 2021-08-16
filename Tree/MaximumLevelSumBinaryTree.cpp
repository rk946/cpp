    #include <iostream>  
    #include <set> 
    #include<bits/stdc++.h> 
      
    using namespace std;  
/*
Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.

Return the smallest level x such that the sum of all the values of nodes at level x is maximal.
\\\


Input: root = [1,7,0,7,-8,null,null]
Output: 2
Explanation: 
Level 1 sum = 1.
Level 2 sum = 7 + 0 = 7.
Level 3 sum = 7 + -8 = -1.
So we return the level with the maximum sum which is level 2.

*/


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 


    int maxLevelSum(TreeNode* root) {
        
        queue<TreeNode*> q;
        if(root==NULL)
            return 0;
        q.push(root);
        int maxSum=INT_MIN;
        int levelmaxSum=1;
        int level = 1;
        while(!q.empty()){
            int n = q.size();
            int sumRow=0;
            for(int i=0;i<n;i++){
                TreeNode*temp = q.front();
                q.pop();
                sumRow+=temp->val;
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            
            // cout << maxSum << " "<<sumRow<<endl;
            if(maxSum < sumRow){
                maxSum = sumRow;
                levelmaxSum = level;
            }
            level++;
        }
        
        return levelmaxSum;
        
    }
    
    int main()  
    {
        TreeNode*root = new TreeNode(1);
        root->left = new TreeNode(3);
        root->right = new TreeNode(2);
        root->left->left = new TreeNode(5);
        root->left->right = new TreeNode(3);
        root->right->left =  new TreeNode(9);
        vector<int> ans = largestValues(root);
        for(int element : ans)
            cout << element << endl;
                return 0;
    }  
