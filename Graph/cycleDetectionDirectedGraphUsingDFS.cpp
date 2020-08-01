#include<iostream>
#include<map>
#include<list>
using namespace std;
template<typename T>
class Graph{
private:
	map<T,list<T>> adjList;
public:
	void addEdge(T u,T v, bool bidir = true)
	{
		adjList[u].push_back(v);
		if(bidir)
			adjList[v].push_back(u);
	}

	void print()
	{
		for(auto node : adjList)
		{
			cout << node.first<<"->";
			for(T neighbor:adjList[node.first])
				cout << neighbor;
			cout << endl;
		}
		cout << endl;
	}

	bool isCyclePresentHelper(T node, map<T,bool> &visited, map<T,bool> &instack)
	{
		visited[node] = true;
		instack[node] = true;
		for(T neighbor: adjList[node])
		{
			if(!visited[neighbor] and isCyclePresentHelper(neighbor,visited,instack) or instack[neighbor])
				return true;
		}
		instack[node]=false;
		return false;
	}
	bool isCyclePresent()
	{
		map<T,bool> visited;
		map<T,bool> instack;
		for(auto i:adjList)
		{
			return isCyclePresentHelper(i.first,visited,instack);

		}
	}

};
int main()
{
	Graph<int> g;
	g.addEdge(1,2,false);
	g.addEdge(1,3,false);
	g.addEdge(2,4,false);
	g.addEdge(3,4,false);
	g.addEdge(4,1,false);
	g.print();
	cout << endl;
	if(g.isCyclePresent())
		cout << "cycle is present "<<endl;
	else
		cout << "cycle is not present "<<endl;


	return 0;
}