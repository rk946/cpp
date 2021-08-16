#include<iostream>
#include<thread>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
/*
 *
 *
 *g++ -std=c++11 mutexFirst.cpp -lpthread -o mutexFirst
*/

std::mutex m;
int maxbuffersize = 50;
list<int> buffer;
std::condition_variable cond;

void produce(int val){
	while(val>0){
		std::unique_lock<mutex> ul(m);
		cond.wait(ul, [](){return buffer.size()<maxbuffersize;});
		buffer.push_back(val);
		val--;
		cout << "Produced "<<val <<endl;
		ul.unlock();
		cond.notify_one();
	}
}

void consume(){
	while(1){
		std::unique_lock<mutex> ul(m);
		cond.wait(ul, [](){return buffer.size()>0;});
		cout << "Consumed "<<buffer.front()<<endl;
		buffer.pop_front();
		ul.unlock();
		cond.notify_one();
	}

}

int main(){

	std::thread t1(produce,100);
	std::thread t2(consume);
	t1.join();
	t2.join();


}
