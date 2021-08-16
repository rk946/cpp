#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
int key=3;
vector<int> a = {1,2,3,4,5};
	auto b=find(a.begin(),a.end(),key);
	cout<<*b<<endl;
	return 0;
}