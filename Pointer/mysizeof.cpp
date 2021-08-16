#include<bits/stdc++.h>

using namespace std;

#define my_sizeof(type) (char *)(&type+1)-(char*)(&type)

template<typename T>
int mysize(T* a){
	return (char*)(a+1) - (char*)a;

}

class Dog{
public:
	
	int x;
	int y;
	long l;
	int z;
	int a;
	char d;
	int b;
	char f;
	char g;
	int k;
	int t;
	int fq;
};
int main()
{
    double x;
    printf("%ld", my_sizeof(x));
    cout << mysize(&x);
    Dog *d = new Dog();
    cout << mysize(d);
    // getchar();
    return 0;
}