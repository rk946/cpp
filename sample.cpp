#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

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
