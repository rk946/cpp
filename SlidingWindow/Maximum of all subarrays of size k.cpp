#include<bits/stdc++.h>
using namespace std;

vector<int> maxOfallsubarrays(int *arr, int n, int k)
{
	list<int> l;
	vector<int> v;
	int i=0,j=0;
	while(j<n)
	{
		while(l.size()>0 and l.back()<arr[j])
			l.pop_back();
		l.push_back(arr[j]);
		if(j-i+1==k)
		{
			v.push_back(l.front());
			if(l.front()==arr[i])
				l.pop_front();
			i++;
		}
		j++;
	}
	return v;
}


int main()
{
	int arr[]={1,3,-1,-1,5,3,6,7};
	int n = sizeof(arr)/sizeof(int);
	int k=3;
	vector<int> ans = maxOfallsubarrays(arr,n,k);
	for(int i:ans)
		cout << i <<" ";
	return 0;
}

