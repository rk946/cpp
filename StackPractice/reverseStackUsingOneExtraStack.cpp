#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

void reverseStack(stack<int> &s)
{
		stack<int> s1;
		int n = s.size();
		while(n>0)
		{
			int inhand = s.top();
			s.pop();
			int i = n-1;
			while(i>0)
			{
				s1.push(s.top());
				s.pop();
				i--;
			}
			s.push(inhand);
			while(s1.empty()==false)
			{
				s.push(s1.top());
				s1.pop();
			}
			n--;
		}
}
int main()
{
	
	stack<int> s;
	for(int i=1;i<=5;i++)
		s.push(i);
	reverseStack(s);
	for(int i=1;i<=5;i++)
	{
		cout<<s.top()<<endl;
		s.pop();
	}
	return 0;

}