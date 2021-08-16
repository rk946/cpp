#include<iostream>
#include<cstring>
using namespace std;

int ans=0;

bool isSafe(int board[][10], int i, int j, int n)
{
	for(int k=0;k<i;k++)
	{
		if(board[k][j]==1)
			return false;

	}

	int x=i;
	int y=j;
	while(x>=0 and y>=0)
	{
		if(board[x][y]==1)
			return false;
		x--;
		y--;
	}

	x=i;
	y=j;
	while(x>=0 and y<n)
	{
		if(board[x][y]==1)
			return false;
		x--;
		y++;
	}
	return true;
}


bool solve(int board[][10], int row, int n)
{
	if(row==n)
	{
		ans++;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(board[i][j]==1)
					cout << "Q ";
				else
					cout<<"_ ";
			}
			cout << endl;
		}
		cout << endl;
		// return;
		return false;
	}

	for(int j=0;j<n;j++)
	{
		
		if(isSafe(board,row,j,n))
		{
			board[row][j]=1;
		
			
		bool nextQueen = solve(board,row+1,n);
		if(nextQueen)
			return true;
		else
			board[row][j]=0;
	}
	}
	return false;
}


int main()
{
	int n;
	cin>>n;
	int board[10][10]={0};
	solve(board,0,n);
	cout << "Possible configuration : "<<ans<<endl;
	return 0;
}