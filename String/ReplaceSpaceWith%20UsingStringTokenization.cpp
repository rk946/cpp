#include<bits/stdc++.h>
using namespace std;



int main()
{
	string input;
	getline(cin,input);
	stringstream ss(input);
	string token;
	vector<string> tokens;
	while(getline(ss,token,' '))
	{
		tokens.push_back(token);
		cout << token<<endl;
	}
	// cout<<"hello"<<endl;
	string output="";
	int n = tokens.size();
	for(int i=0;i<n;i++)
		// if(i<n-1)
		output += tokens[i]+"%20";
	cout << output<<endl;
	n=output.length();
	output = output.substr(0, n-3);
	cout << output<<endl;
	// cout<<"hello1"<<endl;
	return 0;
}