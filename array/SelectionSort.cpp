#include<iostream>
using namespace std;


void selectionSort(int arr[], int n)
{
	int temp;
	for(int i=0;i<n-1;i++)
	{
		int min_index=i;
		for(int j=i;j<n;j++)
		{
			if(arr[min_index]>arr[j])
			{
				min_index=j;
			}	
		}
		temp=arr[min_index];
		arr[min_index]=arr[i];
		arr[i]=temp;
	}
	cout << "Printing elements in sorted order";
	for(int i=0;i<n;i++)
	{
		cout << arr[i];
	}
}
int main()
{
	int n;
cout <<"Enter the number of elements in array";
cin >> n;
int a[n]={0};
for(int i=0;i<n;i++)
{
	cin>>a[i];
}

selectionSort(a,n);

return 0;
}