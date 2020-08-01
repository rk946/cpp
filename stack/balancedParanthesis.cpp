#include<iostream>
#include<stack>
#include<algorithm>
#include<cstring>
using namespace std;

bool isBalancedParanthesis(char a[])
{
	stack<char> s;
	int n = strlen(a);
	for(int i=0;i<n;i++)
	{
		if(a[i]=='(')
		{
			s.push(a[i]);
		}
		else if(a[i]==')')
		{
			if(s.empty() or s.top()!='(')
				return false;
			else
				s.pop();
		}
	}
	if(s.empty())
		return true;
	else
	return false;
}
int main()
{
	// char a[]="((a+b)-c*d+s)()()()()()";
	char a[]=")";
	cout << isBalancedParanthesis(a);
	return 0;

}