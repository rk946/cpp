    #include <iostream>  
    #include <set> 
    #include<bits/stdc++.h> 
      
    using namespace std;  
    long long M=1000000009;
  long long expo(long long base, int power){
  	cout << base << " "<<power <<endl;
        if(power==1)
            return base;
        if(power&1)
            return base * expo((base*base)%M, power/2)%M;
        else{
            return expo((base*base)%M, power/2)%M;
        }
    }
    
    int main()  
    {
    	long long a = expo(20,2);
    	cout << a;

    	// a^b mod c


      	// cout << (3355443200000000%1000000009 * 100000000000000000%1000000009)%1000000009
        return 0;
    }  
