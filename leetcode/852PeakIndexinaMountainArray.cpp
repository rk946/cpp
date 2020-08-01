#include<iostream>
#include<vector>
using namespace std;

  int peakIndexInMountainArray(vector<int>& A) {
       int lo=0;
       int high=A.size();

       while(lo<high)
       {
       		int mid = lo+(lo+high)/2;
       		if(A[mid]<A[mid-1])
       			high=mid;
       		else if(A[mid]<A[mid+1])
       			lo=mid+1;
       		else
       			return mid;


       }
        
    }

int main()
{
 
	vector<int> a{0,2,1,0};
	cout << peakIndexInMountainArray(a);
	return 0;
}