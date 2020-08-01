#include<iostream>
#include<list>
#include<string>
#include<map>
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
};

int main()
{
	Graph<string> g;
	g.addEdge("Modi","Trump");
	g.addEdge("Modi","Yogi");
	g.addEdge("Yogi","Trump",false);
	g.print();

	cout << endl;

	Graph<int> g2;
	g2.addEdge(1,2);
	g2.addEdge(0,2);
	// g2.print();
	g2.addEdge(2,3);
	g2.addEdge(3,10);
	g2.addEdge(5,10);
	g2.print();	
	return 0;
}