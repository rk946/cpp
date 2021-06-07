#include<bits/stdc++.h>
using namespace std;

bool findTriplet(int *arr, int n)
{
	unordered_map<int,int> m;
	for (int i = 0; i < n; ++i)
	{
		/* code */
		m[arr[i]]++;
		
	}
}

int main(){
	int arr[] = {3, 1, 4, 6, 5};
	int n= sizeof(arr)/sizeof(int);
	if(findTriplet(arr,n))
		cout <<"triplet found";
	else
		cout << "triplet not found";
	return 0;
}