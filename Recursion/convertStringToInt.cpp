#include<iostream>
#include<cstring>
#include<math.h>
using namespace std;


int sol(char *a,int n)
{
	if(n==0)
		return 0;
	return (sol(a+1,n-1)+(*a-48)*pow(10,n-1));
}


int main()
{

	char a[]="1234";
	// char a[]={'1','2','3','4'};
	int n= sizeof(a)/sizeof(char);
	// cin>>a;
	// getch();
	// cout << strlen(a);
	cout << sol(a,n-1)-1 <<endl;
}