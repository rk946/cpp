#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

  int countPrimes(int n) {
        if(n==0 or n==1)
            return 0;
        bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= n; p++)
    {
        // If prime[p] is not changed,
        // then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples
            // of p greater than or
            // equal to the square of it
            // numbers which are multiple
            // of p and are less than p^2
            // are already been marked.
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    int count =0;
     for (int p = 2; p <= n; p++)
        if (prime[p])
            count++;
        return count;
        
    }
 
int main()
{
    cout << countPrimes(5000000);

	return 0;

}