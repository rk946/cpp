#include<iostream>

using namespace std;

void solve(int a[][100],int m,int n)
{
	//reverse each row 
	
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n/2;j++)
		{
			swap(a[i][j],a[i][n-1-j]);
		}
	}

	//reverse upper triangle
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i<j)
				swap(a[i][j],a[j][i]);
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


}


int main()
{

	// char a[3][5];
	int a[100][100]={0};
	
	// ={{'.','.','*','.'},{'.','#','.','.'},{'*','*','.','.'},{'.','#','*','*'}};
	// int m=sizeof(a)/sizeof(a[0]);
	// int n=sizeof(a[0])/sizeof(a[0][0]);
	// cout<<"Number of rows = "<< m;
	// cout << "Number of col = "<< n;
	cout<<"Enter number of rows = "<<endl;
	int m=0;
	cin>>m;
	cout<<"Enter number of col = "<<endl;
	int n=0;
	cin>>n;
	cout <<"Original array " <<endl;
	int val = 1;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			a[i][j]=val++;
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

solve(a,m,n);
	




	return 0;
}