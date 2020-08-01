#include<iostream>
#include<deque>
using namespace std;

int main()
{
	
	int a[100 ];
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	int k;
	cin>>k;
deque<int> q(k);
	for(int i=0;i<k;i++)
	{
		while(!q.empty() and a[i]>=a[q.back()] )
			q.pop_back();
		q.push_back(i);
	}
		
		for(int i=k;i<n;i++)
		{
			cout << a[q.back()];
			while(!q.empty() and i-q.front()>=k)
			{
				q.pop_back();
			}
			while(!q.empty() and a[i]>=a[q.back()])
				q.pop_back();
			q.push_back(i);
		}
	cout << q.back();

	return 0;
}
