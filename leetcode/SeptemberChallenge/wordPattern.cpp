#include<iostream>
#include<bits/stdc++.h>
using namespace std;

    bool wordPattern(string pattern, string str) {
        unordered_map<char,string> mapping;
        unordered_map<string,bool> mapping2;
        int i=0;
        stringstream ss(str);
        string temp;
        int len = pattern.length();
        while(getline(ss,temp,' '))
        {
            if(mapping[pattern[i]] == "")
            {
            	if(!mapping2[temp])
            	{
                	mapping[pattern[i]] = temp;
                	mapping2[temp]=true;
                }
                else
                	return false;
            }
            else if(mapping[pattern[i]]!=temp)
                return false;

            i++;
        }
        if(i!=len)
        	return false;
        return true;
        
    }



int main()
{
	string pattern = "jquery", str = "jquery";
	cout << wordPattern(pattern,str);
	return 0;
}