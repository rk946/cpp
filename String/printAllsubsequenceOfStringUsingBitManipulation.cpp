#include<bits/stdc++.h>
using namespace std;

string getsubsequence(string s, int j)
{
	string ans = "";
	int n = s.length();
	for(int i=0;i<n;i++)
	{
		if(j&(1<<i))
			ans+=s[i];
	}
	return ans;
}

void printall(string s)
{
	int n =s.length();
	for(int i=0;i<pow(2,n);i++)
	{
		cout << getsubsequence(s,i)<<" ";

	}
}

void printallUsingRecurssion(string s, string output)
{
	if(s.length()==0)
	{
		reverse(output.begin(),output.end());
		cout << output<<" ";
		return;
	}
	printallUsingRecurssion(s.substr(0,s.length()-1),output);
	output+=s[s.length()-1];
	printallUsingRecurssion(s.substr(0,s.length()-1),output);
}

int main()
{
	string s;
	getline(cin,s);
	printall(s);
	cout <<endl<<"print using recurssion "<<endl;
	string output="";
	printallUsingRecurssion(s,output);
	return 0;
}