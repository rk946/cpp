#include<bits/stdc++.h>
using namespace std;

int largestSubArray(int *arr, int n, int sum)
{
	int i=0,j=0;
	int currsum=0;
	int maxLength=0;
	while(j<n)
	{
		currsum += arr[j];
		if(currsum==sum)
			maxLength = max(maxLength, j-i+1);
		else if(currsum > sum)
		{
			currsum-=arr[i];
			i++;
		}
		j++;

	}
	return maxLength;
}


void printlargestSubArray(int *arr, int n, int sum)
{
	int i=0,j=0;
	int currsum=0;
	int maxLength=0;
	int left=0,right=0;
	while(j<n)
	{
		currsum += arr[j];
		if(currsum==sum)
		{
			if(maxLength<(j-i+1))
			{
				maxLength = j-i+1;
				left=i;
				right=j;
			}
			// maxLength = max(maxLength, j-i+1);
		}
		else if(currsum > sum)
		{
			currsum-=arr[i];
			i++;
		}
		j++;

	}
	cout <<"left = "<<left<<" right "<<right<<endl;
	for(int i=left;i<=right;i++)
		cout<<arr[i]<<" ";

	
}
int main()
{
	// int arr[]={4,1,1,1,2,3,5};
	int arr[]={-5,8,-14,2,4,12};
	int n = sizeof(arr)/sizeof(int);
	int sum;
	cin>>sum;
	cout << largestSubArray(arr,n,sum)<<endl;

	printlargestSubArray(arr,n,sum);
	return 0;
}

