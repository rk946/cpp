#include<iostream>

using namespace std;
int n = 4;
int graph[10][10] = { { 0, 10, 15, 20 }, 
                      { 10, 0, 35, 25 }, 
                      { 15, 35, 0, 30 }, 
                      { 20, 25, 30, 0 } }; 


int dp[16][4];                     
int VISITED_ALL = (1<<n)-1;
int INT_MAX = 9999;
int count=0;
int tsp(int mask, int pos)
{
	count++;
	// cout << mask << " , " << pos <<endl;
	// cout<< VISITED_ALL <<endl;
	if(mask == VISITED_ALL)
	{
		// cout << "in base case";
		return graph[pos][0];
	}
 	// if(dp[mask][pos]!=-1)
		// return dp[mask][pos];
	int ans= INT_MAX;
	for(int city=0;city<n;city++)
	{
		// cout << "in for loop" <<endl;
		if((mask & (1<<city)) == 0)
		{
			// cout << "in if statement";
			int newAns = graph[pos][city]+tsp(mask|(1<<city),city);
			ans = min(ans,newAns);
		}
	}
	dp[mask][pos]=ans;
	return ans;
}                      

int main()
{
	for(int i=0;i<16;i++)
	{
		for(int j=0;j<4;j++)
		{
			dp[i][j]=-1;
		}
	}
	cout << tsp(1,0)<<endl;
	cout<<count;
	return 0;
}