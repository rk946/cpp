#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

int rainWater(int *arr, int n)
{
	vector<int> maxL(n,0);
	vector<int> maxR(n,0);
	maxL[0] = arr[0];
	for(int i=1;i<n;i++)
		maxL[i]=(max(maxL[i-1],arr[i]));

	maxR[n-1] = (arr[n-1]);
	for(int i=n-2;i>=0;i--)
		maxR[i] = max(maxR[i+1], arr[i]);
	// reverse(maxR.begin(),maxR.end());
	vector<int> height;
	int water=0;
	for(int i=0;i<n;i++)
	{

		int h= min(maxL[i],maxR[i]);
		// cout << maxL[i] <<" "<<maxR[i]<<" "<<h<<endl;
		water+=  (h- arr[i]);
	}
	return water;
}

int main()
{
	int arr[]={0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	int n = sizeof(arr)/sizeof(int);
	cout << rainWater(arr,n);
	return 0;

}