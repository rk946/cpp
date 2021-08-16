#include<iostream>
#include<thread>

#include<vector>
using namespace std;
/*
 *
 *
 *g++ -std=c++11 mutexFirst.cpp -lpthread -o mutexFirst
*/

int odd=0;
void findOdd(int start, int end){
	for(int i=start;i<=end;i++)
	{
		if(i&1)
			odd+=i;
	}


}

int main(){
	
	
	std::thread t1(findOdd, 1,10);
	

	if(t1.joinable())
	t1.join();
	//t1.join(); //will give error
if(t1.joinable())
	t1.join();

if(t1.joinable())
	t1.join();

if(t1.joinable())
	t1.detach(); // called only if t1 is joinable // main will not wait for t1 to terminate


	
	cout << odd <<endl;
	return 0;


}
