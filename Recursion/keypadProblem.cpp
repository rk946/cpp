#include<iostream>
#include<cstring>
using namespace std;


char keypad[][5]={"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};


void getSequence(char *in,char *out, int i, int j)
{
	
	if(in[i]=='\0')
	{
		out[j]='\0';
		cout << out <<endl;
		return;
	}	

	int digit = in[i]-'0';
	for(int k=0;k<strlen(keypad[digit]);k++)
	{
		out[j]=keypad[digit][k];
		getSequence(in,out,i+1,j+1);
	}


}




int main()
{

	char in[100];
	char out[100];

	cin>>in;

	cout <<endl;
	getSequence(in,out,0,0);





	return 0;
}