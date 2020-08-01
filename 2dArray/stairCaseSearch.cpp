#include<iostream>

using namespace std;

void solve(int a[][100],int m,int n,int key)
{


	int i=0;int j=n-1;
	while(i<m and j>=0)
	{
		if(key<a[i][j])
			j--;
		else if(key>a[i][j])
			i++;
		else
		{
			cout<< "Key present in "<< i << " row "<< j <<" col"<<endl;
			break;
		}

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
	int key=0;
cout<<"Enter key to find"<<endl;
cin>>key;
solve(a,m,n,key);
	




	return 0;
}