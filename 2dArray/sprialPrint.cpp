#include<iostream>

using namespace std;

void spirtalPrint(int a[][1000],int m,int n)
{
	int startRow =0,startCol = 0;
	int endRow = m-1, endCol = n-1;
	while(startRow<=endRow and startCol<=endCol)
	{
		for(int i=startCol;i<=endCol;i++)
		{
			cout << a[startRow][i]<< "";
		}
		startRow++;
		for(int i=startRow;i<=endRow;i++)
		{
			cout<<a[i][endCol]<<" ";
		}
		endCol--;
		if(startRow<endRow)
		{
		for(int i=endCol;i>=startCol;i--)
			cout<<a[endRow][i]<<" ";
		endRow--;
		}

		if(startCol<endCol)
		{

			for(int i=endRow;i>=startRow;i--)
			cout<<a[i][startCol]<<" ";
		startCol++;
	}
	}
}


int main()
{
	int m=0,n=0;
	cout << "Enter number of rows";
	cin>>m;
	cout << "Enter number of columns";
	cin>>n;
	int val = 1;startCol
	int a[1000][1000]={0};
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

spirtalPrint(a,m,n);
	




	return 0;
}