#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

// If the fractional part is repeating, enclose the repeating part in parentheses.

// If multiple answers are possible, just return any of them.

// Example 1:

// Input: numerator = 1, denominator = 2
// Output: "0.5"
// Example 2:

// Input: numerator = 2, denominator = 1
// Output: "2"


 string fractionToDecimal(int numerator, int denominator) {
        int a = numerator/denominator;
        string s="";
        while(a>0)
        {
        	a/=10;
        }

        
    }


int main()
{
 

	return 0;
}