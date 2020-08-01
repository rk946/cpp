#include<iostream>
#include<algorithm>
using namespace std;

bool compare(int a , int b)
{
	return a<b;
}

int main()
{
	int n=5;
	int a[5]= {5,3,7,1,2};

sort(a,a+n,compare);

	cout << "Printing elements in sorted order";
	for(int i=0;i<n;i++)
	{
		cout << a[i] << ",";
	}
return 0;
}