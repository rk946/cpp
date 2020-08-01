#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int main()
{
	char s[100] = "Today is a rainy day";

	char *p = strtok(s," ");
	cout << p <<endl;
	cout << p++ << endl;
	return 0;
}