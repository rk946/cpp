#include<iostream>
using namespace std;

int lower_bound(int a[], int n, int key)
{
	int s=0,e=n-1;
	int mid=0;
	int result =-1;
	while(s<=e)
	{
		mid =  (s+e)/2;
		if(key<a[mid])
		{
			e=mid-1;
		}
		else if(key>a[mid])
		{
			s=mid+1;
		}
		else if(key==a[mid])
		{	
			result=mid;
			e=mid-1;
		}
	}
	return result;
}

int upper_bound(int a[], int n, int key)
{
	int s=0,e=n-1;
	int mid=0;
	int result =-1;
	while(s<=e)
	{
		mid =  (s+e)/2;
		if(key<a[mid])
		{
			e=mid-1;
		}
		else if(key>a[mid])
		{
			s=mid+1;
		}
		else if(key==a[mid])
		{	
			result=mid;
			s=mid+1;
		}
	}
	return result;
}

int main()
{

int n=0;
cout << "Enter the number of elements of array";
cin >> n;

int a[n]={0};
for(int i=0;i<n;i++)
	cin>>a[i];
cout <<endl;
cout << "Array is "<<endl;
for (int i=0;i<n;i++)
cout<< a[i] << " ";
int key = 0;
cout <<endl << "Enter key to find "<<endl;
cin >> key;
int lower_index = lower_bound(a,n,key);
int upper_index = upper_bound(a,n,key);
cout << "Lower bound index = "<<lower_index<<endl;
cout << "Upper bound index = "<<upper_index<<endl;

	return 0;
}