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
int leftmost=INT_MAX, rightmost=INT_MIN;

void getwidth(TreeNode*root, int level){
	if(root==NULL)
		return ;
	leftmost = min(leftmost, level);
	rightmost = max(rightmost, level);
	getwidth(root->left,level-1);
	getwidth(root->right,level+1);


}

int main(){
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(7);

	getwidth(root,0);
	cout <<"width = "<<rightmost-leftmost<<endl;
	return 0;
}