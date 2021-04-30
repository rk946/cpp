#include<bits/stdc++.h>

using namespace std;

int dp[10][10];
int solve(int arr[], int i, int j)
{
	int ans = INT_MAX;
	if(i>=j)
		return dp[i][j]=0;
	if(dp[i][j]!=-1)
		return dp[i][j];
	for(int k=i;k<j;k++)
	{
		int temp = (arr[i-1]*arr[k]*arr[j]) +  solve(arr,i,k)+solve(arr,k+1,j);
		if(temp<ans)
			ans=temp;
	}
	return dp[i][j] = ans;

}

int main()
{
	int arr[]={1, 2, 3, 4};
	int n = sizeof(arr)/sizeof(int);
	memset(dp,-1,sizeof(dp));
	cout << solve(arr, 1,n-1)<<endl;
	cout << "DP:"<<endl;
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			cout << dp[i][j]<<" ";
		}
		cout << endl;
	}
	return 0;
}