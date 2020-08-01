#include<iostream>
#include<bits/stdc++.h>
#include<map>
using namespace std;

    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> sub;
        for(int i=0;i<n;i++)
        {
        	sub.push_back(nums[i]);
        	for(int j=i+1;j<n;j++)
        	{
        		sub.push_back(sub.back()+nums[j]);
        	}
        }

        sort(sub.begin(),sub.end());

        int sum=0;
       for(int i=0;i<sub.size();i++)
       {
       	cout << sub[i]<<" ";
       }
       cout << endl;
        for(int i=left-1;i<=right-1;i++)
        {
        	sum+=sub[i];
        }
       return sum;
    }
int main()
{
	vector<int> nums{1,2,3,4};
	int n=4;
	int left=1,right=10;
	cout << rangeSum(nums,n,left,right);

	cout << endl;

	// char* token = strtok(s," ");
	return 0;
}