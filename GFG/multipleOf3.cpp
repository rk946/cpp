#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool ismultipleOfThree(int n)
{
	int i = n;
	int odd=0,even=0;
	if(n<0)
		{n = -n;}
	if(n==0)
		return true;
	if(n==1)
		return false;
	while(i)
	{
		if(i&1)
			odd++;
		if(i&2)
			even++;
		i=i>>2;
	}
	return ismultipleOfThree(odd - even);

	
}
int main()
{
	int n;
	cin >> n;

	cout << ismultipleOfThree(n);
	

	return 0;

}