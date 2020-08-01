#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
using namespace std;
	    int findones(int a)
    {
        int res=0;
        while(a>0)
        {
            if(a&1)
                res++;
           a= a>>1;
        }
        return res;
    }
    bool compare(int a, int b)
    {
        return findones(a)<findones(b);
    }
class Solution {
public:



    vector<int> sortByBits(vector<int>& arr) {
       sort(arr.begin(),arr.end(),compare);
        
        return arr;
    }
};
int main()
{
	vector<int> a{0,1,2,3,4,5,6,7,8};
	vector<int> b = a;
	Solution s;
	b = s.sortByBits(a);
	for(int i=0;i<b.size();i++)
		cout << b[i]<< " ";
	cout << endl;

	return 0;

}