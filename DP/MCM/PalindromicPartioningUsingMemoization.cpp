#include<bits/stdc++.h>

using namespace std;
int dp[11][11];
bool isPalindrome(string s, int i, int j)
{
	if(i>=j)
		return true;
	while(i<j)
	{
		if(s[i]!=s[j])
			return false;
		i++;
		j--;
	}
	return true;
}

int solve(string s, int i, int j)
{
	if(i>=j)
		return dp[i][j]=0;
	if(isPalindrome(s,i,j))
		return 0;
	if(dp[i][j]!=-1)
		return dp[i][j];
	int ans = INT_MAX;
	for(int k=i;k<j;k++)
	{
		int temp = 1+solve(s,i,k)+solve(s,k+1,j);
		ans = min(ans, temp);
	}



	return dp[i][j]=ans;
}

int main()
{
	string s="nitik";
	int n = s.length();
	memset(dp,-1,sizeof(dp));
	cout << solve(s, 0,n-1)<<endl;
	cout << "DP"<<endl;
	for(int i=0;i<11;i++)
	{
		for(int j=0;j<11;j++)
		{
			cout << dp[i][j]<<" ";
		}
		cout << endl;
	}

	return 0;
}