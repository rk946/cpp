#include<iostream>
#include<vector>
#include<cstring>
using namespace std;



int main()
{
	char s[100]="Today is a rainy day";
 	cout << s<<endl;
 	string s1 = s;
 	s1+=" also";
 	cout << s1<<endl;	
 	string s2;
 	strcpy(s1,s2);
 	cout << strcpy(s1)<<endl;
 	
	return 0;
}