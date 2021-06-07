#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

void putAtBottom(stack<int> &s, int e, int n)
{
	if(n==0)
	{
		s.push(e);
		return;
	}
	int inhandelement = s.top();
	s.pop();
	putAtBottom(s,e,n-1);
	s.push(inhandelement);
}
void reverseStack(stack<int> &s)
{
		int n = s.size();
		while(n>0)
		{
			int inhandelement = s.top();
			s.pop();
			putAtBottom(s,inhandelement, n-1);
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