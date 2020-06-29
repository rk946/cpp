#include<iostream>
using namespace std;

float sqrRoot(int n, int p)
{
	float ans = -1;
	int s=0,e=n;
	while(s<=e)
	{
		int mid = (s+e)>>1;
		if(mid*mid==n)
			return mid;
		else if(mid*mid<n)
		{
			ans=mid;
			s=mid+1;
		}
		else
			e=mid-1;
	}
	cout << "Int val = " << ans <<endl;
	float inc=0.1;
	for(int i=0;i<p;i++)
	{
		// ans=ans+inc;
		while(ans*ans<=n)
		{
			ans = ans+inc;
		}
		ans=ans-inc;
		inc = inc/10;

	}

	return ans;
}

int main()
{
	cout << "Enter the number whose square root is to be found" <<endl;
	int n=1;
	cin >> n;
	float ans = sqrRoot(n,3);
	cout << "sq root of "<<n << " = "<<ans<<endl;

	return 0;
}