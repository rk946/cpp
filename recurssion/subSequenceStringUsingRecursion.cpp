#include<iostream>

using namespace std;

void subSequence(char *in, char *out, int i, int j)
{
	if(in[i]=='\0')
	{
		out[j]='\0';
		cout << out << ",";
		return;
	}
	subSequence(in,out,i+1,j);
	out[j]=in[i];
	subSequence(in,out,i+1,j+1);


}


int main(){
	char in[100];
	cin>>in;
	char out[100];

	subSequence(in,out,0,0);

	return 0;
}