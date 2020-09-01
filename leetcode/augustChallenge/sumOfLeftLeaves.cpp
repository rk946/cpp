#include<iostream>
#include<queue>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
int max_level=-1;
int helper(TreeNode *root, int level)
{
	if(root == NULL)
		return 0;
	int res=0;
	if(level>max_level)
	{
		max_level=level;
		if(root->left==nullptr and root->right==nullptr)
			res +=root->val;
	}
	
		res+=helper(root->left,level+1);
		res+=helper(root->right,level+1);
		return res;
}

int sumOfLeftLeaves(TreeNode* root) {
	int res=0;
	if(root==NULL)
		return 0;
	if(root->left==nullptr and root->right == nullptr)
			return 0;
	

		

        
    }
int main(){
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);
	cout << sumOfLeftLeaves(root);
	return 0;
}