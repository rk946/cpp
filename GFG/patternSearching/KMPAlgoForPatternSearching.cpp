#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
//Given a text txt[0..n-1] and a pattern pat[0..m-1], write a function search(char pat[], char txt[]) that prints all occurrences of pat[] in txt[]. You may assume that n > m.
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