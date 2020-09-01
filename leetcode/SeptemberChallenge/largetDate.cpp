#include<iostream>
#include<bits/stdc++.h>
using namespace std;

 string largestTimeFromDigits(vector<int>& A) {
        string str;
        sort(A.begin(),A.end());
        int a;
     	for(int i=0;i<5;i++)
     	{
     		if(i==0)
     			a=2;
     		else if(i==1)
     		{
     			if(str[0] == '2')
     				a=3;
     			else
     				a=10;
     		}
     		else if(i==2)
     		{
     			str+=":";
     			continue;
     		}
     		else if(i==3)
     			a=5;
     		else
     			a=10;
     		
     		int j=3;
     		for(;j>=0;j--)
     		{
     			if(A[j]!=-1 and A[j]<=a)
     			{
     				str+=A[j]+48;
     				A[j]=-1;
     				break;
     			}
     		}
     		if(j==-1)
     			return "";
     	}
     	
        return str;
    }


int main()
{
 
 	vector<int> A;
 	for(int i=0;i<4;i++)
 	{
 		int a;
 		cin>>a;
 		A.push_back(a);
 	}
 	string s = largestTimeFromDigits(A);
 	cout << s<<endl;
	return 0;
}