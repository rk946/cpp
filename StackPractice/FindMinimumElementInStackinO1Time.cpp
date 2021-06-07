#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

class customStack{
private:
	stack<int> s;
	stack<int> helper;
public:
	void push(int a)
	{
		s.push(a);
		if(helper.size()==0)
			helper.push(a);
		else
			helper.push(min(helper.top(),a));
	}
	int top(){
		return s.top();
	}

	void pop(){
		s.pop();
		helper.pop();
	}
	int size(){
		return s.size();
	}
	bool empty()
	{
		return s.empty();
	}
	int getmin()
	{
		return helper.top();
	}
};

int main()
{
	int arr[] = {5,3,7,2,9,15,11};
	
	int n = sizeof(arr)/sizeof(int);
	customStack s;
	for(int i=0;i<n;i++)
	{
		s.push(arr[i]);
	
	}

	while(s.empty()==false)
	{
		cout << s.top() << " min = "<<s.getmin()<<endl;
		s.pop();
	}
	
	return 0;

}