#include<bits/stdc++.h>

using namespace std;

//Divide the array into subsets such that sum of subarrays have minimum difference 
//Output will be the minimum difference between two subsets

int minimumSubsetSum(int arr[],int sum, int n)
{
	bool dp[n+1][sum+1];

	//Initialization
	for(int j=0;j<=sum;j++)
		dp[0][j]=false;
	for(int i=0;i<=n;i++)
		dp[i][0]=true;

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=sum;j++)
		{
			if(arr[i-1]<=j)
			{
				dp[i][j] = dp[i-1][j-arr[i-1]] or dp[i-1][j];
			}
			else
				dp[i][j] = dp[i-1][j];
		}
	}

	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=sum;j++)
		{
			cout << dp[i][j] <<" ";
		}
		cout << endl;
	}
	int ans=INT_MAX;
	for(int j=sum/2;j>=0;j--)
	{
		if(dp[n][j])
		{
			ans = min(ans, sum-(2*j));
		}
	}
	return ans;
}

int main()
{
	int arr[]={1,8};
	int sum=0;
	int n= sizeof(arr)/sizeof(int);
	for(int i=0;i<n;i++)
		sum+=arr[i];
	cout << minimumSubsetSum(arr,sum,n);

	return 0;
}