#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

void search(string text, string pattern)
{
	int n=text.length();
	int m = pattern.length();
	for(int i=0;i<n;i++)
	{
		int j=0;
		for(;j<m;j++)
		{
			if(text[i+j]!=pattern[j])
				break;
		}
		if(j==m)
		{
			cout << "pattern found at index = "<<i<<endl;
			break;
		}
	}
}


int main()
{
	string text;
	getline(cin,text);
	string pattern;
	getline(cin,pattern);
	search(text,pattern);	

	return 0;

}