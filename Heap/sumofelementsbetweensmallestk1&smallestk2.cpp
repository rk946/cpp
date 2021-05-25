    #include <bits/stdc++.h>  
      
    using namespace std;  

    int sum(int *arr, int n, int k1, int k2){
    	priority_queue<int> maxh;
    	for(int i=0;i<n;i++)
    	{
    		maxh.push(arr[i]);
    		if(maxh.size()>k2)
    		{
    			maxh.pop();
    		}
    	}
    	int sum1=0;
    	while(maxh.size()>k1)
    	{
    		sum1+=maxh.top();
    		maxh.pop();
    		cout << sum1<<endl;
    	}
    	return sum1;
    }
      
    int main()  
    {
    	int arr[]={1,3,12,5,15,11};
    	int n = sizeof(arr)/sizeof(int);
    	cout << sum(arr,n,2,4);
        return 0;
    }  