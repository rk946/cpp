#include<bits/stdc++.h>
using namespace std;


int countAnagrams(string s, string t)
{
	vector<int> m(26,0);
	vector<int> m1(26,0);
	for(char c:t)
		m[c-97]++;

	int i=0,j=0,k=t.length();
	int n = s.length(),count=0;
	while(j<n)
	{
		m1[s[j]-97]++;
		if(j-i+1==k)
		{
			if(m==m1)
				count++;
			m1[s[i]-97]--;
			i++;
		}
		j++;


	}
	return count;

}

int main()
{
	string s = "aabaabaa";
	string t="aaba";
	cout << countAnagrams(s,t);

	return 0;
}

