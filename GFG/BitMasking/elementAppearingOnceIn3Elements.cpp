#include<iostream>
#include<bits/stdc++.h>
using namespace std;




int main()
{
	int arr[]={12,12,12,4,3,3,3,1,1,1};
	int n = sizeof(arr)/sizeof(int);
	// cout << n<<endl;
	int res = 0;
	for(int i=0;i<32;i++)
	{
		int a = 1<<i;
		for(int j=0;j<n;j++)
		{
			res += arr[j]&a;
		}
		res%=3;
	}
 
	cout << res;
	return 0;
}