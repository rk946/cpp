#include<iostream>

using namespace std;

void mergeSort(int a[], int s, int e)
{
	int mid=(s+e)/2;
	if(s>=e)
		return a;
	mergeSort(s,mid);
	mergeSort(mid+1,e);
	int k=0;
	for(int i=0,j=0;i<b.length,j<c.length;)
	{
		if(b[i]<c[j])
			{
				a[k] = b[i];
				k++;i++;
			}
			else
			{
				a[k]=c[j];

			}
	}


}



int main()
{


	int a[100];
	int n=0;
	cin>n;
	for(int i=0;i<n;i++)
	{
		cin>a[i];
	}


	a = mergeSort(a,0,n-1);
}