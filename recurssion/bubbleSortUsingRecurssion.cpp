#include<iostream>
using namespace std;

void bubbleSortRecursion(int *a, int n)
{
	if(n==0)
		return;
	for(int i=0;i<n-1;i++)
	{
		if(a[i]>a[i+1])
			swap(a[i],a[i+1]);
	}
	bubbleSortRecursion(a,n-1);

}

void bubbleSortRecursion2()
{
	
}


int main()
{
	int a[]= {1,5,2,9,3,6,7};
int n = sizeof(a)/sizeof(int);
bubbleSortRecursion(a,n);
for(int i=0;i<n;i++)
	{cout << a[i] <<  " "; }
return 0;

}