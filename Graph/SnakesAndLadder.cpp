#include<iostream>
#include<map>
#include<queue>
#include<list>
#include<climits>
using namespace std;
template<typename T>
class Graph{
	map<T,list<T>> adjList;
public:
	void addEdge(T u, T v, bool bidir = true)
	{
		adjList[u].push_back(v);
		if(bidir)
			adjList[v].push_back(u);
	}

	void BFS(T src)
	{
		queue<T> q;
		map<T,bool> visited;
		for(auto entry:adjList)
		{
			visited[entry.first]=false;
		}
		q.push(src);
		visited[src]  = true;
		while(!q.empty())
		{
			T node = q.front();
			cout << node << " ";
			q.pop();
			for(auto neighbors:adjList[node])
			{
				if(!visited[neighbors])
				{
					q.push(neighbors);
					visited[neighbors]=true;
				}
			}
		}
	}

	void calculateSSSP(T src)
	{
		queue<T> q;
		map<T,int> dist;
		for(auto entry:adjList)
			dist[entry.first] = INT_MAX;
		q.push(src);
		dist[src]=0;
		while(!q.empty())
		{
			T node = q.front();
			cout  << node<<" ";
			q.pop();
			for(auto neighbor : adjList[node])
			{
				if(dist[neighbor]==INT_MAX)
				{
					dist[neighbor] = dist[node]+1; 
					q.push(neighbor);
				}
			}
		}
		cout << endl;
		for(auto d : dist)
			cout << "Distance to "<< d.first << " from "<<src <<" = "<<d.second<<endl;
	}

	int minNoRolls(T src, T dest)
	{
		queue<T> q;
		map<T,int> dist;
		map<T,T> parent;
		for(auto entry:adjList)
		{
			dist[entry.first] = INT_MAX;
		}
		q.push(src);
		dist[src]=0;
		while(!q.empty())
		{
			T node = q.front();
			// cout << node << " ";
			q.pop();

			for(auto neighbor: adjList[node])
			{
				if(dist[neighbor]==INT_MAX)
				{
					dist[neighbor] = dist[node]+1;
					q.push(neighbor);
					parent[neighbor] = node;
				}
			}

		}
		cout << endl;
		T temp=dest;
		while(temp!=src)
		{
			cout << temp << "<-";
			temp = parent[temp];
		}
		cout << src<<endl;


		// for(auto it:adjList)
		// 	// cout << "Distance of "<<it.first<< " = "<<it.second<<endl;
		// 	cout << "Distance = "<< dist[it.first]<<endl;
		int ret = dist[dest];
		cout << "Shortest distance  = "<<ret<<endl;
		return ret;
	}
};

int main()
{
	Graph<int> g;
	int board[50]={0};
	board[2]=13;
	board[5]=2;
	board[9]=18;
	board[18]=11;	
	board[17]=-13;
	board[20]=-14;
	board[24]=-8;
	board[25]=-10;
	board[32]=-2;
	board[34]=-22;

	for(int u=0;u<=36;u++)
	{
		for(int dice=1;dice<=6;dice++)
		{
			int v = u+dice+board[u+dice];
			g.addEdge(u,v,false);
		}
	}
	// g.BFS(0);
	// cout << endl;
	// g.calculateSSSP(0);
	// cout << endl;
	cout <<"Min Distance = "<< g.minNoRolls(0,36)<<endl;
	cout << "Ends"<<endl;
	return 0;
}