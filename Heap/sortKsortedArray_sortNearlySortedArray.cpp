#include <bits/stdc++.h>  
      
using namespace std;  
      
void sortKsortedArray(int *arr, int n, int k)
{
	priority_queue<int,vector<int>,greater<int>> minh;
	int j=0;
	for(int i=0;i<n;i++)
	{
		minh.push(arr[i]);
		if(minh.size()>k)
		{
			arr[j] = minh.top();
			minh.pop();
			j++;
		}
	}
	// cout <<endl<<minh.size()<<endl;
	// for(int i=n-k;i<n;i++)
	// while(j<n)
	while(minh.size()>0)
	{
		// cout <<endl<<minh.size()<<endl;
		// cout << "call";
		arr[j] = minh.top();
		minh.pop();
		j++;
		
	}
}

int main()  
{  
	int arr[] = {6,5,3,2,8,10,9};
	int k=3;
	int n =sizeof(arr)/sizeof(int);
	for(int i=0;i<n;i++)
	{
		cout << arr[i] <<" ";
	}
	cout << endl;
	sortKsortedArray(arr,n,k);
	for(int i=0;i<n;i++)
	{
		cout << arr[i] <<" ";
	}

    return 0;
}  