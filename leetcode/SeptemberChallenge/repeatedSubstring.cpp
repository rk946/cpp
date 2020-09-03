#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool check(string str, int s, int e, int k)
{
	int n=str.length();
	if(s>=n or e>=n or e+k>n)
		return false;
	for(int i=0;i<k;i++)
	{
		if(str[s+i]!=str[e+i])
			return false;
	}
	if(e+k == n)
		return true;
	return check(str,s+k,e+k,k);
}

bool repeatedSubstringPattern(string s) {
        int n=s.length();
        if(n<=0)
            return true;
        for(int j=1;j<n;j++)
        {
        	if(s[0]==s[j])
        	{
        		int k = j-0;
        		if(check(s,0,j,k))
        			return true;

        	}
        }
        return false;
    }

int main()
{
	cout << repeatedSubstringPattern("aaa");
	return 0;
}