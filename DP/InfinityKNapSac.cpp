#include<bits/stdc++.h>

using namespace std;

int maxSum(int weights[], int prices[], int W, int n)
{
	if(W==0 || n==0)
		return 0;
	if(weights[n-1]<=W)
		return max((prices[n-1]+maxSum(weights,prices,W-weights[n-1],n)) , maxSum(weights, prices,W,n-1));
	return maxSum(weights,prices,W,n-1);
}


int main()
{
	int weights[]={2,7,3,4};
	int prices[]={5,20,20,10};
	int W=11;
	int n = sizeof(weights)/sizeof(int);
	cout << maxSum(weights,prices,W,n) << endl;
	return 0;
}