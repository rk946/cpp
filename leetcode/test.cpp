#include<iostream>
#include<vector>
// #include<bitset>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
       TreeNode*sort(vector<int> &nums, vector<bool> &arr, int s, int e)
    {
        if(s>e)
            return NULL;
        int mid = (s+e)/2;
        if(!arr[mid])
        {   
            TreeNode * root = new TreeNode(nums[mid]);
            arr[mid] = true;
            root->left = sort(nums,arr,s,mid-1);
            root->right = sort(nums,arr,mid+1,e);
            return root;
        }
        else
            return NULL;
    }
 TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size()-1;
        vector<bool> arr(n,false);
        
        return  sort(nums,arr,0,n);
        
        
        
    }
    

int main()
{
	string s="ADOBECODEBANC";
	int i = s.find('A');
	cout << i <<endl;
}