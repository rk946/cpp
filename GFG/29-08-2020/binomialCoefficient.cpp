#include<iostream>

using namespace std;

int binomialCoefficient(int n, int k)
{	
	if(k>n-k)
		k=n-k;
	int res=1;
	for(int i=1;i<=k;i++)
	{	
		res*=(n-i+1);
		res/=i;
	}
	return res;

}
int recurssion(int n, int k)
{
	if(k==n || k==0)
		return 1;
	return recurssion(n-1,k-1)+recurssion(n-1,k);
}
int dp(int n, int k)
{
	int dp[n+1][k+1]={0};
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		dp[i][0]=1;
		for(int j=1;j<=min(k,n-k);j++)
		{
			dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
			dp[j][i] = dp[i][j];
		}
	}
	return dp[n][k];

}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<=n;i++)
	{
		cout << binomialCoefficient(n,i)<<",";
		cout << recurssion(n,i)<<",";
		cout << dp(n,i)<<endl;
	}


	return 0;
}