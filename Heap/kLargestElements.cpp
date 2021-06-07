    #include <bits/stdc++.h>  
      
    using namespace std;  
      
    void klargestElements(int *arr, int n, int k)
    {
      priority_queue<int, vector<int>, greater<int>> minH;
      for(int i=0;i<n;i++)
      {
        minH.push(arr[i]);
        if(minH.size()>k)
        {
          minH.pop();
        }

      }
      while(k>0)
      {
        cout << minH.top()<<" ";
        minH.pop();
        k--;
      }

    }
    int main()  
    { 
      int arr[]={7,10,4,3,20,15};
      int n = sizeof(arr)/sizeof(int);
      int k;
      cin >>k;
      cout <<"\n";
      klargestElements(arr,n,k); 

        return 0;
    }  