#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

bool isvalidParenthesis(string ip)
{
	stack<char> s;
	for(char c:ip)
	{
		if(c=='(')
			s.push(c);
		else if(c=='{')
			s.push(c);
		else if(c=='[')
			s.push(c);
		else if(c==')')
		{
			if(s.top()=='(')
				s.pop();
			else
			{
					// cout <<"Not a valid parenthesis"<<endl;
				return false;
			}
		}

		else if(c=='}')
		{
			if(s.top()=='{')
				s.pop();
			else
			{
				// cout <<"Not a valid parenthesis"<<endl;
				return false;
			}
		}

		else if(c==']')
		{
			if(s.top()=='[')
				s.pop();
			else
			{
				// cout <<"Not a valid parenthesis"<<endl;
				return false;
			}
		}

	}
	return true;
}

int main()
{
	
	string ip;
	getline(cin,ip);
	if(isvalidParenthesis(ip))	
		cout << "valid parenthesis"<<endl;
	else
		cout << "Not a valid parenthesis"<<endl;
	return 0;

}