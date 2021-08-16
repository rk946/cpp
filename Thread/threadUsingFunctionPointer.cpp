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
	


	t1.join();

	
	cout << odd <<endl;
	return 0;


}
