#include<bits/stdc++.h>

using namespace std;


int findCountOfSubsets(int *arr, int sum, int n)
{
	int dp[n+1][sum+1];
	//Initialization
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=sum;j++)
		{
			if(i==0)
				dp[i][j]=0;
			if(j==0)
				dp[i][j]=1;
		}
	}

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=sum;j++)
		{
			if(arr[i-1]<=sum)
				dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
			else
				dp[i][j] = dp[i-1][j];
			
		}
	}

	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=sum;j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}	


	return dp[n][sum];
}

int main()
{
	int arr[]={2,3,5,6,8,10};
	int n = sizeof(arr)/sizeof(int);
	int sum = 2;
	cout << findCountOfSubsets(arr,sum,n);
	 // cout << "Count = "<<counting <<endl;
	return 0;
}