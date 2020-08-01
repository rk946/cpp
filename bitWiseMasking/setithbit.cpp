#include<iostream>
using namespace std;

int main()
{
	
	int n=4;
	int bit = 3;
	int ans = (n | (1<<bit));
	cout << ans;
		return 0;
}