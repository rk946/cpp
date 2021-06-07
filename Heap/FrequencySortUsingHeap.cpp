    #include <bits/stdc++.h>  
      
    using namespace std;  
      unordered_map<int,int> m;
     
    int main()  
    {  
    	int arr[] = {1,1,1,3,2,2,4};
    	int n = sizeof(arr)/sizeof(int);
    	for(int i=0;i<n;i++)
    	{
    		m[arr[i]]++;
    	}
    	priority_queue<pair<int,int>> maxh;
    	for( auto i:m)
    	{
    		maxh.push(make_pair(i.second,i.first));
    	}
    	int i=0;
    	while(maxh.size()>0)
    	{
    		pair<int,int> p = maxh.top();
    		maxh.pop();
    		int count = p.first;
    		while(count>0)
    		{
    			arr[i++]=p.second;
    		}
    	}
        return 0;
    }  