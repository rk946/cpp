#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


    string countAndSay(int n) {
        if(n==1)
            return "1";
        string s = countAndSay(n-1);
        string output = "";
        int len = s.length();
        int count = 1;
        int i=0;
        for(;i<len-1;i++)
        {
            if(s[i]!=s[i+1])
            {
                output+=to_string(count);
                output+=to_string(s[i]-'0');
                count=1;
            }
            else
                count++;
        }
            output+=to_string(count);
                output+=to_string(s[i]-'0');
            return output;
    }
int main()
{
	int n;
	cin >> n;
	cout << countAndSay(n)<<endl;
	return 0;

}