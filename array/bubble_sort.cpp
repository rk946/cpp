#include<iostream>
using namespace std;

bool compare(int a,int b)
{
	return a>b;
}
void bubbleSort(int arr[], int n, bool (&cmp)(int a, int b))
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i;j++)
		{
			if(cmp(arr[j],arr[j+1]))
				swap(arr[j+1],arr[j]);
		}
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

bubbleSort(a,n,compare);

return 0;
}