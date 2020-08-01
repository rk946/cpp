#include<iostream>
#include<algorithm>
#include<string>

using namespace std;
bool compare(string s1,string s2)
{
	return (s1.length()) < (s2.length());
}
int main()
{
	int n;
	cout <<"Enter the number of strings";
	cin >> n;	
	string s[100];
	cin.get();
	for(int i=0;i<n;i++)
	{
		getline(cin,s[i]);
	}

	cout << "Printing the entered strings \n";
	for(int i=0;i<n;i++)
	{
		cout << s[i] <<endl;
	}


	cout<<endl;

	sort(s,s+n,compare);
cout << "Sorted string on the basis of lexical ordering" <<endl;	
for(int i=0;i<n;i++)
{
	cout << s[i]<<endl;
}

	return 0;
}