#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Compare two version numbers version1 and version2.
If version1 > version2 return 1; if version1 < version2 return -1;otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.

The . character does not represent a decimal point and is used to separate number sequences.

For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

You may assume the default revision number for each level of a version number to be 0. For example, version number 3.4 has a revision number of 3 and 4 for its first and second level revision number. Its third and fourth level revision number are both 0.

 

Example 1:

Input: version1 = "0.1", version2 = "1.1"
Output: -1
Example 2:

Input: version1 = "1.0.1", version2 = "1"
Output: 1
Example 3:

Input: version1 = "7.5.2.4", version2 = "7.5.3"
Output: -1
Example 4:

Input: version1 = "1.01", version2 = "1.001"
Output: 0
Explanation: Ignoring leading zeroes, both “01” and “001" represent the same number “1”
Example 5:

Input: version1 = "1.0", version2 = "1.0.0"
Output: 0
Explanation: The first version number does not have a third level revision number, which means its third level revision number is default to "0"
 

Note:

Version strings are composed of numeric strings separated by dots . and this numeric strings may have leading zeroes.
Version strings do not start or end with dots, and they will not be two consecutive dots.

*/

int compareVersion(string version1, string version2) {
        stringstream s1(version1);
        string temp1;
        vector<int> num1,num2;
        stringstream s2(version2);
        string temp2;
        while(getline(s1,temp1,'.'))
        {
            int n = temp1.length();
            int num=0;
            if(n<=1)
                num = temp1[0]-48;
            else
            {
                int i=0;
                
                while(i<n)
                {
                    num+=((temp1[n-i-1]-48) * pow(10,i));
                    i++;
                }
            }
            num1.push_back(num);
        }
        
        while(getline(s2,temp2,'.'))
        {
            int n = temp2.length();
            int num=0;
            if(n<=1)
                num = temp2[0]-48;
            else
            {
                int i=0;
                
                while(i<n)
                {
                    num+=((temp2[n-i-1]-48) * pow(10,i));
                    i++;
                }
            }
            num2.push_back(num);
        }
        int size1 = num1.size();
        int size2 = num2.size();
        int finalSize=size1;
        if(size1-size2>0)
        {
            for(int i=0;i<(size1-size2);i++)
                num2.push_back(0);
            finalSize = size1;
        }
        else if(size2-size1>0)
        {
             for(int i=0;i<(size2-size1);i++)
                num1.push_back(0);
            finalSize = size2;
        }
        
        cout << "testing"<<endl;
        for(int i=0;i<num1.size();i++)
        	cout << num1[i] <<" , "<<num2[i]<<endl;
        cout << "tested"<<endl;


        int i=0;
        for(; i< finalSize; i++)
        {
            if(num1[i]<num2[i])
                return -1;
            else if(num1[i]>num2[i])
                return 1;
        }
        return 0;
        
        
    }

int main()
{

	cout << compareVersion("1.0","1.0.0")<<endl;

	return 0;
}