#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

// Example 1:

// Input: [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.
// Example 2:

// Input: [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

 int maxProduct(vector<int>& nums) {
     int max_product=INT_MIN, product_sofar=1;
     bool isNegative=false;
     int n=nums.size();
     int j=0,k=-1;
    while(j!=-1 and k!=j)
    {
    	k=j;
     	product_sofar=1;
     	for(int i=j;i<n;i++)
     	{ 
     		if(nums[i]==0)
     		{
     			isNegative=false;
     			j=i+1;
     			if(j>=n)
     				j=-1;
     			product_sofar=0;
     			break;

     			
     		}
     		else if(nums[i]<0)
     		{
     			isNegative=(!isNegative);
     			if(isNegative)
     				j=i+1;
     			else
     				j=-1;
     		}
     		
     		

     		product_sofar*=nums[i];
     		if(max_product<product_sofar)
     			max_product=product_sofar;
     	}
     	if(max_product<product_sofar and k!=j)
     			max_product=product_sofar;

     }
     return max_product;

    }

int main()
{
	vector<int> nums{2,-5,-2,-4,3};
	cout << maxProduct(nums);
	return 0;
	
}