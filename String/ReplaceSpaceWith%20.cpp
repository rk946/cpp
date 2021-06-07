#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	getline(cin,s);
	int n = s.length();
	int spaces=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]==' ')
			spaces++;
	}
	int i = n+(2*spaces);
	int j = n;
	
	while(j>=0)
	{
		if(s[j]==' ')
		{
			s[i-2] = '%';
			s[i-1] = '2';
			s[i] = '0';
			j--;
			i=i-2;
		}
		else
		{
			s[i]=s[j];
			i--;
			j--;
		}
	}
	cout << s<<endl;
	return 0;
}