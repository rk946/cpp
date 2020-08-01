#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	cout << "Enter the string \n";
	char a[1000]; 
	cin.getline(a,1000,'\n');
	cout <<"My SOP "<< a <<"\n";
	int n=strlen(a);
	for(int i=0,j=0;i<=n;)
	{
		if(a[i]!=a[j])
			a[++j]=a[i++];
		i++;
			
	}

	cout << a << " updated";
	return 0;
}