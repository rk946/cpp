#include<iostream>
using namespace std;

bool check(int a[], int m, int n, int maxPages,int totalPages)
{
	bool result = false;
	int ScumPages = 0;
	int cumPages = 0;
	int count = 1;
	for(int i=0;i<n;i++)
	{	
		ScumPages = ScumPages+a[i];
		// cumPages = cumPages+a[i];
		if(ScumPages>maxPages)
		{
			ScumPages = a[i];
			// cumPages = cumPages-a[i];
			count++;

		}
		if(count>m)
			return false;
	}

return true;

}


int main()
{

	int m=2;//Students
	int n=4; //Books
	int a[]={10,20,30,40};//number of pages in each book
	int totalPages = 0;
	for(int i=0;i<n;i++)
		totalPages+=a[i];
	int s=a[n-1];
	int e=totalPages;
	
	int ans = 0;
	while(s<=e)
	{
		cout << "start = " << s << "  end  = "<<e <<endl;
		int mid = (s+e) >>1;
		//true
		if(check(a,m,n,mid,totalPages))
		{
			ans=mid;
			e=mid-1;
		}
		//false
		else{
			s=mid+1;
		}

	}

	cout << ans;

	return 0;
}