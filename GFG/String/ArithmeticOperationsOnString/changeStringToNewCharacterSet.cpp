#include<iostream>
#include<bits/stdc++.h>
using namespace std;




int main()
{
 	string newCharSet = "qwertyuiopasdfghjklzxcvbnm";
 	char hash[26];
 	for(int i=0;i<26;i++)
 		hash[newCharSet[i]-'a']=i;

 	string input = "egrt";
 	string output="";
 	int n=input.length();
 	for(int i=0;i<n;i++)
 	{
 		output += hash[input[i]-'a']+'a';
 	}
 	cout << output<<endl;
	return 0;
}