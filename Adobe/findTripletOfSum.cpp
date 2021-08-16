
#include<bits/stdc++.h>
using namespace std;
  

  
int main(void)
{ 
  vector<int> arr={12, 3, 4, 1, 6, 9};
  int sum = 24;
  sort(arr.begin(), arr.end());
  int n = arr.size();
  for(int i=0;i<n;i++){
      int start=i+1;
      int end = n-1;
      while(start<end){
        int temp = arr[start]+arr[end]+arr[i] ;
        if(temp== sum){
          cout << arr[start] <<" "<<arr[end] << " "<<arr[i] <<endl;
          break;

          }
        else if(temp<sum)
          start++;
        else
          end--;
      }
  }

  return 0;
}