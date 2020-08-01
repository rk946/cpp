#include<iostream>
using namespace std;


void insertionSort(int arr[], int n)
{
	int temp=0;
	for(int i=1;i<n;i++)
	{
		temp=arr[i];
		int j=i-1;
/*		while(j>=0 and arr[j]>temp)	
		{
			arr[j+1]=arr[j];
			j--;
		}*/
		 for(;j>=0;j--)
		 {
		 	if(temp<arr[j])
		 		arr[j+1]=arr[j];
		 	else
		 	{
		 		break;
		 	}
		 }
		arr[j+1]=temp;		
		
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

insertionSort(a,n);

return 0;
}