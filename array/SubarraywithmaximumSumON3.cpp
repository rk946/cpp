#include<iostream>
using namespace std;


int main()
{
	int n;
cout <<"Enter the number of elements in array";
cin >> n;
int a[n]={0};
for(int i=0;i<n;i++)
{
	cin>>a[i];
}
int csum[n]={0};
csum[0]=a[0];
for(int i=1;i<n;i++)
{
	csum[i]=csum[i-1]+a[i];
}
int currSum=0;int maxSum=0;
int firstIndex=0,lastIndex=0;
for(int i=0;i<n;i++)
{
	for(int j=i;j<n;j++)
	{
		for(int k=i;k<=j;k++)
			{
				
				currSum=currSum+a[k];
			}
		if(maxSum<currSum)
			{
				maxSum=currSum;
				firstIndex = i;
				lastIndex = j;
			}
			currSum=0;
	}
}
cout << "maxSum = " << maxSum << "\n";
for(int i=firstIndex;i<=lastIndex;i++)
{
	cout<< a[i] <<",";
}
cout << "\n";
return 0;
}