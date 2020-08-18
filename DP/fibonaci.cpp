#include<iostream>

using namespace std;

int fib(int n,int dp[])
{
	if(n==0 or n==1)
		return n;
	if(dp[n]==0)
		dp[n]=fib(n-1,dp)+fib(n-2,dp);
	return dp[n];
}

int fibUP(int n)
{
	int dp[100]={0};
	dp[1]=1;
	for(int i=2;i<=n;i++)
		dp[i]=dp[i-1]+dp[i-2];
	return dp[n];
}

int fibSpaceOpt(int n)
{
	if(n==0 or n==1)
		return n;
	int a=0,b=1;
	int c=0;
	for(int i=2;i<=n;i++)
	{
		c=a+b;
		a=b;
		b=c;
	}
	return c;
}

int main()
{
	int n;
	cin>>n;
	int dp[100]={0};
	cout << fib(n,dp)<<endl;
	cout << fibUP(n)<<endl;
	cout << fibSpaceOpt(n)<<endl;
	return 0;
}