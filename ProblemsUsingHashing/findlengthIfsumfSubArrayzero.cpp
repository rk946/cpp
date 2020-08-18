#include<iostream>
#include<unordered_map>
#include<climits>
using namespace std;


int check(int *a, int n)
{
	int dist = 0;
	unordered_map<int,int> m;
	int pre = 0;
	for(int i=0;i<n;i++)
	{
		pre +=a[i];
		if(a[i]==0 and dist==0) 
			dist=1;
		if(pre == 0)
			dist = i+1;
		if(m.find(pre)!=m.end())
			dist = max(dist,i-m[pre]);
		else
			m[pre] = i;
	}
	return dist;

}

int main()
{
	int a[] = {-1,1,2,5,-5,-2};
	int n = sizeof(a)/sizeof(a[0]);
	cout << "length = "<<check(a,n);
	return 0;
}