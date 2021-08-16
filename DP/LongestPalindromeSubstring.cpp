#include<bits/stdc++.h>

using namespace std;



string longestPalindrome(string s) {
	int n = s.length();
	int maxLength=1;
	bool dp[n][n];
	int start = 0;
	//Initialization
	for(int i=0;i<n;i++)
		dp[i][i]=true;
	for(int i=0;i<n-1;i++)
	{
		if(s[i]==s[i+1])
		{
			dp[i][i+1]=true;
			maxLength=max(maxLength,2);
			start = i;
		}
		else
			dp[i][i+1]=false;
	}
	
	for(int k=3;k<=n;k++){
		for(int i=0;i<n-k+1;i++){
			int j = i+k-1;
			if(s[i]==s[j] and dp[i+1][j-1]){
				dp[i][j] = true;
				if(k>maxLength){
					start = i;
					maxLength=k;
				}
			}
			else
				dp[i][j]=false;
		}
	}

	return s.substr(start,maxLength);



}

int main()
{
	string s = "aacabba";
	cout << longestPalindrome(s);
	return 0;
}