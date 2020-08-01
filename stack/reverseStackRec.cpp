#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

void insertAtBottom(stack<int> &s,int x)
{
	if(s.empty())
	{
		s.push(x);
		return;
	}
	int y = s.top();
	s.pop();
	insertAtBottom(s,x); 
	s.push(y);
}
void reverse(stack<int>&s)
{
	if(s.empty())
		return;
	int x = s.top();
	s.pop();
	reverse(s);
	insertAtBottom(s,x);
}
int main()
{
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.push(6);
	reverse(s);
	int n=s.size();
	for(int i=0;i<n;i++)
	{
		cout << s.top() << endl;
		s.pop();
	}

	return 0;

}