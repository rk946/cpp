#include<iostream>
#include<queue>
using namespace std;
// template<typename T>

	    int noofsetbits(int a)
	    {
	    	// cout << a<<" ";
	        int res=0;
	        while(a)
	        {
	            a=a&(a-1);
	            res++;
	        }
	        // cout<<res <<endl;
	        return res;
	    }
	    int countPrimeSetBits(int L, int R) {
	        bool prime[21];
	        prime[2]=true;
	        prime[3]=true;
	        prime[5]=true;
	        prime[7]=true;
	        prime[11]=true;
	        prime[13]=true;
	        prime[17]=true;
	        prime[19]=true;
	        
	        int res=0;
	        for(int i=L;i<=R;i++)
	        {
	            if(prime[noofsetbits(i)])
	                res++;
	        }
	        return res;
	    }

int main()
{
	int L,R;
	cin>>L>>R;
	cout << countPrimeSetBits(L,R);
	return 0;
}