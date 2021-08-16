#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

void wiggleSort(int *arr, int n)
{
    for(int i=1;i<n;i+=2)
    {
        if(arr[i]<arr[i-1])
            swap(arr[i],arr[i-1]);
        if(arr[i]<arr[i+1])
            swap(arr[i],arr[i+1]);
    }

    for(int i=0;i<n;i++)
    {
        cout << arr[i] <<" , ";
    }
    cout << endl;

}

int main()
{
    int arr[]={3,5,2,1,6,4,7};
     int n = sizeof(arr)/sizeof(arr[0]);
     cout << "size = "<<n<<endl;
    wiggleSort(arr,n);

}