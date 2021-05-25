#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

template <typename T>

class stack1{
private:
	vector<T> v;
public:
	void push(T a)
	{
		v.push_back(a);
	}

	bool empty()
	{
		return v.size()==0;
	}
	void pop()
	{
		int n = v.size();
		if(n==0)
			return;
		T e = v[v.size()-1];
		v.pop_back();
		// return e;
	}
	T top(){
		int n = v.size();
		if(n==0)
			return -1;
		return v[v.size()-1];
	}
	int size(){
		return v.size();
	}
};
int main()
{
	stack1<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	while(s.empty()==false)
	{
		cout << "size = "<<s.size()<<endl;
	cout << s.top()<<endl;
	s.pop();
	
	}
	
	return 0;

}