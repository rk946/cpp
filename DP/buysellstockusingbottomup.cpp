#include<bits/stdc++.h>

using namespace std;

int maxSum(int buy[], int sell[], int sum, int n)
{
	int dp[n+1][sum+1];

	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=sum;j++)
		{
			if(i==0 || j==0)
				dp[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=sum;j++)
		{
			if(i==0 || j==0)
				dp[i][j]=0;
			if(buy[i-1]<=j)
			{
				dp[i][j] = max((sell[i-1]-buy[i-1])+dp[i-1][j-buy[i-1]], dp[i-1][j]);
			}
			else
				dp[i][j] = dp[i-1][j];
			cout << dp[i][j] <<" ";
		}
		cout << endl;
	}
	return dp[n][sum];
}


int main()
{

	int buy[]={3,5,4,3,7};
	int sell[]={10,10,10,10,10};
	int sum=15;
	int n = sizeof(buy)/sizeof(int);
	
	// memset(dp,-1,sizeof(dp));
	cout << maxSum(buy,sell,sum,n) << endl;
	return 0;
}