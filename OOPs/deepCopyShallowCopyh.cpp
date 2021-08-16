#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

class Car{
public: 
	int* price;
	Car(int*p){
		price = p;
	}
	Car(Car &X){
		price = new int(*(X.price)); ////Deep Copy
		// price = X.price; //Shallow Copy
	}
	void print(){
		cout << *price<<endl;
	}
};
int main()
{
	Car A(new int(10));
	A.print();

	Car B =A;
	B.print();

	*(A.price) = 15;

	A.print();
	B.print();
	
	return 0;

}