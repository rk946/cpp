#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*You are playing the following Bulls and Cows game with your friend: You write down a number and ask your friend to guess what the number is. Each time your friend makes a guess, you provide a hint that indicates how many digits in said guess match your secret number exactly in both digit and position (called "bulls") and how many digits match the secret number but locate in the wrong position (called "cows"). Your friend will use successive guesses and hints to eventually derive the secret number.

Write a function to return a hint according to the secret number and friend's guess, use A to indicate the bulls and B to indicate the cows. 

Please note that both secret number and friend's guess may contain duplicate digits.

Example 1:

Input: secret = "1807", guess = "7810"

Output: "1A3B"

Explanation: 1 bull and 3 cows. The bull is 8, the cows are 0, 1 and 7.
Example 2:

Input: secret = "1123", guess = "0111"

Output: "1A1B"

Explanation: The 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow.
Note: You may assume that the secret number and your friend's guess only contain digits, and their lengths are always equal.
*/

/* string getHint(string secret, string guess) {
        int cow=0,bull=0;
        int n=secret.length();
        unordered_set<char> s;
        for(int i=0;i<n;i++)
        	s.insert(secret[i]);
        for(int i=0;i<n;i++)
        {
        	if(guess[i]==secret[i])
        		bull++;
        	else if(s.find(guess[i])!=s.end())
        		cow++;
        }
        string str = "";
        str+=(bull+48);
        str+="A";
        str+=(cow+48);
        str+="B";
        return str;
        
    }*/

/* string getHint(string secret, string guess) {
        int cow=0,bull=0;
        int n=secret.length();
        unordered_map<char,int> m;
        for(int i=0;i<n;i++)
        	m[secret[i]]++;
        for(int i=0;i<n;i++)
        {
        	if(guess[i]==secret[i])
        	{
        		bull++;
        		m[secret[i]]--;
        	}
        	else if(m[guess[i]]!=0)
        	{
        		cow++;
        		m[guess[i]]--;
        	}
        	
        }
        string str = "";
        str+=(bull+48);
        str+="A";
        str+=(cow+48);
        str+="B";
        return str;
        
    }*/

string getHint(string secret, string guess) {
        int cow=0,bull=0;
        int n=secret.length();
        unordered_map<char,int> m;
     vector<int> indices;
        for(int i=0;i<n;i++)
        	m[secret[i]]++;
        for(int i=0;i<n;i++)
        {
        	if(guess[i]==secret[i])
        	{
        		bull++;
        		m[secret[i]]--;
        		if(m[secret[i]]<0)
        			{
        				cow--;
        				m[secret[i]]++;
        			}
        	}
        	else if(m[guess[i]]!=0)
        	{
        		cow++;
        		m[guess[i]]--;
        	}
        	
        }

        string str = "";
        str+=(bull+48);
        str+="A";
        str+=to_string(cow);
        str+="B";
        return str;
        
    }

int main()
{

	string secret = "00112233445566778899", guess = "16872590340158679432";
	cout << getHint(secret,guess);
	return 0;
}