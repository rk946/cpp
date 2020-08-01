#include<iostream>
#include<stack>
#include<algorithm>
#include<cstring>
using namespace std;

void printSpan(int arr[], int n)
{
	
	stack<pair<int,int>> s;
	s.push(pair<int,int>(0,arr[0]));
	cout << 0 << " ";
	for(int i=1;i<n;i++)
	{
		// pair<int,int> p;
		// p=s.top();
		while(s.top().second<arr[i])
		{
			s.pop();
			// p=s.top();
		}
		cout << i - s.top().first << " " ;
		s.push(pair<int,int>(i,arr[i]));
		
	}	
}
int main()
{
	int n=7;
	int arr[]= {100,80,60,70,60,75,85};
	printSpan(arr,n);
	return 0;

}