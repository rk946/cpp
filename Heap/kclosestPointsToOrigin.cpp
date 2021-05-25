    #include <bits/stdc++.h>  
      
    using namespace std;  

    vector<pair<int,int>> kClosest(vector<pair<int,int>>&points, int k)
    {
    	priority_queue<pair<int,pair<int,int>>> maxh;
    	int n = points.size();
    	for(int i=0;i<n;i++)
    	{
    		cout << i<<endl;
    		int first = points[i].first;
    		int second = points[i].second;
    		int dist = (first*first) + (second*second);
    		maxh.push(make_pair(dist,make_pair(first,second)));
    		if(maxh.size()>k)
    		{
    			maxh.pop();
    		}
    	}
    	vector<pair<int,int>> ans;
    	while(maxh.size()>0)
    	{
    		pair<int,pair<int,int>> p = maxh.top();
    		maxh.pop();
    		ans.push_back(p.second);
    	}
    	return ans;
    }
      
    int main()  
    {  
    	vector<pair<int,int>> points;
    	points.push_back(make_pair(1,3));
    	points.push_back(make_pair(-2,2));
    	points.push_back(make_pair(5,8));
    	points.push_back(make_pair(0,1));
    	int k=2;
    	vector<pair<int,int>> ans = kClosest(points,k);
    	int n = ans.size();
    	for(pair<int,int> i:ans)
    	{
    		cout << i.first << "  "<<i.second<<endl;
    	}
        return 0;
    }  