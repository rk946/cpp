#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

class A{
	int i,j;
public:
	A(int x, int y){
		i=x;
		j=y;
	}

	void display(){
		cout << "i = " <<i<<" j= "<<j<<endl;
	}	
};

int main()
{

	A a(10,20);
	a = {30,40};
	a.display();
	
	return 0;

}