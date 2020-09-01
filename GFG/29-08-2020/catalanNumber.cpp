#include<iostream>

using namespace std;
//Catalan numbers are the number which follow pattern as C(N+1) = sum from i to N Ci*C(N-i) or it can also be said as binomial coefficient
// Use case are: 
// 1) Count the number of expressions containing n pairs of paranthesis which are matched
// 2) Number of possible BSTs from n keys
// 3) Number of complete binary trees from n+1 keys
// 4) number of chords without intersection in n+2 polygon

int getCatalan(int n)
{
	if(n<=1)
		return 1;
	int res=0;
	for(int i=0;i<n;i++)
	{
		res+=getCatalan(i)*getCatalan(n-i-1);
	}
	return res;
}
int getCatalanUsingDP(int n)
{
	int dp[n+1]={0};
	// int res = 0;
	dp[0]=1;
	dp[1]=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<i;j++)
		{
			dp[i]+=(dp[j]*dp[i-j-1]);
		}	
	}
	return dp[n];
}
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
int getCatalanUsingBinomialCoefficient(int n)
{	

	return binomialCoefficient(2*n,n)/(n+1);
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<=n;i++)
	{
		cout << getCatalan(i)<<",";
		
		cout << getCatalanUsingDP(i)<<",";
		
		cout << getCatalanUsingBinomialCoefficient(i)<<",";
		cout << endl;
	}

	cout << getCatalanUsingDP(2);
	
}