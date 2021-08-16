#include<bits/stdc++.h>

using namespace std;

int solve(int egg, int floor)
{
	cout << egg <<" , "<<floor<<endl;
	if(floor==0 or floor==1)
		return floor;
	if(egg==1)
		return floor;
	int ans = INT_MAX;
	for(int k=1;k<=floor;k++)
	{
		int temp = 1+max(solve(egg-1,k-1),solve(egg,floor-k));
		ans = min(ans, temp);
	}
	return ans;
}


int main()
{
	int egg,floor;
	cin >>egg>>floor;
	cout << solve(egg, floor);
    return 0;
}