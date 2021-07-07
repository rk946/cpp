#include <iostream>  
#include <set> 
#include<bits/stdc++.h> 
      
using namespace std;  

void buildST(vector<int>&arr, int s, int e, vector<int>&tree, int i){
    if(s==e){
        tree[i]=arr[s];
        return;
    }
    int mid = (s+e)/2;
    buildST(arr,s,mid,tree,2*i);
    buildST(arr,mid+1,e,tree,2*i+1);
    tree[i] = min(tree[2*i] , tree[2*i+1]);
    return;
}

int query(vector<int>&tree, int ss, int se, int qs, int qe, int index){
    //Complete Overlap
    if(qs<=ss and qe>=se)
        return tree[index];
    //No overlap
    if(qe<ss or qs>se)
        return INT_MAX;
    int mid = (ss+se)/2;
    int left = query(tree, ss, mid, qs, qe, 2*index);
    int right = query(tree, mid+1, se, qs, qe, 2*index+1);
    return min(left,right);
}
 
void update(vector<int>&tree, int ss, int se, int i, int increment, int index){
    // 3 cases
    //No overlap 
    if(i <ss or i > se)
        return;
    //complete overlap
    if(ss==se){
        tree[index]+=increment;
        return;
    }
    //Partial overlap
    //call on left and right
    int mid = (ss+se)/2;
    update(tree,ss,mid,i,increment,2*index);
    update(tree,mid+1,se,i,increment,2*index+1);
    tree[index] = min(tree[2*index], tree[2*index+1]);
    return;
}

int main()  
{
    vector<int> arr={1,3,2,-5,6,4};
    int n = arr.size();
    vector<int> tree(4*n+1, 0);        
    buildST(arr,0,n-1,tree,1);
    for(int i:arr)
        cout << i <<" ";
    cout<< endl;
    int left, right;
    cin>>left>>right;
    cout << query(tree,0,n-1,left,right,1);

    //update
    int index,inc;
    cin >> index >> inc;
    update(tree,0,n-1,index,inc,1);
    cout << query(tree,0,n-1,left,right,1);

    return 0;
}