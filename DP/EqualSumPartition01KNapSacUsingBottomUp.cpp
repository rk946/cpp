#include<bits/stdc++.h>

using namespace std;

bool check(int arr[], int sum, int n)
{
	bool dp[n+1][sum+1];

	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=sum;j++)
		{
			if(i==0)
				dp[i][j] = false;
			if(j==0)
				dp[i][j] = true;
		}
	}

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=sum;j++)
		{
			if(arr[i-1]<=j)
			{
				dp[i][j] = (dp[i-1][j-arr[i-1]])or(dp[i-1][j]);
			}
			else
				dp[i][j] = dp[i-1][j];
			// cout << dp[i][j] << " ";
		}
		// cout << endl;
	}


	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=sum;j++)
		{
			cout << dp[i][j] <<" ";
		}
		cout << endl;
	}
	return dp[n][sum];
}


int main()
{

	int arr[]={2,3,4,8,11};
	int n = sizeof(arr)/sizeof(int);
	// int sum=36;
	// memset(dp,-1,sizeof(dp));
	
	int sum=0;
	bool result;
	for(int i=0;i<n;i++)
		sum+=arr[i];
	if(sum%2!=0)
		cout << "Equal Partiotion not possible";
	else
	{
		result  = check(arr,sum/2,n);
		if(result)
			cout << "Equal Partiotion possible of sum = "<< sum/2;
		else
			cout << "Equal partition not possible";
	}



	return 0;
}