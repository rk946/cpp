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
int maxSum=a[0],currSum=a[0];
int firstIndex=0;
int lastIndex=0;
for(int i=1;i<n;i++)
{
	if(currSum<0)
		currSum=0;
	currSum=currSum+a[i];
	if(maxSum<currSum)
		maxSum=currSum;
}



cout << "maxSum = " << maxSum << "\n";
// for(int i=firstIndex;i<=lastIndex;i++)
// {
// 	cout<< a[i] <<",";
// }
cout << "\n";
return 0;
}