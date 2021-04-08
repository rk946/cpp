#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

 bool isPalindrome(string s) {
        int n = s.length();
        int j = n-1;
        for(int i=0;i<n;)
        {
            if(i>j)
                return true;
            
            
            if(s[i]>='A' and s[i]<='Z')
                s[i]+=32;
            else if(s[i]<'a' or s[i]>'z')
            {
                i++;
                continue;
            }
            
            if(s[j]>='A' and s[j]<='Z')
                s[j]+=32;
            else if(s[j]<'a' or s[j]>'z')
            {
                j--;
                continue;
            }
            cout << "Comparing "<<s[i]<<" , "<<s[j]<<endl;
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
            
        }
        return true;
        
        
    }

int main()
{

	cout << isPalindrome("A man, a plan, a canal : Panama");
	return 0;

}