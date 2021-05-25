#include<bits/stdc++.h>

using namespace std;

int V=6;

int findMinimumWeight(vector<int>&weight, vector<bool> &setMST)
{
	
}

void printMST(int graph[V][V])
{
	vector<int> weight(V,INT_MAX);
	vector<bool> setMST(V,false);
	int parent[V];
	weight[0]=0;
	parent[0]=-1;

	int U = findMinimumWeight(weight, setMST);
	setMST[U]=true;
	for(int j=0;j<V-1;j++)
	{
		if(graph[U][j]!=0 and setMST[j]==false and graph[U][j]<weight[j])
		{
			weight[j]=graph[U][j];
			parent[j]=U;
		}
	}



}

int main()
{
	int graph[V][V]={{0,4,6,0,0,0},
						{4,0,6,3,4,0},
						{6,6,0,1,8,0},
						{0,3,1,0,2,3},
						{0,4,8,2,0,7},
						{0,0,0,3,7,0}};
	printMST(graph);

	return 0;
}