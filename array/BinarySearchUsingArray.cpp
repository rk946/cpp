#include<iostream>
using namespace std;

int main()
{
	int n;
cin >> n;
int a[n]={0};
for(int i=0;i<n;i++)
{
	cin>>a[i];
}

cout << "Find the element to search \n";

int key;

cin>>key;
int s=0;
int length=sizeof(a)/sizeof(int);
int e=n-1;
int m=0;
while(s<=e)
{
	m=(s+e)/2;
	if(a[m]==key)
		break;
	else if(key<a[m])
		e=m-1;
	else if(key>a[m])
		s=m+1;
		
	}

if(a[m]==key)
	cout << key <<" element found at index = " << m;
else
	cout << key << " element not found";
return 0;
}