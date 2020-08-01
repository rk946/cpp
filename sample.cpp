#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
#include<climits>
using namespace std;

int main()
{
	int i = 1000000;
	int j=0;
	while(i>0)
	{
		i=i/2;
		j++;
	}
	cout << j;
	return 0;

}