#include<iostream>
#include<climits>
using namespace std;

int minCoins(int n, int coins[], int dp[], int T)
{
	if(n==0)
		return 0;
	if(dp[n]!=0)
		return dp[n];
	int ans=INT_MAX;
	for(int i=0;i<T;i++)
	{
		if(n>=coins[i])
		{
			int subProblemAns = minCoins(n-coins[i],coins,dp,T);
			ans = min(ans,subProblemAns+1);
		}

	}

	dp[n]=ans;
	return dp[n];
}

int minCointBottomUp(int n, int coins[], int dp[], int T)
{
	if(n==0)
		return 0;
	for(int i=1;i<=n;i++)
	{
		int ans=INT_MAX;
		for(int j=0;j<T;j++)
		{
			if(i>=coins[j])
			{
				ans = min(ans,dp[i-coins[j]]+1);
			}
		}
		dp[i]=ans;
	}
	return dp[n];
}


int main()
{
	int N;
	cin >> N;
	int coins[] = {1,5,7};
	int dp[100]={0};
	int T = sizeof(coins)/sizeof(int);
	int count = minCoins(N,coins,dp,T);
	cout<<count<<endl;

	int dp1[100]={0};
	cout << minCointBottomUp(N,coins,dp1,T);
	return 0;
}