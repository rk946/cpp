#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s1 = "hello";
	string s2 = "elnl";
	int i = s1.length()-1;
	int j = s2.length()-1;

	while(i>=0 and j>=0)
	{
		if(s1[i]==s2[j])
		{
			i--;
			j--;
		}
		else
			i--;
	}
	if(j<0)
		cout << "subset present";
	else
		cout << "subset not present";
	return 0;
}