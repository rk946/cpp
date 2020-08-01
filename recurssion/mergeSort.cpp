#include<iostream>

using namespace std;

void merge(int *a,int s, int e)
{
	int mid=(s+e)/2;
	int temp [100];
	int i=s,j=mid+1,k=s;
	while(i<=mid and j<=e)
	{
		if(a[i]<a[j])
			{temp[k++]=a[i++];}
		else
			temp[k++]=a[j++];
	}

	while(i<=mid)
		temp[k++]=a[i++];

	while(j<=e)
		temp[k++]=a[j++];

	for(int l=s;l<=e;l++)
		a[l]=temp[l];

}


void mergeSort(int *a, int s, int e)
{
	if(s>=e)
		return;

	//1. Divide
	int mid = (s+e)/2;
	mergeSort(a,s,mid);
	mergeSort(a,mid+1,e);
	//2. sort divided array

	//3. merge
	merge(a,s,e);
}


int main()
{
	/////cin>>n;
	int a[]= {1,5,3,9,2,6,4};
	int n = sizeof(a)/sizeof(int);
	mergeSort(a,0,n-1);
	for(int i=0;i<n;i++)
		cout << a[i];
	return 0;
}