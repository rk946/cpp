#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 int missingNumber(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=n)
                nums[nums[i]]=-1;
        }
        for(int i=0;i<n;i++)
        {
            cout << nums[i]<<endl;
            // if(nums[i]!=-1)
            //     return i;
        }
        return n;
        
    }
int main()
{
	vector<int> nums;
	nums.push_back(9);
	nums.push_back(6);
	nums.push_back(4);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(5);
	nums.push_back(7);
	nums.push_back(0);
	nums.push_back(1);
	cout << "missing number = "<<missingNumber(nums)<<endl;

	return 0;

}