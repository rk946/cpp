#include<bits/stdc++.h>
using namespace std;

int main()
{
	int arr[] = {5,1,8,3,4};
	int  n = sizeof(arr)/sizeof(int);
	int k=3;
	vector<int> ans;
	int i=0,j=0;
	int sum=0,maxsum=0;
	int t=0;
	for(;j<k;j++)
	{
		sum+=arr[j];
		maxsum = sum;
	}
	for(;j<n;j++)
	{
		sum+=(arr[j]-arr[i]);
		i++;
		maxsum = max(maxsum,sum);	
	}
	cout << maxsum;

	return 0;
}
