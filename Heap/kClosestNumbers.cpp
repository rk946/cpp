    #include <bits/stdc++.h>  
      
    using namespace std;  
    typedef pair<int,int> pi;
    vector<int> kClosestNumber(vector<int>&arr, int k, int x)
    {
    	int n = arr.size();
    	vector<int> ans;
    	priority_queue<pi> maxh;
    	for(int i=0;i<n;i++)
    	{
    		maxh.push(make_pair(abs(arr[i]-x), arr[i]));
    		if(maxh.size()>k)
    		{
    			maxh.pop();
    		}
    	}
    	while(maxh.size()>0)
    	{
    		pi temp = maxh.top();
    		maxh.pop();
    		ans.push_back(temp.second);
    	}
    	return ans;

    }
      
    int main()  
    {  
    	vector<int> arr = {6,7,8,9,10};
    	int x=6,k=3;
    	vector<int> ans = kClosestNumber(arr,k,x);
    	for(int i=0;i<ans.size();i++)
    	{
    		cout << ans[i] <<" ";
    	}
        return 0;
    }  