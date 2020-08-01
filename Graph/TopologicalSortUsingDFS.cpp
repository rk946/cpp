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
		static map<T,bool> visited;
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

	void dfsHelper(T node, map<T,bool> &visited)
	{
		visited[node]=true;
		cout << node <<" ";
		for(T neighbor:adjList[node])
		{
			if(!visited[neighbor])
				dfsHelper(neighbor,visited);
		}
	}
	void dfs(T src)
	{
		map<T,bool> visited;
		dfsHelper(src,visited);
		int components = 1;	
		for(auto i:adjList)
		{
			if(!visited[i.first])
			{
				dfsHelper(i.first,visited);
				components++;
			}

		}

		cout << "Total components = "<<components<<endl;
	}

	void topSortHelper(T node, map<T,bool> &visited, list<T> &ordering)
	{
		visited[node] = true;
		for(auto neighbor:adjList[node])
		{
			if(!visited[neighbor])
			topSortHelper(neighbor,visited,ordering);
		}
		ordering.push_front(node);
	}
	void dfsTopSort()
	{
		map<T,bool> visited;
		list<T> ordering;
		for(auto i:adjList)
		{
			if(!visited[i.first])
			{
				T node = i.first;
				topSortHelper(node,visited,ordering);
			}
		}

		for(auto i:ordering)
			cout << i << " ";
		cout << endl; 
	}
};

int main()
{
	Graph<int> g;
	g.addEdge(1,2,false);
	g.addEdge(10,7,false);
	g.addEdge(10,8,false);
	g.addEdge(2,3,false);
	g.addEdge(2,9,false);
	g.addEdge(3,11,false);
	g.addEdge(9,11,false);
	g.addEdge(7,2,false);
	g.addEdge(8,11,false);
	// g.addEdge(,,false);
	g.dfsTopSort();
	return 0;
}