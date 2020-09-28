#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int countPair(vector<int> arr, int sum)
{
	int count=0;
	int n = arr.size();
	unordered_set<int> s;
	for(int i=0;i<n;i++)
	{
		int a = sum-arr[i];
		if(s.find(a)!=s.end())
			{
				count++;
				cout << a <<" , "<<arr[i]<<endl;
			}
		s.insert(arr[i]);
	}
	return count;

}


int main()
{
	vector<int> arr={1,5,7,2,-1,0,6};
	cout << countPair(arr,6); 

	return 0;
}