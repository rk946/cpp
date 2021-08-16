#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

class Car{
public:
	int price;
	int model_no;
	string name;

//Default Constructor
	Car(){
		cout << "default constructor calling"<<endl;
	}
//Parameterised Constructor
	Car(int p, int m, string n){
		price =p;
		model_no=m;
		name=n;
		cout << "Parameterised constructor called"<<endl;
	}

	Car(Car &X){
		price = X.price;
		model_no = X.model_no;
		name = X.name;
	}

	void print(){
		cout << price << " "<<model_no << " "<< name<<endl;
	}
};
int main()
{

	Car A;
	Car B(1000,1001,"Audi");
	A.print();
	B.print();

	Car C=B;
	C.print();

	
	Car *D = new Car();

	return 0;

}