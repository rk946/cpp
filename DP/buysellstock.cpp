#include<bits/stdc++.h>

using namespace std;
int dp[6][16];
int maxSum(int buy[], int sell[], int sum, int n)
{
	if(sum==0 || n==0)
		return 0;
	if(dp[n][sum]!=-1)
		return dp[n][sum];
	if(buy[n-1]<=sum)
		return dp[n][sum] = max(((sell[n-1]-buy[n-1])+maxSum(buy,sell,sum-buy[n-1],n-1)) , maxSum(buy,sell,sum,n-1));
	return dp[n][sum] = maxSum(buy,sell,sum,n-1);
}


int main()
{

	int buy[]={3,5,4,3,7};
	int sell[]={10,10,10,10,10};
	int sum=15;
	int n = sizeof(buy)/sizeof(int);
	
	memset(dp,-1,sizeof(dp));
	cout << maxSum(buy,sell,sum,n) << endl;
	return 0;
}