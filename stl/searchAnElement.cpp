#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
int key=5153;
int a[5] = {1,2,3,4,5};
	auto b=find(a,a+5,key);
	cout<<b-a<<endl;
	return 0;
}