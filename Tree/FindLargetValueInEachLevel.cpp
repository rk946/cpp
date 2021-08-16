    #include <iostream>  
    #include <set> 
    #include<bits/stdc++.h> 
      
    using namespace std;  

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 


    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        if(root==NULL)
            return ans;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            int maxInRow = INT_MIN;
            for(int i=0;i<n;i++){
                TreeNode*temp = q.front();
                q.pop();
                maxInRow = max(maxInRow,temp->val);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                
                
            }
            ans.push_back(maxInRow);
        }
        return ans;
        
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
