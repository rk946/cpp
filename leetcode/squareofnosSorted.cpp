#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


vector<int> sortedSquares(vector<int>& A) {
        
        vector<int>::iterator ptr;
        for(ptr=A.begin();ptr<A.end();ptr++)
        {
        	int a=*ptr;
            *ptr=a*a;
        }
        sort(A.begin(),A.end());
        return A;
    } 


int main() 
{

	vector<int> a{1,2,-4,6,-9,3,-8,-2};
	vector<int> result = sortedSquares(a);
	vector<int> :: iterator ptr;
	for(ptr=result.begin();ptr<result.end();ptr++)
	{
		cout << *ptr <<",";
	}


	return 0;
}