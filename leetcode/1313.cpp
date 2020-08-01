#include<iostream>
#include<vector>
using namespace std;

    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> res;
        for(int i=1;i<nums.size();)
        {
        	for(int j=0;j<nums[i-1];j++)
        		res.push_back(nums[i]);
        	i=i+2;
        }
        return res;
    }


int main()
{
 
	vector<int> nums{1,2,3,4};
	vector<int> res = decompressRLElist(nums);
	for(int i=0;i<res.size();i++)
	{
		cout << res[i] << " , ";
	}
	return 0;
}