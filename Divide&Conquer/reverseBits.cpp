#include<iostream>
using namespace std;

    int reverseBits(int n) {
     int res = 0;
        
        while(n>0)
        {
              res = res << 1;
          if(n&1)
          {
              res = res | 1;
          }
          
            n= n>>1;
        }
        
        return res;
    }


int main()
{
	int i=6;
	cout << reverseBits(i);
}