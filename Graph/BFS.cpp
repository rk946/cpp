#include<iostream>
#include<list>
#include<string>
#include<map>
#include<queue>
using namespace std;
template<typename T>
class Graph{

	map<T,list<T>> m;
public:
	void addEdge(T u, T v, bool biDir = true)
	{
		m[u].push_back(v);
		if(biDir)
			m[v].push_back(u);
	}

	void print()
	{
		for(auto a:m)
		{
			cout << a.first<<"->";
			for(auto b:a.second)
				cout<<b<<",";
			cout << endl;
		}
	}

	void BFS(T src)
	{
		queue<T> q;
		map<T,bool> visited;
		q.push(src);
		visited[src] = true;

		while(!q.empty())
		{
			T node = q.front();
			cout << node << " ";
			q.pop();

			for(auto i :m[node])
			{
				if(!visited[i])
				{
					visited[i]=true;
					q.push(i);
				}
			}

		}


	}
};


int main()
{
	Graph<string> g;
	g.addEdge("Modi","Trump");
	g.addEdge("Modi","Yogi");
	g.addEdge("Yogi","Trump",false);
	g.print();
	cout << endl;
	g.BFS("Modi");
	cout << endl;
	cout << endl;
	Graph<int> g2;
	g2.addEdge(0,1);
	g2.addEdge(2,3);
	g2.addEdge(4,5);
	g2.addEdge(2,4);
	g2.addEdge(1,5);
	g2.addEdge(1,3);
	g2.print();	
	cout <<endl;
	g2.BFS(0);
	return 0;
}