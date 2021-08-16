#include<bits/stdc++.h>
using namespace std;


int len(string s, int k)
{
	int n = s.length();
	unordered_map<char,int> m;
	int i=0,j=0;
	int lengthSub=0;
	while(j<n)
	{
		m[s[j]]++;
		if(m.size()==k)
		{
			lengthSub = max(lengthSub,j-i+1);
		}
		else if(m.size()>k)
		{
			m[s[i]]--;
			if(m[s[i]]==0)
				m.erase(s[i]);
			i++;
		}
		j++;
	}
	return lengthSub;
}
int main()
{
	string s = "aabacbebebe";
	int k=3;
	cout << len(s,k);
	return 0;
}

