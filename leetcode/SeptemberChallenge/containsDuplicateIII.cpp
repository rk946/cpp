#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Given an array of integers, 
// find out whether there are two distinct indices i and j in the array 
// such that the absolute difference between nums[i] and nums[j] is at most t
// and the absolute difference between i and j is at most k.


 bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<=i+k;j++)
            {
                int a = nums[i]-nums[j];
                if(a<0)
                    a=(0-a);
                if(a<=t)
                    return true;
                    
            }
                
        }
        return false;
        
    }
int main()
{
	vector<int> nums = {1};
	int k = 1, t = 1;
	cout << containsNearbyAlmostDuplicate(nums,k,t);

	return 0;
}