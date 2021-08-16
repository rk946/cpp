#include<iostream>
#include<algorithm>

using namespace std;

bool compare(int a,int b)
{
	// cout << "Comparing "<<a << "  " <<b<<endl; 
	return a<=b;
}
int main()
{
	int a[]={1,2,5,10,20,50,100,500,2000};
	int n=sizeof(a)/sizeof(int);
	auto index = lower_bound(a,a+n,200);
	cout << index - a << endl;
	// for(int i=0;i<n;i++)
	// 	cout << a[i] << " ";
	// cout <<endl;
	return 0;
}
