#include<bits/stdc++.h>
using namespace std;

int main()
{
	string para;
	getline(cin,para);
	string word;
	getline(cin,word);
	int index= -1;
	int count=0;
	while(index!=-1)
	{/*
		if(index==0)
			index = para.find(word);
		else*/
		// count++;
			index = para.find(word,index+1);
		cout << index<<",";
		count++;
		
	}
	cout <<"count = " <<count<<endl;

	return 0;
}