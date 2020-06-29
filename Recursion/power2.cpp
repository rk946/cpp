#include<iostream>
using namespace std;


int sol(int a,int b)
{
	if(b==1)
		return a;
	int c=sol(a,b/2);
	if(b&1)
		return (a*c*c);
	else
		return c*c;
}


int main()
{

	int a,b;
	cin>>a>>b;
	cout <<a<<endl;
	cout <<b<<endl;

	cout << sol(a,b) <<endl;
}