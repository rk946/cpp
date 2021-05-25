#include <bits/stdc++.h>  
      
using namespace std;  

int kthSmallest(int arr[], int n, int k)
{
    priority_queue<int> maxh;
    for(int i=0;i<n;i++)
    {
        maxh.push(arr[i]);
        if(maxh.size()>k)
        {
            maxh.pop();
        }

    }
    return maxh.top();
}

int main()  
 {  
    int arr[]={7,10,4,3,20,15};
    int n = sizeof(arr)/sizeof(int);
    int k;
    cin>>k;
    cout << kthSmallest(arr,n,k);



        return 0;
}  