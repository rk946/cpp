#include<iostream>

using namespace std;

int nthUglyNo(int n)
{
	int dp[n+1];
	dp[0]=1;
	int i2=0,i3=0,i5=0;
	int next_multiple2 = dp[i2]*2;
	int next_multiple3=dp[i3]*3;
	int next_multiple5=dp[i5]*5;
	for(int i=1;i<n;i++)
	{
		int a = min(min(next_multiple3,next_multiple5),next_multiple2);
		dp[i]=a;
		if(next_multiple2==a)
			{
				i2=i2+1;
				next_multiple2=dp[i2]*2;
			}
			if(next_multiple3==a)
			{
				i3=i3+1;
				next_multiple3=dp[i3]*3;
			}
			if(next_multiple5==a)
			{
				i5=i5+1;
				next_multiple5=dp[i5]*5;
			}
	}
	return dp[n-1];
}


int main(){
	int n;
	cin>>n;
	cout << nthUglyNo(n);
	return 0;
}