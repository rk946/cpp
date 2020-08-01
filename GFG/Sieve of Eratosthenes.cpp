#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void printAllPrime(int n)
{
	bool prime[n+1];
	for(int i=0;i<=n+1;i++)
		prime[i]=true;
	for(int i=2;i<=n;i++)
	{
		// cout << "i"<<i;
		if(prime[i])
		{
			// cout <<"true";
			for(int j=i*i;j<=n;j+=i)
				{
					prime[j]=false;
				}
		}

	}
	for(int i=2;i<=n;i++)
	{
		if(prime[i])
			cout << i <<",";
	}
	cout <<endl;
}
int main()
{
	int n;
	cin>>n;
	printAllPrime(n);

	return 0;

}