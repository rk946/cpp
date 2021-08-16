#include<iostream>
#include<thread>

#include<vector>
using namespace std;
/*
 *
 *
 *g++ -std=c++11 mutexFirst.cpp -lpthread -o mutexFirst
*/



int main(){

// Lambda function
	auto fun = [](int x){
		while(x-- > 0)
			cout << x<< endl;
	};
//thread called using function parameter
	std::thread t1(fun, 10);
	t1.join();
cout << "Using actual lambda" << endl;

//call thread using lambda
	std::thread t2([](int x){
		while(x-- > 0)
			cout << x <<endl;
	}, 6);
	t2.join();
	
	// cout << odd <<endl;
	return 0;


}
