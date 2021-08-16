#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int mul(int a, int b)
{
	if(b==1)
		return a;
	if(b==-1)
		return 0-a;
	if(b==0)
		return 0;
	if(b>0)
		return a+mul(a,b-1);
	if(b<0)
		return (0-a)+mul(a,b+1);
}


int main()
{
	int a,b;
	cin>>a>>b;

	cout << mul(a,b);

	return 0;

}