#include<bits/stdc++.h>

using namespace std;
class SmartPointer{
	int *ptr;
public:
	SmartPointer(int *p=NULL){
		ptr = p;
	}	
	~SmartPointer(){
		delete ptr;
	}

	int& operator *(){
		return *ptr;
	}

	int* operator ->(){
		return ptr;
	}
};
int main(){
	SmartPointer s(new int(10));
	cout << *s;

	return 0;
}