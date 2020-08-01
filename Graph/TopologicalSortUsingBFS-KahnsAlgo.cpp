#include<iostream>
#include<map>
#include<queue>
#include<list>
#include<climits>
#include<string>
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

	void bfsTopSort()
	{
		queue<T> q;
		map<T,int> indegree;
		for(auto entry:adjList)
		{
			T node = entry.first;
			indegree[node] = 0;
		}

		for(auto entry:adjList)
		{
			for(T v:adjList[entry.first])
			{
				indegree[v]++;
			}
		}
		for(auto i:adjList)
		{
			T node = i.first;
			if(indegree[node]==0)
				q.push(node);
		}

		while(!q.empty())
		{
			T node = q.front();
			cout << node << " ";
			q.pop();
			for(T neighbor:adjList[node])
			{
				indegree[neighbor]--;
				if(indegree[neighbor]==0)
					q.push(neighbor);
			}
		}


	}
};

int main()
{

	Graph<string> g;
	g.addEdge("English","PL",false);
	g.addEdge("Math","PL",false);	
	g.addEdge("PL","HTML",false);	
	g.addEdge("PL","Python",false);	
	g.addEdge("PL","Java",false);	
	g.addEdge("PL","JS",false);	
	g.addEdge("Python","Web-Dev",false);	
	g.addEdge("HTML","CSS",false);	
	g.addEdge("CSS","JS",false);	
	g.addEdge("JS","Web-Dev",false);	
	g.addEdge("Java","Web-Dev",false);	
	g.addEdge("Python","Web-Dev",false);	
	// g.addEdge("","",false);	
	// g.addEdge("","",false);	
	g.dfsTopSort();
	cout <<endl << "bfsTopSort"<<endl;
	g.bfsTopSort();
	return 0;
}