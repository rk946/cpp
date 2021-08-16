#include<bits/stdc++.h>
using namespace std;

string SCS(string X, string Y, int m, int n)
{
	int dp[m+1][n+1];
	for(int i=0;i<=m;i++)
		dp[i][0]=0;
	for(int j=0;j<=n;j++)
		dp[0][j]=0;

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
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	string ans="";
	int i=m,j=n;
	while(i>0 and j>0)
	{
		if(X[i-1]==Y[j-1])
		{
			ans.push_back(X[i-1]);
			i--;
			j--;
		}
		else
		{
			// ans.push_back()
			if(dp[i-1][j] > dp[i][j-1])
			{
				ans.push_back(X[i-1]);
				i--;
			}
			else
			{
				ans.push_back(Y[j-1]);
				j--;
			}
		}
	}
	while(i>0)
	{
		ans.push_back(X[i-1]);
		i--;
	}
	while(j>0)
	{
		ans.push_back(Y[j-1]);
		j--;
	}

	reverse(ans.begin(), ans.end());
	return ans;

}

int main()
{
	string X="abcdaf";
	string Y="acbcf";
	cout << SCS(X,Y,X.length(),Y.length());
	return 0;
}