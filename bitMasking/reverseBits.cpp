#include<iostream>
using namespace std;

    uint32_t reverseBits(uint32_t n) {
     uint32_t res = 0;
        int count = 1;
       for(int i=0;i<32;i++)
        {
          count++;
              res = res << 1;
          if(n&1)
          {
              res = res | 1;
          }
          
            n= n>>1;
        }
        cout << "count = "<<count<<endl;
        return res;
    }


int main()
{
	uint32_t i=7;
  cin>>i;
	cout << reverseBits(i);
}