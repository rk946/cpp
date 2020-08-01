#include<iostream>
using namespace std;

void findUnique2(int a[],int n)
{

	int res = 0;
	for(int i=0;i<n;i++)
		res = res^a[i];

	int i=0;
	int temp=res;
	cout << "res =  "<< res<<endl;
	if(temp==0)
		cout << "No numbers present uniquely";
	while(temp>0)
	{
		if(temp&1)
			break;
		temp = temp>>1;
		i++;
	}

	cout <<endl <<i<<endl;
int first = 0;
int second = 0;
	for(int j=0;j<n;j++)
	{
		if(((a[j])&(1<<i)))
			first=first ^ a[j];
	}

second = res ^ first;
cout << "first "<<first <<endl;
cout <<"second "<<second <<endl;
}


int main()
{
	int a[] = {1,2,1,2,6,6,9,9,11,11};
	
	int n=sizeof(a)/sizeof(int);
	findUnique2(a,n);
		return 0;
}