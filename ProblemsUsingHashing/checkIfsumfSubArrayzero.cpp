#include<iostream>
#include<set>
using namespace std;


bool check(int *a, int n)
{
	// cout << "hello";
	set<int> s;
	// int n = sizeof(a)/sizeof(a[0]);
	cout <<"size "<< n<<endl;
	int pre = a[0];
	if(pre == 0)
		return true;
	s.insert(pre);
	for(int i=1;i<n;i++)
	{
		cout << pre <<endl;
		pre +=a[i];
		if(pre ==0 or s.find(pre)!=s.end())
			return true;
		else
			s.insert(pre);
	}
	return false;

}

int main()
{
	int a[] = {6,-1,2,1,-1};
	int n = sizeof(a)/sizeof(a[0]);
	if(check(a,n))
			cout <<"subarray with zero sum present" <<endl;
	else
		cout<< "subarray with zero sum not present"<<endl;
	return 0;
}