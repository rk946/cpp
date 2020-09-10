#include<iostream>
#include<bits/stdc++.h>
using namespace std;



int main()
{
	string num="100";

	int j=0;
	int n = num.length()-1;
	cout << n<<endl;
	int a=0;
	int mul=1;
	while(j<=n)
        	{
        		cout << a <<endl;
        		a+=((num[n-j]-48)*mul);
        		mul*=2;
        		j++;
        	}
        	cout << a;
	return 0;
}