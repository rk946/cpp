#include<bits/stdc++.h>
using namespace std;

int main()
{
	int arr[]={-12,1,7,8,-15,30,16,28};
	int n = sizeof(arr)/sizeof(int);
	list<int> l;
	int i=0,j=0,k=3;
	vector<int> v;
	while(j<n)
	{
		if(arr[j]<0)
			l.push_back(arr[j]);
		if(j-i+1==k)
		{
			if(l.size()==0)
				v.push_back(0);
			else
				v.push_back(l.front());
			if(l.front()==arr[i])
				l.pop_front();
			i++;

		}
		j++;
	}
	cout<<endl;
	for(int a:v)
		cout << a<<" ";
	return 0;
}

