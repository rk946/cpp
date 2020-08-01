#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	cout << "Enter the number of strings \n";
	int n;
	cin >> n;
	cin.get();
	char str[1000],lar[1000]; 
	for(int i=0;i<n;i++)
	{
		cin.getline(str,1000);
	//	if(i==0)
	//		lar=str;
	if(strlen(lar)<strlen(str))
	{
		strcpy(lar,str);
	}


	}
	
cout << "Larget String " << lar;
	return 0;
}