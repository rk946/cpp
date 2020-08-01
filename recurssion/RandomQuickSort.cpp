#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int findPivot(int *a,int s, int e)
{
	int i = s-1;
	for(int j=0;j<e;j++)
	{
		if(a[j]<a[e])
		{
			swap(a[j],a[i+1]);
			i++;
		}


	}
	swap(a[e],a[i+1]);
	return i+1;
}


void quickSort(int *a, int s, int e)
{
	if(s>=e)
		return;
	int pivot = findPivot(a,s,e);
	quickSort(a,s,pivot-1);
	quickSort(a,pivot+1,e);
}

void shuffleArray(int *a, int s, int e)
{
	srand(time(NULL));
	int i,j;
	for(int i=e;i>s;i--)
	{
		j = rand()%(i+1);
		swap(a[i],a[j]);
	}
}

int main()
{
	int a[]= {1,2,3,4,5,6,7};
int n = sizeof(a)/sizeof(int);
shuffleArray(a,0,n-1);
cout << "after shuffling"<<endl;
for(int i=0;i<n;i++)
	{cout << a[i] <<  " "; }
cout <<endl<<" after quick sort "<<endl;
quickSort(a,0,n-1);
for(int i=0;i<n;i++)
	{cout << a[i] <<  " "; }
return 0;

}