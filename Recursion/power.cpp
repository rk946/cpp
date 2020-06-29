#include<iostream>
using namespace std;


int sol(int a,int b)
{
	if(b==1)
		return a;
	return a*sol(a,--b);
}


int main()
{

	int a,b;
	cin>>a>>b;
	cout <<a<<endl;
	cout <<b<<endl;

	cout << sol(a,b) <<endl;
}