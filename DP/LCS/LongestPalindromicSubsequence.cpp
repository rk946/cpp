#include<bits/stdc++.h>
using namespace std;


int LCS(string X, string Y, int m, int n)
{
	int dp[m+1][n+1];
	for(int j=0;j<=n;j++)
		dp[0][j]=0;
	for(int i=0;i<=m;i++)
		dp[i][0]=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(X[i-1]==Y[j-1])
			{
				dp[i][j] = 1+dp[i-1][j-1];
			}
			else
			{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}

		}
	}

	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			cout << dp[i][j] <<" ";
		}
		cout<< endl;
	}
	
	return dp[m][n];
}
int main()
{
	string X="agbcba";
	string Y=X;
	reverse(Y.begin(), Y.end());
	cout << LCS(X,Y,X.length(),Y.length());
	return 0;
}