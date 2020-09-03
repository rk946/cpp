#include<iostream>
#include<bits/stdc++.h>
using namespace std;

 bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<=i+k;j++)
            {
                int a=nums[i]-nums[j];
                if(a<0)
                    a=0-a;
                if(a<=t)
                    return true;
            }
        }
        return false;
        
    }

int main()
{
	vector<int> nums={1,5,9,1,5,9};
int k=2;
int t=3;
cout << containsNearbyAlmostDuplicate(nums,k,t);

	return 0;
}