#include<iostream>
using namespace std;

void subset(char *a, int num)
{
	int i=0;
	while(num>0)
	{
		num&1?cout << a[i]: cout <<"";
		num = num >>1;
		i++;
	}

}


void getNumbers(char *a,int n)
{
	int range = (1<<n)-1;
	for(int i=0;i<=range;i++)
	{
		subset(a,i);
		cout << endl;
	}

}


int main()
{
	
	char a[100];
	cin>>a;
	int n=sizeof(a)/sizeof(char);
	getNumbers(a,n);
		return 0;
}