#include<iostream>
#include<vector>
using namespace std;


int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int i=0,j=0;
        int count=0;
        for(;i<arr1.size();i++)
        {
        	// cout <<"first loop"<<endl;
            for(int j=0;j<arr2.size();j++)
            {
                //compare two elements and check if difference is less than +ve 'd' and greater than -ve 'd'
                int e = abs(arr1[i]-arr2[j]);
                bool a = (e<=d) and (e!=0);
                // cout << arr1[i]<<" " << arr2[j]<< " "<<a<<endl;
                //if(false)
                if(a)
                    count++;
            }
        }
        return count;
    }


int main()
{
	// [2,1,100,3] [-5,-2,10,-3,7] 6
// vector<int> arr1{2,1,100,3}, arr2 {-5,-2,10,-3,7};
// int d = 6;

vector<int> arr1{1,4,2,3}, arr2 {-4,-3,6,10,20,30};
int d = 3;
cout << findTheDistanceValue(arr1,arr2,d) <<endl;
	return 0;
}