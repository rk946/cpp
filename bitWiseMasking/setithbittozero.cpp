#include<iostream>
using namespace std;

int main()
{
	
	int n=14;
	int bit = 3;

	int mask = 1<<bit;
	mask = ~mask;

	int ans = n&mask;
	cout << ans;
		return 0;
}