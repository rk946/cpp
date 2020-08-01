#include<iostream>

using namespace std;

int main()
{
	int m=0,n=0;
	cout << "Enter number of rows";
	cin>>m;
	cout << "Enter number of columns";
	cin>>n;
	int val = 1;
	int a[m][n]={0};
	cout <<"Original array " <<endl;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			a[i][j]=val++;
			cout << a[i][j] << " ";
		}
		cout << endl;
	}


cout << "Wave print array " << endl;
	for(int j=0;j<n;j++)
	{
		if(j%2==0)
		{
			for(int i=0;i<m;i++)
			{
				cout << a[i][j] << " ";
			}
		}
		else
		{
						for(int i=m-1;i>=0;i--)
			{
				cout << a[i][j] << " ";
			}
		}
		cout << endl;
	}
	




	return 0;
}