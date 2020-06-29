#include<iostream>
using namespace std;

bool possibility(int stalls[],int n, int cows, int min_sep)
{
	int count=1,lastCow=stalls[0];
	for(int i=0;i<n;i++)
	{
		if(stalls[i]-lastCow>=min_sep)
			{
				lastCow = stalls[i];
				count++;
			}
		if(count==cows)
			return true;
	}
	return false;
}


int main()
{
	int stalls[] = {1,2,4,8,9};
	int cows = 3;
	int n=5;

	int s=stalls[0];
	int e=stalls[n-1]-stalls[0];
	int ans = 0;
	while(s<=e)
	{	
		int mid = (s+e)/2;
		//false
		if(!possibility(stalls,n,cows,mid))
		{
			e=mid-1;
		}
		//true
		else
		{
			ans=mid;
			s=mid+1;
		}
	}

	cout << "ans = "<< ans << endl;


	

	return 0;
}