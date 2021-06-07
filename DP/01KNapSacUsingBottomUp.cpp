#include<bits/stdc++.h>

using namespace std;

int maxSum(int weights[], int prices[], int W, int n)
{
	int dp[n+1][W+1];

	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=W;j++)
		{
			if(i==0 || j==0)
				dp[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=W;j++)
		{
			if(i==0 || j==0)
				dp[i][j]=0;
			if(weights[i-1]<=j)
			{
				dp[i][j] = max(prices[i-1]+dp[i-1][j-weights[i-1]], dp[i-1][j]);
			}
			else
				dp[i][j] = dp[i-1][j];
			cout << dp[i][j] <<" ";
		}
		cout << endl;
	}
	return dp[n][W];
}


int main()
{

	int weights[]={2,7,3,4};
	int prices[]={5,20,20,10};
	int W=11;
	int n = sizeof(weights)/sizeof(int);
	
	// memset(dp,-1,sizeof(dp));
	cout << maxSum(weights,prices,W,n) << endl;
	return 0;
}