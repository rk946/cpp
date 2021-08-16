
#include<bits/stdc++.h>
using namespace std;
  

  
int main()
{ 
  vector<int> arr={1, 8, 4, 6, 3, 7, 2};
  int n = arr.size();
  vector<int> flag(n,0);
  for(int element : arr){
    if(element<n)
      flag[element-1]=-1;
  }
  for(int i=0;i<n;i++){
    if(flag[i]!=-1){
      cout << i+1 <<endl;
      // break;
    }
  }
  cout << "finished"<<endl;
  return 0;
}