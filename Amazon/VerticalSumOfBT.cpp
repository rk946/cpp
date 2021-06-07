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
    map<int,vector<int>> m;
    void helper(TreeNode* root, int level)
    {
        if(root==NULL)
            return;
        m[level].push_back(root->val);
        helper(root->left,level-1);
        helper(root->right,level+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        helper(root,0);
        vector<vector<int>> ans;
        for(auto v:m)
            ans.push_back(v.second);
        return ans;
    }


int main(){
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(7);
	vector<vector<int>> ans = verticalTraversal(root);
	vector<int> sum;
	for(auto e:ans)
	{
		int currsum=0;
		for(auto i:e)
			currsum+=i;
		sum.push_back(currsum);
	}
	cout <<endl<<"vertical sum "<<endl;
	for(auto e:sum)
		cout << e <<" ";
	
	return 0;
}