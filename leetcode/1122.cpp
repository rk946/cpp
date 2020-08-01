#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> res;
        sort(arr1.begin(),arr1.end());
        for(int i=0;i<arr2.size();i++)
        {
            int k = upper_bound(arr1.begin(),arr1.end(),arr2[i]) - lower_bound(arr1.begin(),arr1.end(),arr2[i]);
            cout << k << " "<<arr2[i]<<endl;
            for(int l=0;l<k;l++)
                res.push_back(arr2[i]);
        }
        for(int i=0;i<arr1.size();i++)
        {
        	if(find(arr2.begin(),arr2.end(),arr1[i])==arr2.end())
        		res.push_back(arr1[i]);
        }
        return res;
    }


int main()
{
	vector<int> arr1 {2,3,1,3,2,4,6,7,9,2,19}, arr2 {2,1,4,3,9,6};
	vector<int> arr3(arr1.size());

	arr3 = relativeSortArray(arr1,arr2);

	for(auto it=arr3.begin();it!=arr3.end();it++)
	{
		cout << (*it)<<",";
	}
	cout<<endl;
	return 0;

}