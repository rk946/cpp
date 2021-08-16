#include<iostream>
#include<bits/stdc++.h>
using namespace std;

    vector<int> findDuplicates(vector<int>& nums) {

        vector<int> res;
        if(nums.size()==0)
        	return res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]==nums[i+1])
            {
                res.push_back(nums[i]);
                while(nums[i]==nums[i+1])
                    i++;
            }
                
        }
        return res;
        
    }

int main()
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(1);
 	vector<int> res = findDuplicates(nums);
 	for(int i=0;i<res.size();i++)
 		cout << res[i]<<",";

	return 0;
}