#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
 	int size1= nums1.size();
 	int size2= nums2.size();
 	sort(nums2.begin(),nums2.end());
 	vector<int> v3;
 	for(int i=0;i<size1;i++)
 	{
 		if(binary_search(nums2.begin(),nums2.end(),nums1[i]))
 			{
 				if(find(v3.begin(),v3.end(),nums1[i])==v3.end())
 				v3.push_back(nums1[i]);
 			}
 	}
 	return v3;
        
    }
int main()
{
	vector<int> v1{4,9,5,4}, v2{9,4,9,8,4};

	vector<int> v3= intersection(v1,v2);
	for(int i=0;i<v3.size();i++)
		cout << v3[i]<< " ";

	return 0;

}