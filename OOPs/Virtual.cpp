#include <bits/stdc++.h>
using namespace std;

/*
required if the pointer to the base class should access method of base class only
used in inheritance
virtual functiton can have definition in the class as well
*/

class A{
public:
	virtual void f1(){
		cout << "f1 in A\n";
	}
};

class B:public A{
public:
	void f1(){
		cout << "f1 in B"<<endl;
	}
};

int main()
{
	A a;
	a.f1();
	B b;
	b.f1();

	A *c;
	c=&b;
	c->f1(); // Now late biniding happens and f1 of B is called here

return 0;
}
