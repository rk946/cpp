#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
    int findDuplicate(vector<int>& nums) {
        int res=-1;
        int size = nums.size();
        for(int i=0;i<size;i++)
        {
        	for(int j=i+1;j<size;j++)
        	{
        		if(nums[i]==nums[j])
        		{
        			return nums[i];
        			
        		}
        	}
        }
        return -1;
    }
int main()
{

	vector<int> a{1,2,2,3,3,4,5,3};
	cout << findDuplicate(a);
	return 0;

}