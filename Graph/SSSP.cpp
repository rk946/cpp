#include<iostream>
#include<queue>
#include<map>
#include<list>
#include<algorithm>
#include<climits>
using namespace std;

template<typename T>
class Graph {
	map<T,list<T>> adjList;
public:
	void addEdge(T u, T v, bool bidir = true )
	{
		adjList[u].push_back(v);
		if(bidir)
			adjList[v].push_back(u);
	}

	void BFS(T src)
	{
		queue<T> q;
		map<T,bool> visited;
		for(auto element:adjList)
		{
			visited[element.first] = false;
		}
		q.push(src);
		visited[src]=true;

		while(!q.empty())
		{
			T node = q.front();
			cout << node << " ";
			q.pop();
			for(auto neighbor:adjList[node])
			{
				if(!visited[neighbor])
				{
					q.push(neighbor);
					visited[neighbor] = true;
				}
			}
		}

	}

	void calculateSSSP(T src)
	{
		queue<T> q;
		map<T,int> dist;
		for(auto element : adjList)
			dist[element.first] = INT_MAX;
		q.push(src);
		dist[src] = 0;
		while(!q.empty())
		{
			T node = q.front();
			q.pop();

			for(auto neighbor : adjList[node])
			{
				if(dist[neighbor]==INT_MAX)
				{
					// cout <<"Pushing "<<neighbor<<endl;
					dist[neighbor] = dist[node]+1;
					q.push(neighbor);
				}
			}


		}

		for(auto d : dist)
			cout <<"Distance to "<<d.first <<" is = "<< d.second <<endl;
		cout <<endl;

	}


};
int main()
{
	Graph<int> g;
	g.addEdge(0,1);
	g.addEdge(2,3);
	g.addEdge(4,5);
	g.addEdge(2,4);
	g.addEdge(1,5);
	g.addEdge(1,3);
	g.BFS(0);
	cout << endl << "distances " <<endl;
	g.calculateSSSP(0);

	return 0;
}