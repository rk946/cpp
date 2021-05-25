    #include <bits/stdc++.h>  
      
    using namespace std;  
      unordered_map<int,int> m;
      bool compare(int a, int b)
      {
      	return m[a]>m[b];
      }
    int main()  
    {  
    	int arr[] = {1,1,1,3,2,2,4};
    	int n = sizeof(arr)/sizeof(int);
    	for(int i=0;i<n;i++)
    	{
    		m[arr[i]]++;
    	}
    	sort(arr,arr+n,compare);
    	for(int i=0;i<n;i++)
    		cout << arr[i] <<" ";
        return 0;
    }  