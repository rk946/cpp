#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int getnumeralC(char num)
{
	if(num>='0' and num<='9')
		return num-'0';
	else if(num>='A' and num<='Z')
		return num-'A'+10;
}

char getnumeralI(int num)
{
	if(num>=0 and num<=9)
		return num+'0';
	else if(num>=10 and num<=14)
		return num+'A'-10;
}
char * add(char* a, char* b)
{

	int asize = strlen(a);
	// cout<<asize<<endl;
	int bsize = strlen(b);
	// cout<<bsize<<endl;
	char *sum= new char[asize+1];
	// cout<<sum<<endl;	
	int carry = 0;
	for(int i=asize-1;i>=0;i-- )
	{
		int x = getnumeralC(a[i])+getnumeralC(b[i])+carry;
		if(x>14)
		{
			carry=1;
			x=x-14;
		}
		else
			carry=0;
		sum[i+1] = getnumeralI(x);
	}
	if(carry == 0)
		sum[0]='0';
	else
		sum[0] = '1';
}
int main()
{
	char a[]="A23A";
	char b[]="B12B";
	
	char * sum = add(a,b);
	cout <<sum<<endl;

	return 0;

}