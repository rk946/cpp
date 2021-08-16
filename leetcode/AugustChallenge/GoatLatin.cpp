#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

string toGoatLatin(string S) {
        vector<string> tokens;
        stringstream ss(S);
        string intermediate;
        string output;
        while(getline(ss,intermediate,' '))
        {
            tokens.push_back(intermediate);
            
        }

        for(int i=0;i<tokens.size();i++)
        {
        	char firstChar = tokens[i][0];
            char c=firstChar;
        	if(c<=90)
                c+=32;
        	if(c=='a'|| c=='e' || c=='i' || c=='o' || c=='u')
        	{

        	}
        	else
        	{
        	
        		tokens[i].erase(0,1);
        		tokens[i]+=firstChar;        		
        	}
        	tokens[i] = tokens[i]+"ma";
        	for(int j=0;j<=i;j++)
        			tokens[i]=tokens[i]+"a";
        		output+=tokens[i]+" ";
        }
        output.erase(output.length()-1,output.length());
        return output;    
    }



int main()
{
	string output = toGoatLatin("Each word consists of lowercase and uppercase letters only");
	// string output = toGoatLatin("apple");
	cout << output;
	return 0;
}