#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int multiplyBy6(int n)
{
	return ((n<<3) - (n<<1));
}
int main()
{

	int n;
	cin>>n;
	cout << multiplyBy6(n) <<endl;
	return 0;

}