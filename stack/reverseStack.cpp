#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void reverseStack1(stack<int> &s)
{
	stack<int> s2,s3;
	int n=s.size();
	for(int i=0;i<n;i++)
	{
		s2.push(s.top());
		s.pop();
	}
for(int i=0;i<n;i++)
	{
			s3.push(s2.top());
		s2.pop();
	}
for(int i=0;i<n;i++)
	{
			s.push(s3.top());
		s3.pop();
	}
}

void transfer(stack<int> &s1,stack<int> &s2, int n)
{
	for(int i=0;i<n;i++)
	{
		s2.push(s1.top());
		s1.pop();
	}
}
void reverseStack2(stack<int>&s)
{
	int n=s.size();
	stack<int> s2;
	for(int i=0;i<n;i++)
	{
		int a = s.top();
		s.pop();
		transfer(s,s2,n-i-1);
		cout << "size = "<<s.size()<<"  "<<a<<endl;
		s.push(a);
		transfer(s2,s,n-i-1);
	}
}

int main()
{
 	stack<int> s;
 	s.push(1);
 	s.push(2);
 	s.push(3);
 	s.push(4);

 	// reverseStack1(s);
 	reverseStack2(s);
 	// reverseStack3();

	int n = s.size();
 	for(int i=0;i<n;i++)
 	{
 		cout << s.top() << " ";
 		s.pop();
 	}
 	cout <<endl;
	return 0;
}