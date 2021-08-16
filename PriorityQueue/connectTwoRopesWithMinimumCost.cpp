#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int minCost(int *a, int n)
{
	int cost=0;
	priority_queue<int,vector<int>,greater<int>> pq;
	// cout << a[0];
	for(int i=0;i<n;i++)
		pq.push(a[i]);
	// cout << "queue is filled";
	while(pq.size()>1)
	{
		int first = pq.top();
		pq.pop();
		int second = pq.top();
		pq.pop();
		cout << first <<" , "<<second<<"\n";
		cost+=(first+second);
		pq.push(first+second);
	}
	return cost;
}

int main(){

	int n;
	cin>>n;
	cout << "Enter lengths\n";
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];

	}
	// cout << "calling function\n";
	cout << minCost(a,n);
	
	return 0;
}