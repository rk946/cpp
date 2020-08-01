#include<iostream>
using namespace std;


void solve(int a[][1000],int m,int n)
{
	cout<<"solving"<<endl;
int currSum=0;
	for(int ti=0;ti<m;ti++)
	{
		cout<<ti<<endl;
		for(int tj=0;tj<n;tj++)
		{
			for(int bi=ti;bi<m;bi++)
			{
				for(int bj=tj;bj<n;bj++)
				{
					
					for(int i=ti;i<=bi;i++)
					{
						for(int j=tj;j<=bj;j++)
						{
							currSum = currSum+a[i][j];
						}	
					}
				}

			}
		}
	}
	cout << "sum = "+currSum;

}

int main()
{
	int a[1000][1000];
	int m=0,n=0;
	cout<<"Rows = ";
	cin>>m;
	cout<<"col = ";
	cin>>n;
	int val=1;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			a[i][j]=val;
		}
	}
for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			// a[j][i]=a[i][j];
			cout << a[i][j] << " ";
		}
		cout <<endl;
	}
	solve(a,m,n);
	return 0;
}