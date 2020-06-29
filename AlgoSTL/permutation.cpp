#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool compare(int a,int b)
{
	// cout << "Comparing "<<a << "  " <<b<<endl; 
	return a<=b;
}
int main()
{
	vector <int>a{1,2,5,10,20,50,100,500,2000};
	for(int i=0;i<a.size();i++)
		cout<<a[i] << " ";

	cout << "after rotating";

	next_permutation(a.begin(),a.end());
for(int i=0;i<a.size();i++)
		cout<<a[i] << " ";
	return 0;
}
