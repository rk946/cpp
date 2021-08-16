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

int MAH(vector<int>& arr, int n)
{
	stack<int> s1,s2;
	vector<int> v1,v2;
	for(int i=0;i<n;i++)
	{
		if(s1.size()==0)
			v1.push_back(-1);
		else
		{
			while(s1.size()>0 and arr[s1.top()]>=arr[i])
				s1.pop();
			if(s1.size()==0)
				v1.push_back(-1);
			else if(arr[s1.top()]<arr[i])
			{
				v1.push_back(s1.top());
			}
		}
		s1.push(i);
	}

	for(int i=n-1;i>=0;i--)
	{
		if(s2.size()==0)
			v2.push_back(n);
		else
		{
			while(s2.size()>0 and arr[s2.top()]>=arr[i])
				s2.pop();
			if(s2.size()==0)
				v2.push_back(n);
			else if(arr[s2.top()]<arr[i])
			{
				v2.push_back(s2.top());
			}
		}
		s2.push(i);
	}
	reverse(v2.begin(),v2.end());
	vector<int> width;
	for(int i=0;i<n;i++)
	{
		// cout << v2[i] << " "<<v1[i]<<endl;
		width.push_back(v2[i]-v1[i]-1);
	}
	int maxarea=0;
	for(int i=0;i<n;i++)
	{
		maxarea = max(maxarea, width[i]*arr[i]);
	}
	return maxarea;
}

int main()
{
	vector<vector<int>> arr={{0,1,1,0},{1,1,1,1},{1,1,1,1},{1,1,0,0}};
	int m = arr.size();
	int n = arr[0].size();

	vector<int> v;
	for(int j=0;j<n;j++)
		v.push_back(arr[0][j]);
	int maxArea = MAH(v,v.size());
	for(int i=1;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(arr[i][j]==0)
				v[j]=0;
			else
			{
				v[j] = v[j]+arr[i][j];
			}
		}
		maxArea = max(maxArea,MAH(v,n));
	}
	cout << maxArea;
	return 0;

}