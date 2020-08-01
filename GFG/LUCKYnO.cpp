#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isLucky(int n)
{
	int i=1,j=0;

	while(i<n)
	{

		if(j&1)
		{
			cout << j << " odd " <<endl;
			i+=4;
		}
		else
		{
			cout << j << " even " <<endl;
			i+=2;
		}
		j++;
	}
	cout << i << " "<<j<<endl;
			if(n==i)
			return true;
		else
	return false;
}
int main()
{

	int x;
	cin >>x;
	cout << isLucky(x) <<endl;
	return 0;

}