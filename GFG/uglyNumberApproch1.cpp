#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// Ugly numbers are numbers whose only prime factors are 2, 3 or 5. The sequence 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, … shows the first 11 ugly numbers. By convention, 1 is included. 
//print nth ugly numbers 

int divide(int a, int b)
{
	while(a%b==0)
		a=a/b;
	return a;
}

bool isUgly(int n)
{
	if(n==1)
		return true;
	n = divide(n,2);
	n = divide(n,3);
	n = divide(n,5);
	if(n==1)
		return true;
	else 
		return false;
}


int getNumber(int n)
{
	int count=1;
	if(n==1)
	{
		cout << 1<<endl;
		return 1;
	}
	int number = 1;
	while(count<n)
	{
		number++;
		if(isUgly(number))
		{	
			count++;
			cout << number<<",";
		}
		
	}
	cout << endl;
	return number;
}

int main()
{

	int n;
	cin>>n;
	cout << getNumber(n);
	return 0;

}