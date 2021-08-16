#include <bits/stdc++.h>
using namespace std;
/*Required if definition of function is to be outside the class and we need to access 
private variable of the class outside the class
Example two classes are there class1 wants to access private members of class2 then friend function
in class A and class B can be created and both can access private members of both classes*/


/*friend funcion is only declared in the class
definition is outside the class */


class A{
	int x;
public:
	friend void fun(A);
	// {
	// 	cout << "fun called in A"<<endl;
	// }
	void f1(){
		x=10;
		cout << "called f1"<<endl;
	}
};

void fun(A a){
	cout << "fun called outside"<<endl;
	cout << a.x<<endl;
}
class B:public A{
public:
	// void fun(){
	// 	cout << "fun called in B"<<endl;
	// }

};
class D;
class C{
	int c;
public:
	friend void fun(C,D);
	void set(){
		c=15;
	}
	
};
class D{
	int d;
public:
	friend void fun(C,D);
	void set(){
		d=20;
	}
};
class E{
	int e;
public:
	friend class F;
	void set(){
		e=50;
	}
};

class F{
public:
	void printE(E& e1){
		cout << e1.e <<endl;
	}

};
void fun(C c1,D d1){
	cout <<"otside C inside fun of C "<<endl;
	cout << c1.c<<" "<<d1.d<<endl;
}


// void fun(C c1,D d1){
// 	cout <<"otside D inside fun of D` "<<endl;
// 	cout << c1.c<<" "<<d1.d<endl;
// }
int main()
{
	A a;
	B b;
	a.f1();
	b.f1();
	fun(b);
	fun(a);

	C c;
	D d;
	c.set();
	d.set();
	fun(c,d);

	E e;
	e.set();

	F f;
	f.printE(e);
return 0;
}
