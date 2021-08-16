#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
int key=3;
int a[] = {1,2,4,5};
int n=sizeof(a)/sizeof(a[0]);
	auto b=binary_search(a,a+n,key);
	cout<<b<<endl;

	auto c = lower_bound(a,a+n,key);
	cout << "Lower Bound = "<<c-a	<<endl;


	auto d = upper_bound(a,a+n,key);
	cout << "Upper Bound = "<<d-a	<<endl;
	
	cout << "No of occurences of "<<key<< " = "<< d-c<<endl;
	return 0;
}