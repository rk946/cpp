#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


    string longestCommonPrefix(vector<string>& strs) {
    	int len = strs[0].length();
    	string ref = strs[0];
    	for(int i=1;i<strs.size();i++)
    	{
    		while(strs[i].compare(0,len,ref,0,len))
    		{
    			len--;
    			if(len<=0)
    				return "";
    		}
    	}

    	return ref.substr(0,len);
        
    }
int main()
{
	
	vector<string> strs;
	// strs.push_back("flower");
	// strs.push_back("flow");
	// strs.push_back("flight");
	strs.push_back("race");
	strs.push_back("car");
	strs.push_back("dog");
	cout << longestCommonPrefix(strs)<<endl;
	return 0;

}