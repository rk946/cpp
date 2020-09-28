#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*Given an alphanumeric string, extract maximum numeric value from that string.

Examples:

Input : 100klh564abc365bg
Output : 564
Maximum numeric value among 100, 564 
and 365 is 564.
Input : abchsd0365sdhs
Output : 365*/
int convertStringToInt(string s)
{
	
	int res;
	int n = s.length();
	res = s[0]-'0';
	for(int i=1;i<n;i++){
	
		res*=10;
		res+=(s[i]-'0');
	
	}
	
	return res;
}


int findMaxint(string input)
{
	int n = input.length();
	string temp="";
	int res=0;
	for(int i=0;i<n;i++)
	{
		if(isdigit(input[i]))
		{
			temp+=input[i];
		}
		else if(temp!="")
		{
			int a = convertStringToInt(temp);
			if(a>res)
				res=a;
			temp="";
		}
		else
			temp="";
	}
	return res;
}

int main()
{
 	string input = "100klh564abc365bg";
 	cout << findMaxint(input);

	return 0;
}