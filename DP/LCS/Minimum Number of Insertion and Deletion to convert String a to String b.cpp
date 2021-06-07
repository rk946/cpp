#include<bits/stdc++.h>
using namespace std;


int LCS(string X, string Y, int n, int m)
{
	int dp[n+1][m+1];
	for(int j=0;j<=m;j++)
		dp[0][j]=0;
	for(int i=0;i<=n;i++)
		dp[i][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
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

	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			cout << dp[i][j] <<" ";
		}
		cout<< endl;
	}
	
	return dp[n][m];
}
int main()
{
	string X="heap";
	string Y="pea";
	int lcs = LCS(X,Y,X.length(),Y.length());
	cout << "Minimum number of deletions = "<<X.length() - lcs<<endl;
	cout << "Minimum number of insertions = "<<Y.length() - lcs<<endl;
	// cout << LCS(X,Y,X.length(),Y.length());
	return 0;
}