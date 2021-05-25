#include<bits/stdc++.h>
using namespace std;

vector<string> s;
void generateSubsets(string ip, string op, int index,int n)
{
	if(index==n)
	{
		cout << op<<endl;
		s.push_back(op);
		return;
	}
	generateSubsets(ip,op,index+1,n);
	op.push_back(ip[index]);
	generateSubsets(ip,op,index+1,n);
	// op.pop_back();
	
	

}
bool compare(string s1, string s2)
{
	if(s1.length()>s2.length())
		return false;
	else if(s1.length()==s2.length())
	{
		if(s1>s2)
			return false;
		else
			return true;
	}
	
		return true;
}
int main()
{
	string ip = "abc";
	string op = "";
	generateSubsets(ip,op,0,ip.length());
	for(auto it:s)
	{
		cout << it<<"   ";
	}
	sort(s.begin(),s.end(),compare);
	cout << endl;
	for(auto it:s)
	{
		cout << it<<"   ";
	}
	return 0;
}