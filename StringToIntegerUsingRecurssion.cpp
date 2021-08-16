#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;


int stoic(string s,int n, int no)
{
	if(s[n]=='\0')
		return -1;
	no*=10;
	int a = s[n]-'0';
	int b = stoic(s,n+1,no);
	if(b!=-1)
		no+=a;
	return a;
}
int main()
{
	string s;
	getline(cin,s);
	// cin>>s;
	// cout << "string = "<<s<;
	cout << stoic(s,0,0);

	return 0;

}