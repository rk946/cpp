#include<iostream>
#include<climits>
using namespace std;

int solTDhelper(int n, int *dp)
{
	if(n==0 or n==1)
		return 0;
	if(dp[n]==0)
		{
			int a = INT_MAX;
			int b = INT_MAX;
			int c = INT_MAX;
			if(n%2 == 0)
				a = solTDhelper(n/2,dp);
			if(n%3 == 0)
				b = solTDhelper(n/3,dp);
			c = solTDhelper(n-1,dp);
			return min(a,min(b,c))+1;
	}
	else
		return dp[n];
}
int solTD(int n)
{
	int dp[n+1]={0};
	return solTDhelper(n,dp);

}


int solUP(int n)
{
	int dp[n+1] = {0};
	if(n==0 or n==1)
		return 0;
	dp[0]=0;
	dp[1]=0;
	
	for(int i=2;i<=n;i++)
	{
		int a=INT_MAX;
	int b=INT_MAX;
	int c=INT_MAX;
		if(i%2==0)
			a=dp[i/2];
		if(i%3==0)
			b=dp[i/3];
		c=dp[i-1];
		dp[i] = 1+min(a,min(b,c));
	}
	return dp[n];
}


int main()
{
	int n;
	cin>>n;

	cout << solTD(n)<<endl;
	cout << solUP(n)<<endl;

	return 0;
}