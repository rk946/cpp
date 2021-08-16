
#include<iostream>
<<<<<<< HEAD
=======
#include<vector>
#include<algorithm>
<<<<<<< HEAD
#include<bits/stdc++.h>
=======
#include<stack>
>>>>>>> c0efdc7a2927456c7c248ee165b6971d1135d8f8
>>>>>>> 597d5c5faf0835c781a7e68a253b1bfcacb8992b
using namespace std;
  

<<<<<<< HEAD
void print(int *x){
  cout << *x;

<<<<<<< HEAD
int main()
{
    unsigned int i = 1;
    char *c = (char*)&i;
    *c = 'a';
    cout << *c;


    char d='e';
    int *p1 = (int*)&d;
    cout << *p1;
}

// This code is contributed by rathbhupendra
=======
}
int main(void)
{ 
  const int* a;
  int b = 15;
  a=&b;
  int*temp = const_cast<int*>(a);
  print(temp);
=======
bool compare(pair<int,int> a, pair<int,int> b)
{
	return a.first>b.first;
}
int main()
{
	vector<pair<int,int>> a;
	for(int i=0;i<10;i++)
	{
		a.push_back(make_pair(10-i,i));
	}
	sort(a.begin(),a.end(),compare);
	cout << "Printing \n";
	for(int i=0;i<10;i++)
		cout << a[i].first <<" , " <<a[i].second << "\n";
	return 0;
>>>>>>> c0efdc7a2927456c7c248ee165b6971d1135d8f8

  return 0;
}
>>>>>>> 597d5c5faf0835c781a7e68a253b1bfcacb8992b
