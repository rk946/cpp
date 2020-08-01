#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	cout << "Enter the string ";
	char a[1000]; 
	cin.getline(a,1000,'\n');
	cout << a;
	cout << "size = " << sizeof(a);
	int n=strlen(a);
	int i=0,j=n-1;
	while(i<j)
	{
		if(a[i]!=a[j])
		{	cout<< " Not a palindrom";
			return -1;
}
		i++;j--;

	}

	cout << a << " is a palindrom";
	return 0;
}