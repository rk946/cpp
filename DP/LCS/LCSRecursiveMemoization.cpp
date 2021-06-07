#include<bits/stdc++.h>
using namespace std;

int dp[1000][1000];

int LCS(string X, string Y, int n, int m)
{
	if(dp[m][n]!=-1)
		return dp[m][n];
	if(X[n-1]==Y[m-1])
		return dp[m][n] = 1+LCS(X,Y,n-1,m-1);
	else
		return dp[m][n] = max(LCS(X,Y,n-1,m), LCS(X,Y,n,m-1));
}
int main()
{
	string X="abcdgh";
	string Y="abedfhr";
	memset(dp,-1,sizeof(dp));
	dp[0][0]=0;
	cout << LCS(X,Y,X.length(),Y.length());
	return 0;
}