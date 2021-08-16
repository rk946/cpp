#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int KnapSack(int wt[], int val[], int W, int n)
{
	int dp[5][12];
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<W+1;j++)
		{
			if(i==0 || j==0)
			dp[i][j]=0;
		}
	}
	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<W+1;j++)
		{
			
			if(wt[i-1]<=j)
				dp[i][j] = max((val[i-1]+dp[i-1][j-wt[i-1]]),dp[i-1][j]);
			else 
				dp[i][j] = dp[i-1][j];
		}
	}

	return dp[n][W];

	
}

int main()
{
	int wt[] = {1,4,5,7};
	int val[]={10,3,5,8};
	int W=11;
	int n = sizeof(wt)/sizeof(int);
	cout << KnapSack(wt,val,W,n);
	return 0;
}