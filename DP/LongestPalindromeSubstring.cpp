#include<bits/stdc++.h>

using namespace std;

string longestPalindrome(string s) {
	int n = s.length();
	int maxLength=1;
	int dp[n][n];
	//Initialization
	for(int i=0;i<n;i++)
		dp[i][i]=1;
	for(int i=0;i<n;i++)
	{
		if(s[i]==s[i+1])
		{
			dp[i][i+1]=1;
			maxLength=max(maxLength,2);
		}
		else
			dp[i][i+1]=0;
	}
	int j=2;
	for(int i=0;i<n;i++)
	{
		if(s[i]==s[n-i-1] and dp[i+1][i+j-1]==1)
		{
			dp[i][i+j]=1;
			maxLength=max(maxLength,);
		}
		else
			dp[i][i+j]=0;
	}


}

int main()
{
	string s = "aaaabba";
	return 0;
}