#include<bits/stdc++.h>

using namespace std;


int solve(int arr[], int i, int j)
{
	int ans = INT_MAX;
	if(i>=j)
		return 0;
	for(int k=i;k<j;k++)
	{
		int temp = (arr[i-1]*arr[k]*arr[j]) +  solve(arr,i,k)+solve(arr,k+1,j);
		if(temp<ans)
			ans=temp;
	}
	return ans;

}

int main()
{
	int arr[]={1, 2, 3, 4};
	int n = sizeof(arr)/sizeof(int);
	cout << solve(arr, 1,n-1);

	return 0;
}