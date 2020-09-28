#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void printMissing(vector<int> arr, int low, int height)
{
	unordered_set<int> s;
	int n= arr.size();
	int count=0;
	for(int i=0;i<n;i++)
	{
		s.insert(arr[i]);
	}
	for(int i=low;i<=height;i++)
	{
		if(s.find(i)==s.end())
		{
			count++;
			cout << i <<" , ";
		}
	}
	cout << endl;
	cout << "Count = "<<count<<endl;
}

void printMissing2(vector<int> arr, int low, int height){
	int n=arr.size();
	int count=0;
	bool arr2[height-low+1];
	for(int i=0;i<n;i++)
	{
		arr2[arr[i]-low]=true;
	}
	n=height-low+1;
	for(int i=0;i<n;i++)
	{
		if(!arr2[i])
		{
			count++;
			cout << i+low <<" , ";
		}
	}
	cout<<endl;
	cout << count<<endl;

}

int main()
{
 	vector<int> arr = {10,11,15,12};
 	int low=10;
 	int height=15;
 	printMissing(arr,low,height);
 	printMissing2(arr,low,height);
	return 0;
}