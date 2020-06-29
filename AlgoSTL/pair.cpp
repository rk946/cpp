#include<iostream>

using namespace std;

int main()
{

	pair<int,char> p;
	p.first=1;
	p.second='A';

	cout << p.first << " " <<p.second<<endl;


	pair<int,char> p2=p;

cout << p2.first << " " <<p2.second<<endl;	

pair<int,char> p3 = make_pair(1,'B');
cout << p3.first <<" "<<p3.second<<endl;


	return 0;
}
