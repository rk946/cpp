#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;


void permute(char *a,int i)
{
	//Base case
	if(a[i] == '\0')
	{
		cout << a<<",";
		return;
	}
	//Rec Case
	for(int j=i;j<strlen(a);j++)
	{
		swap(a[i],a[j]);
		permute(a,i+1);
		swap(a[i],a[j]);

	}
}

int main()
{

	char a[] = "abc";
	permute(a,0);
	return 0;

}