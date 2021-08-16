#include <bits/stdc++.h>
using namespace std;

/*
required if the pointer to the base class should access method of base class only
used in inheritance
virtual functiton can have definition in the class as well
*/

class A{
public:
	virtual void f1()=0;
};

class B:public A{
public:
	void f1(){
		cout << "f1 in B"<<endl;
	}
};

int main()
{
	
	B b;
	b.f1();

	

return 0;
}
