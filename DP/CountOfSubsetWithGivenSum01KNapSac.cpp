#include<bits/stdc++.h>

using namespace std;

int counting=0;

void findCountOfSubsets(int *arr, int sum, int n)
{
	if(sum==0)
	{
		counting++;
		return;
	}
	if(n==0)
		return;
	if(arr[n-1]<=sum)
		findCountOfSubsets(arr,sum-arr[n-1],n-1);
	findCountOfSubsets(arr,sum,n-1);
}

int main()
{
	int arr[]={2,3,5,6,8,10};
	int n = sizeof(arr)/sizeof(int);
	int sum = 8	;
	 findCountOfSubsets(arr,sum,n);
	 cout << "Count = "<<counting <<endl;
	return 0;
}