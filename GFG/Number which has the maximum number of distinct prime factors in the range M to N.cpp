#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int AllPrime(int n)
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
	int res=0;
	for(int i=2;i<=n;i++)
	{
		if(prime[i])
			res++;
	}
	return res;
}
int main()
{
	int a,b;
	cout << "enter a and b"<<endl;
	cin>>a>>b;
	cout <<endl;
	int n,count=0;
	for(int i=a;i<=b;i++)
	{
		int x  = AllPrime(i);
		cout << i <<" " <<x<<endl;
		if(x>count)
			{
				count=x;
				n=i;
			}
	}
	cout << n <<" has max prime factors with " <<count <<" factors "<<endl;
	return 0;

}