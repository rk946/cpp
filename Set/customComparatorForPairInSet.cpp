#include<bits/stdc++.h>
using namespace std;

// template <typename T>
class compare{
public:
	bool operator ()(const pair<int,int> &a, const pair<int,int> &b){
		return a.second>b.second;
	}
};

int main(){
	set<pair<int,int>,compare> s;
	s.insert(make_pair(5,10));
	s.insert(make_pair(15,213));
	s.insert(make_pair(2,123));
	s.insert(make_pair(52,45));
	s.insert(make_pair(63,123));


	for(auto i:s)
		cout << i.first << " " <<i.second << endl;
	cout << endl;
	return 0;
}