#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

unordered_map<int,int> um;
bool compare(int a, int b)
{
    
    if(um.count(a)==0 and um.count(b)==0)
        return a<b;
    else if(um.count(a)==0)
        return false;
    else if(um.count(b)==0)
        return true;
    else
        return um[a]<um[b];
        
    
    
        
    
}
 vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n = arr2.size();
        for(int i=0;i<n;i++)
        {
            um[arr2[i]]=i;
        }
        sort(arr1.begin(),arr1.end(),compare);
        return arr1;
}
 
int main()
{
    vector<int> arr1={26,21,11,20,50,34,1,18};
    vector<int> arr2={21,11,26,20};

    vector<int> arr3 = relativeSortArray(arr1,arr2);
    for(int i=0;i<arr3.size();i++)
        cout << arr3[i] <<" ";
    cout <<endl;


	return 0;

}