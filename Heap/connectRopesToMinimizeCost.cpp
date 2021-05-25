    #include <bits/stdc++.h>  
      
    using namespace std;  
      
      int minCost(int *arr,int n)
      {
      	// int n = sizeof(arr)/sizeof(int);
      	// cout << " n = "<<n<<endl;
      	priority_queue<int, vector<int>, greater<int>> minh;
      	int cost=0;
      	for(int i=0;i<n;i++)
            		minh.push(arr[i]);
            	// cout <<"size = "<<minh.size()<<endl;
      	while(minh.size()>1)
      	{
      		int rope1 = minh.top();
      		minh.pop();
      		int rope2 = minh.top();
      		minh.pop();
      		int rope3 = rope1+rope2;
      		minh.push(rope3);
      		// cout <<rope1<<" "<<rope2<<endl;
      		cost+=rope3;
      	}
      	return cost;
      }
    int main()  
    {  
    	int arr[]={1,2,3,4,5};
    	int n = sizeof(arr)/sizeof(int);
      	// cout << " n1 = "<<n<<endl;
    	cout << minCost(arr,n);
        return 0;
    }  