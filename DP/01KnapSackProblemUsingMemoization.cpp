#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int dp[5][12];
int KnapSack(int wt[], int val[], int W, int n)
{
	if(n==0 || W==0)
		dp[n][W] = 0;
	if(dp[n][W]!=-1)
		return dp[n][W];
	if(wt[n-1]<=W)
		return dp[n][W] = max((val[n-1]+KnapSack(wt,val,W-wt[n-1],n-1)),KnapSack(wt,val,W,n-1));
	else
		return dp[n][W] = KnapSack(wt,val,W,n-1);
}

int main()
{
	memset(dp,-1,sizeof(dp));
	int wt[] = {1,4,5,7};
	int val[]={10,3,5,8};
	int W=11;
	int n = sizeof(wt)/sizeof(int);
	cout << KnapSack(wt,val,W,n);
	return 0;
}