#include<iostream>
using namespace std;

int main()
{
	
	int n=14;
	int bit = 3;
	int ans = (n & (1<<bit))==0?0:1;
	cout << ans;
		return 0;
}