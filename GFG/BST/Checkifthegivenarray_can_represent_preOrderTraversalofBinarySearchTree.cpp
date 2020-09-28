#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool ifPossible(int *arr, int min, int max, int &i, int n)
{
	if(i>=n)
		return true;
	int element = arr[i++];
	if(element<min || element > max)
		return false;
	else if(element>min and element<max)
		return ifPossible(arr,min,element,i,n);
	else if
		return ifPossible(arr,element,max,i,n);
	return true;


}


int main()
{
 	int arr[]={2,4,3};
 	int i=0;
 	int n= sizeof(arr)/sizeof(int);
 	cout << ifPossible(arr,INT_MIN,INT_MAX,i,n);

	return 0;
}