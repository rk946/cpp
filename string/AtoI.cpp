#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


  int myAtoi(string s) {
        bool flag=false;
        long long num=0;
        int n = s.length();
        for(int i=0;i<n;i++)
        {
            char c = s[i];
            if(c==' ')
            	continue;
            else if(c=='-')
            	flag=true;
            else if(c>='0' and c<='9')
            {
            	num*=10;
            	num+=c-'0';
            	
            
            	if(num>=INT_MAX)
            	{
            		if(flag)
            		{	
            			num = num*-1;
            			if(num<=INT_MIN)
	            			return INT_MIN;
    	        	}
            		return INT_MAX;
            	}
            	
            }
            else
            	break;
        }
        if(flag)
            num = num*-1;
        return num;
        
    }
int main()
{
	string s;
	getline(cin,s);
	cout << myAtoi(s)<<endl;
	return 0;

}