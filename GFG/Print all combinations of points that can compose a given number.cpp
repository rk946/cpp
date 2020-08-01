#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
char print(int n)
{
	//Base case
	if(n<=0)
		return 0;
	if(n>=1)
	cout << "1" <<" " << print(n-1)<<endl;
	if(n>=2)cout << "2" <<" " << print(n-2)<<endl;
	if(n>=3)cout << "3" <<" " << print(n-3)<<endl;

}
int main()
{
	int n;
	cin>>n;
	print(n);

	return 0;

}