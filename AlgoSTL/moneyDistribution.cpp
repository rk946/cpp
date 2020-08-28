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
	int key=37;
	while(key>0)
	{
		auto lb = upper_bound(a,a+n,key);
		int index = lb-a-1;
		int coin = a[index];
		cout << coin <<" , ";
		key = key- coin;
	}
	return 0;
}
