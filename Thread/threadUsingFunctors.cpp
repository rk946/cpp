#include<iostream>
#include<thread>

#include<vector>
using namespace std;
/*
 *
 *
 *g++ -std=c++11 mutexFirst.cpp -lpthread -o mutexFirst
*/

class Base{
public:
	void operator()(int x){
		while(x-- > 0)
			cout << x << endl;
	}
};


int main(){


	//Approach 1
	std::thread t1((Base()),10);
	t1.join();

	//Approach 2
	Base b;
	std::thread t2(b,10);
	t2.join();

	return 0;


}
