#include<iostream>
#include<bits/stdc++.h>
#include<map>
using namespace std;

    int numIdenticalPairs(vector<int>& nums) {
    	int count=0;
    	int n=nums.size();
    	for(int i=0;i<n;i++)
    	{
    		for(int j=i+1;j<n;j++)
    		{
    			if(nums[i]==nums[j])
    				count++;
    		}
    	}
        return count;
    }

int main()
{
	vector<int> nums{1,2,3};
	
	cout << numIdenticalPairs(nums);

	cout << endl;

	// char* token = strtok(s," ");
	return 0;
}