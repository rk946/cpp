#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;


 
int reverse(int x)
{
	cout << "reverse called"<<endl;
    int a=0;
    while(x)
    {
        a = (a*10) + (x%10);
        x/=10;
    }
    return a;
}
 

int helper(int n, int u, int x, int*dp)
 {
 	cout <<"u = " <<u << endl;
    
     if(u>n or u<=0)
        return INT_MAX;
    // cout <<"111111"<<endl;
    if(u==x)
    {
    	cout <<"matched u = "<<u<<endl;
        return 0;
    }
// cout <<"2222222"<<endl;
    if(dp[u]!=0)
    {
    	cout << "dp val = "<<dp[u]<<endl;
    	return dp[u];
    }
    // cout <<"3333333"<<endl;
    int val = INT_MAX;
    
    int op[6];
    op[1] = helper(n,u+1,x,dp);
    op[2] = helper(n,u-1,x,dp);
    op[3] = helper(n,u*2,x,dp);
    op[4] = helper(n,u/2,x,dp);
    op[5] = helper(n,reverse(u),x,dp);
    
    for(int i=1;i<6;i++)
    {
        if(op[i]!=INT_MAX)
        {
        	cout << "op"<<i<<" = "<<op[i]<<endl;
                op[i]+=1;
                val = min(val,op[i]);
        }
        
    }
    cout <<"returning from helper"<<endl;
    return dp[u]=val;
    
 }

int solve(int n, int x) {
   	int dp[n+1]={1};
   	cout <<"dp[1] = "<<dp[1]<<endl;
    int temp =  helper(n,1,x,dp);
    cout << "sdgbedfzfgbzdzfg = "<<temp <<endl;
    return temp;
    

}

int main()
{

	// cout << reverse(1);

	int n,x;
	cin>>n>>x;
	cout << "n = "<<n<<" x= "<<x<<endl;
	int steps = solve(n,x);
	cout << "steps = "<<steps<<endl;

	return 0;

}