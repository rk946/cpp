#include <bits/stdc++.h>
using namespace std;

/*
required if the pointer to the base class should access method of base class only
used in inheritance*/

class A{
public:
	void f1(){
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
	c->f1(); // Here f1 of B should have been called but f1 of A is called, For this virtual function is required
return 0;
}
