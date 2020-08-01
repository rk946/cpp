#include<iostream>

using namespace std;

int * product(int *a)
{
	int n= sizeof(a)/sizeof(int);

	int b[n],c[n];
	int *d = new int[n];
	b[0]=1;
	c[n-1]=1;
	for(int i=1;i<n;i++)
	{
		b[i]=b[i-1]*a[i-1];

	}

	for(int i=n-2;i>0;i--)
	{
		c[i]=c[i+1]*a[i+1];

	}

	for(int i=0;i<n;i++)
	{
		d[i]=b[i]*c[i];
	}
	return d;
}

int main()
{

int n=0;
cin>>n;
int a[n];
for(int i=0;i<n;i++)
{
	a[i]=(i+1);
}
int *b = a;

int d[n];
d = product(b);

for(int i=0;i<n;i++)
cout << d[i] << ",";

return 0;
}