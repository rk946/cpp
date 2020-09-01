#include<iostream>

using namespace std;

int waysBU(int n)
{
	if(n==0)
		return 0;
	int dp[100]={0};
	dp[1]=1;
	dp[2]=1+dp[1];
	dp[3]=1+dp[2]+dp[1];
	for(int i=4;i<=n;i++)
	{
		dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
	}
	return dp[n];
}

int ways2(int n)
{
	
}





 int waysTD(int n)
 {

 }
int main()
{
	int N;
	cin>>N;
	cout << waysBU(N)<<endl;
	cout << waysBUcustomized(N)<<endl;
	// cout << waysTD();

	return 0;
}