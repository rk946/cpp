#include<iostream>

using namespace std;

void solve(char a[][100],int m,int n)
{

}


int main()
{

	// char a[3][5];
	char a[100][100];
	int 
	// ={{'.','.','*','.'},{'.','#','.','.'},{'*','*','.','.'},{'.','#','*','*'}};
	int m=sizeof(a)/sizeof(a[0]);
	int n=sizeof(a[0])/sizeof(a[0][0]);
	cout<<"Number of rows = "<< m;
	cout << "Number of col = "<< n;
	cout <<"Original array " <<endl;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			// a[i][j]=val++;
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

solve(a,m,n);
	




	return 0;
}