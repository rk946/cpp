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
	void addEdge(T u, T v, bool biDir = false)
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

	bool isBipartite(int s)
	{
		int n = m.size();
		int color[n];
		for(int i=0;i<n;i++)
			color[i]=-1;

		cout << "Print color"<<endl;
		for(int i=0;i<n;i++)
		{
			cout << color[i]<<" ";
		}
		cout << endl;
		queue<int> q;
		q.push(s);
		color[s]=0;
		while(!q.empty())
		{
			int temp = q.front();
			q.pop();
			for(int v:m[temp])
			{
				if(color[v]==-1)
				{
					color[v] = 1-color[temp];
					q.push(v);
				}
				else if(color[v]==color[temp])
				{
					return false;
				}
				
			}
		}
		return true;


	}


};


int main()
{


	Graph<int> g2;
	g2.addEdge(0,1);
	g2.addEdge(2,0);
	g2.addEdge(1,3);
	g2.addEdge(2,3);
	// g2.addEdge(4,5);
	// g2.addEdge(2,4);
	// g2.addEdge(1,5);
	// g2.addEdge(1,3);
	g2.print();	
	cout <<endl;
	g2.BFS(0);

	if(g2.isBipartite(2))
	{
		cout << "Yes it isBipartite"<<endl;
	}
	else
		cout << "No it is not Bipartite"<<endl;

	return 0;
}