#include<iostream>
#include<vector>
#include<climits>

using namespace std;


    int minHelper(vector<int>& days, vector<int>& costs,int i,int n,vector<int> &cost) {
        cout << "calling "<<i<<endl;
        if(i>n)
            return 0;
        if(cost[i]!=0)
            return cost[i];
        int res=INT_MAX;
        int case1 = costs[0]+minHelper(days,costs,i+1,n);
        
        auto index2 = lower_bound(days.begin(),days.end(),days[i]+7);
        int case2 = costs[1]+minHelper(days,costs,index2-days.begin(),n);
        
        auto index3 = lower_bound(days.begin(),days.end(),days[i]+30);
        int case3 = costs[2]+minHelper(days,costs,index3-days.begin(),n);
        
        res=min(res,case1);
        res=min(res,case2);
        res=min(res,case3);
        
        return res;
        
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> cost(days.size(),0);
    
        return minHelper(days,costs,0,days.size(),cost);
    }

int main()
{
	vector<int> days={1,4,6,7,8,20};
	vector<int> costs={2,7,15};
	cout << mincostTickets(days,costs);
	return 0;
}