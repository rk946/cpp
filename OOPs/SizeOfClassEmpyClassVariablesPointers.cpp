    #include <iostream>  
    #include <set> 
    #include<bits/stdc++.h> 
      
    using namespace std;  

 
class Empty {
};
 
class Derived1 : public Empty {
};
 
class Derived2 : virtual public Empty {
};
 
class Derived3 : public Empty {
    char c;
};
 
class Derived4 : virtual public Empty {
    char c;
};
 
class Dummy {
    char c;
};

class A { 
private: 
        float iMem1; 
        const int iMem2; 
        static int iMem3; 
        char iMem4; 
}; 

class C { 
        char c; 
        int int1; 
        int int2; 
        int i; 
        long l; 
        short s; 
};

class D { 
        int int1; 
        int int2; 
        int i; 
        long l; 
        short s; 
        char c; 
}; 
 
int main()
{
    cout << "sizeof(Empty) " << sizeof(Empty) << endl;
    cout << "sizeof(Derived1) " << sizeof(Derived1) << endl;
    cout << "sizeof(Derived2) " << sizeof(Derived2) << endl;
    cout << "sizeof(Derived3) " << sizeof(Derived3) << endl;
    cout << "sizeof(Derived4) " << sizeof(Derived4) << endl;
    cout << "sizeof(Dummy) " << sizeof(Dummy) << endl;
    cout << "sizeof(A) " <<sizeof(A)<<endl; 
    float f = 123.156;
    int a = 4564;
    char c = 'd';
    cout << "sizeof(float)"<< sizeof(f)<<endl;
    cout << "sizeof(int)"<< sizeof(a)<<endl;
    cout << "sizeof(char)"<< sizeof(c)<<endl;
    int *i = new int(10);
    void *v;
    cout << "size of int pointer "<<sizeof(i)<<endl;
    cout << "size of void pointer "<<sizeof(v)<<endl;
    float *f1;
    cout << "size of float pointer "<<sizeof(f1)<<endl;

    C c1;
    D d1;
    cout << "sizee of C "<<sizeof(c1)<<endl;
    cout << "sizee of D "<<sizeof(d1)<<endl;

    C *c2 = new C;
    cout << "size of pointer to C class " << sizeof(c2)<<endl;

    long l;
    short s;
    cout << "sizeof(long) "<<sizeof(l)<<endl;
    cout << "sizeof(short) "<<sizeof(s)<<endl;
    return 0;
}