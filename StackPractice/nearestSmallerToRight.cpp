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

vector<int> nearestSmallerToLeft(int *arr, int n)
{
	stack<int> s;
	vector<int> v;
	for(int i=0;i<n;i++)
	{
		if(s.size()==0)
			v.push_back(-1);
		else
		{
			while(s.size()>0 and s.top()>=arr[i])
				s.pop();
			if(s.size()==0)
				v.push_back(-1);
			else if(s.top()<arr[i])
			{
				v.push_back(s.top());
			}
		}
		s.push(arr[i]);
	}
	return v;

}

vector<int> nearestSmallerToRight(int *arr, int n)
{
	stack<int> s;
	vector<int> v;
	for(int i=n-1;i>=0;i--)
	{
		if(s.size()==0)
			v.push_back(-1);
		else
		{
			while(s.size()>0 and s.top()>=arr[i])
				s.pop();
			if(s.size()==0)
				v.push_back(-1);
			else if(s.top()<arr[i])
				v.push_back(s.top());
		}
		s.push(arr[i]);
	}
	reverse(v.begin(),v.end());
	return v;
}

int main()
{
	int arr[]={1,3,0,0,1,2,4};
	int n = sizeof(arr)/sizeof(int);
	vector<int> ans = nearestSmallerToRight(arr,n);
	for(int v:ans)
		cout << v <<" ";
	cout << endl;
	return 0;

}