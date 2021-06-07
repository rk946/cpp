#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

vector<int> nearestGreater(int *arr, int n)
{
	stack<int> s;
	vector<int> v;
	for(int i=n-1;i>=0;i--)
	{
		if(s.size()==0)
			v.push_back(-1);
		else
		{
			while(s.size()>0 and arr[i]>s.top())
			{
				s.pop();
			}
			if(s.size()==0)
				v.push_back(-1);
			else if(s.top()>arr[i])
				v.push_back(s.top());
		}
		s.push(arr[i]);
	}
	reverse(v.begin(), v.end());
	return v;
}


vector<int> nearestGreaterLeft(int *arr, int n)
{
	stack<int> s;
	vector<int> v;
	for(int i=0;i<n;i++)
	{
		if(s.size()==0)
			v.push_back(-1);
		else
		{
			while(s.size()>0 and s.top()<=arr[i])
				s.pop();
			if(s.size()==0)
				v.push_back(-1);
			else if(s.top()>arr[i])
				v.push_back(s.top());

		}
		s.push(arr[i]);
	}
	// reverse(v.begin(),v.end());
	return v;
}

vector<int> stockspan(int *arr, int n)
{
	stack<int> s;
	vector<int> v;
	for(int i=0;i<n;i++)
	{
		if(s.size()==0)
			v.push_back(1);
		else
		{
			while(s.size()>0 and arr[s.top()]<=arr[i])
				s.pop();
			if(s.size()==0)
				v.push_back(1);
			else if(arr[s.top()]>arr[i])
				v.push_back(i-s.top());
		}
		s.push(i);
	}
	return v;
}

int main()
{
	int arr[]={100,80,60,70,60,75,85};
	int n = sizeof(arr)/sizeof(int);
	vector<int> ans = stockspan(arr,n);
	for(int v:ans)
		cout << v <<" ";
	cout << endl;
	return 0;

}