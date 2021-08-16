#include<bits/stdc++.h>
using namespace std;


string len(string s, int k)
{
	unordered_map<char,int> m;
	int n = s.length();
	int i=0,j=0;
	int lengthstr=0;
	int left=0,right=0;
	while(j<n)
	{
		m[s[j]]++;
		if(m[s[j]]>1)
		{
			if(lengthstr<j-i)
			{
				left =i;
				right=j;
				lengthstr = j-i;	
				cout << i << j <<lengthstr<<endl;
			}
			
			i=j;
			m.clear();
			m[s[i]]++;
		}
		j++;
	}
	cout << "length = "<<lengthstr<<endl;
	string ans;
	ans = s.substr(left,right-left+1);
	return ans;
}
int main()
{
	string s = "aabacbebebe";
	int k=3;
	cout << len(s,k);
	return 0;
}

