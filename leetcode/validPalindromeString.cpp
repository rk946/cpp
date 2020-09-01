#include<iostream>
#include<vector>
#include<string>
using namespace std;

	bool helper(string str, int s, int e)
    {
        if(s>=e)
            return true;
        char c=str[s];
        char d=str[e];
        
       // if((c>122) || (c<48 and c>57) or (c<65) || (c>90 and c<97) )
       //      return helper(str,s+1,e);
       //  else if(c>=65 and c<=90)
       //      c=c+32;
        
       //  if((d>122) or (d<48 and d>57) or (d<65) or (d>90 and d<97) )
       //      return helper(str,s,e-1);
       //  else if(d>=65 and d<=90)
       //      d=d+32;
        

        if(c>=65 and c<=90)
        	c=c+32;
        else if(c<48 or (c>57 and c<64) or (c>90 and c<97) or c>122)
        	helper(str,s+1,e);
        
        if(d>=65 and d<=90)
        	d=d+32;
        else if(d<48 or (d>57 and d<64) or (d>90 and d<97) or d>122)
        	helper(str,s,e-1);
        
        cout << "c = "<<c<<","<<"d = "<<d<<endl;cp
        if(c==d)
        {
            return helper(str,s+1,e-1);
        }
        else
            return false;
        
        
    }
    bool isPalindrome(string s) {
        return helper(s,0,s.length()-1);       
    }

int main()
{
 	
 	string s="A man, a plan, a canal: Panama";
 	cout << isPalindrome(s);

	return 0;
}