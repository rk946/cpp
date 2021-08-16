#include<iostream>
#include<bits/stdc++.h>
using namespace std;




int main()
{
 
	string a = "123";
	cout << to_string(INT_MAX)<<endl;
	cout << a.compare(to_string(INT_MAX))<<endl;
	cout << (to_string(INT_MAX)).compare(a)<<endl;


	cout << a.compare("12")<<endl;
	return 0;
}