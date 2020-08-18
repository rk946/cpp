#include<iostream>
#include<unordered_map>
#include<climits>
using namespace std;


int check(int *a, int n, int k)
{
	int dist = 0;
	unordered_map<int,int> m;
	int pre = 0;
	for(int i=0;i<n;i++)
	{
		pre +=a[i];
		if(a[i]==k and dist==0) 
			dist=1;
		if(pre == k)
			dist = i+1;
		if(m.find(pre-k)!=m.end())
			dist = max(dist,i-m[pre-k]);
		else
			m[pre-k] = i;
	}
	return dist;

}

int main()
{
	int a[] = {-1,1,2,5,-5,-2};
	int n = sizeof(a)/sizeof(a[0]);
	cout << "length = "<<check(a,n,7);
	return 0;
}