#include<iostream>
#include<vector>
#include<map>
using namespace std;

    int compress(vector<char>& chars) {
     
     	int res=0;
     	   map<char,int> a;
        for(int i=0;i<chars.size();i++)
        {
        	a[chars[i]]++;
        }  
        for(auto x:a)
        {
        	if(x.second==1)
        		res++;
        	else if(x.second>1 and x.second<=9)
        		res=res+2;
        	else if(x.second>=10 and x.second<=99)
        		res=res+3;
        	else if(x.second>=100 and x.second<=999)
        		res=res+4;
        	else if(x.second>=1000)
        		res+=5;

        } 
        return res;
    }

int main()
{
 	vector<char> chars{"a","a","b","b","c","c","c"};
 	cout << compress(chars)<<endl;


	return 0;
}