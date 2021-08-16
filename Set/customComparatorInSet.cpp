#include<bits/stdc++.h>
using namespace std;

template <typename T>
class compare{
public:
	bool operator ()(const T &a, const T &b){
		return a>b;
	}
};

int main(){
	set<int,compare<int>> s;
	s.insert(5);
	s.insert(15);
	s.insert(2);
	s.insert(52);
	s.insert(63);


	for(auto i:s)
		cout << i << " ";
	cout << endl;
	return 0;
}