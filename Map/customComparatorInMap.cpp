#include<bits/stdc++.h>
using namespace std;



class Compare{
public:
	bool operator()(const int &a, const int &b){
		return a>b;

	}
};
int main(){
	map<int,int,Compare> m;
	m[1] = 10;
	m[2] = 20;
	m[5] = 50;
	m[4] = 40;

	for(auto i:m)
		cout << i.first << " "<<i.second<<endl;
	cout << endl;
	return 0;
}