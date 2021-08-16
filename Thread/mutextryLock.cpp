#include<iostream>
#include<thread>
#include<mutex>
#include<vector>
using namespace std;
/*
 *
 *
 *g++ -std=c++11 mutexFirst.cpp -lpthread -o mutexFirst
*/
int counter=0;
std::mutex m;
void incrementby100000(){
	for(int i=0;i<100000;i++){
	if(m.try_lock()) // it will try to lock, if successful return true else returns false
	++counter;
	m.unlock();
}
}

int main(){
	
	
	std::thread t1(incrementby100000);
	std::thread t2(incrementby100000);
	


	t1.join();
	t2.join();
	
	cout << counter <<endl;
	return 0;


}
