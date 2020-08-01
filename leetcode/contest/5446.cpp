#include<iostream>
#include<bits/stdc++.h>
#include<map>
using namespace std;

    int minDifference(vector<int>& nums) {
    	sort(nums.begin(),nums.end());
    	int res;
    	
    	int n = nums.size();
    	if(n<=3)
    		return 0;
    	
    	int a,b,c,x,y,z;
    	a=nums[0];b=nums[1];c=nums[2];x=nums[n-3];y=nums[n-2];z=nums[n-1];
    	// cout <<"size = "<<n;
    	//case1
    	if(nums[0]>=0)
    		return nums[n-4]-nums[0];
    	// -+++
    	if(a<0 and b>0)
    	{
    		return nums[n-3]-nums[1];

    	}
    	//--+
    	if(a<0 and b<0 and c>0)
    	{
    		return nums[n-2]-nums[2];

    	}
    	//---	
    	if(a<0 and b<0 and c<0)
    	{
    		return nums[n-4]-nums[3];
    	}
    	

    	        
    }
int main()
{
	vector<int> nums{6,6,0,1,1,4,6};
	
	cout << minDifference(nums);

	cout << endl;

	// char* token = strtok(s," ");
	return 0;
}