#include<iostream>
using namespace std;


int sol(int a,int b)
{
	if(b==0 || a==0)
		return 0;
	if(b>0)
		return a+sol(a,b-1);
	else if(b<0 and a>0)
		return b+sol(a-1,b);
	else
		return -(a-sol(a,b+1));
	


}


int main()
{

	int a,b;
	cin>>a>>b;
	cout << sol(a,b);
}


	

