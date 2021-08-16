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
	int a[] = {43772400,1674008457,1779561093,744132272,1674008457,448610617,1779561093,124075538,-1034600064,49040018,612881857,390719949,-359290212,-812493625,124732,-1361696369,49040018,-145417756,-812493625,2078552599,1568689850,865876872,865876872,-1471385435,1816352571,1793963758,2078552599,-1034600064,1475115274,-119634980,124732,661111294,-1813882010,1568689850,448610617,1347212898,-1293494866,612881857,661111294,-1361696369,1816352571,-1813882010,-359290212,1475115274,1793963758,1347212898,43772400,-1471385435,124075538,-1293494866,-119634980,390719949};
	
	int n=sizeof(a)/sizeof(int);
	findUnique2(a,n);
		return 0;
}