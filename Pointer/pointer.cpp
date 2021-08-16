#include<bits/stdc++.h>

using namespace std;

int main(){

	int x=10;
	int *y;
	y=&x;
	cout << y<<endl;

	int arr[]={1,2,3};
	cout << arr<<endl;
	cout << &arr<<endl; 	
	cout << &arr[0]<<endl;
	cout << *y;
	return 0;
}