#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

bool compare(pair<int,int> a, pair<int,int> b)
{
	return a.first>b.first;
}
int main()
{
	vector<pair<int,int>> a;
	for(int i=0;i<10;i++)
	{
		a.push_back(make_pair(10-i,i));
	}
	sort(a.begin(),a.end(),compare);
	cout << "Printing \n";
	for(int i=0;i<10;i++)
		cout << a[i].first <<" , " <<a[i].second << "\n";
	return 0;

}