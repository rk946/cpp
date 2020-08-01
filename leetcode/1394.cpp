#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


    int findLucky(vector<int>& arr) {
        int res=-1;
        sort(arr.begin(),arr.end());
        // for(int i=0;i<arr.size();i++)
//         {
//             if(arr[i] == (upper_bound(arr.begin(),arr.end(),arr[i])-lower_bound(arr.begin(),arr.end(),arr[i])))
//             {
//                 if(res<arr[i])
//                     res=arr[i];
//             }
            
            
            
//         }
            int size = arr.size();
            for(int i=0;i<size;i++)
            {
                int a=arr[i];
                if((i+a-1 < size) and arr[i+a-1]==a )
                {
                    if(arr[i+a]!=a)
                    {
                    	cout << arr[i+a-1] <<"  "<<arr[i+a] <<endl;
                    res=a;
                    
                }
                i=i+a-1;
                }
            }
        return res;
        
    }
int main()
{

	vector<int> a{14,14,19,11,6,4,16,17,3,7,7,5,15,12,3,20,1,13,5,20,1,12,10,2};
	cout <<findLucky(a);
	return 0;

}