#include<iostream>
#include<algorithm>
using namespace std;

int search(int a[],int n,int key)
{

	int s=0,e=n-1;
	int mid=(s+e)/2;
	int result=-1;
	while(s<=e)
	{

		mid=(s+e)/2;
		if(a[mid]==key)
			return mid;
		else if(a[s]<=a[mid])
			{
				if(key<=a[mid] and key >=a[s])
				e=mid-1;
				else
					s=mid+1;
			}
		else if(a[e]>=a[mid])
		{
			if(key>=a[mid] and key<=a[e])
				s=mid+1;
			else
				e=mid-1;
		}

	}
	return result;

}

int main()
{
	int a[]= {4,5,1,2,3};
	int n=sizeof(a)/sizeof(int);
	int key=0;
	cout <<"Enter key"<<endl;
	cin>>key;

	int index = search(a,n,key);

	cout <<endl<< "Index = "<<index<<endl;
	return 0;
}