#include<iostream>
#include<unordered_map>
#include<map>
#include<list>
#include<climits>
#include<set>

using namespace std;
template <typename T>
class Graph{
	unordered_map<T,list<pair<T,int>>> m;
public:
	void addEdge(T u, T v, int dist, bool bidir=true)
	{
		m[u].push_back(make_pair(v,dist));
		if(bidir)
			m[v].push_back(make_pair(u,dist));
	}

	void print()
	{
		for(auto i:m)
		{
			cout << i.first << "->";
			for(auto p:m[i.first])
			{
				cout << "{"<<p.first <<","<<p.second<<"},";
			}
			cout << endl;
		}
	}

	void dsssp(T src, T dest)
	{
		unordered_map<T,int> dist;
		unordered_map<T,T> parent;
		for(auto i:m)
		{
			dist[i.first]=INT_MAX;
		}
		dist[src]=0;
		parent[src]=src;
		set<pair<int,T>> s;
		s.insert(make_pair(0,src));

		while(!s.empty())
		{
			auto a = *(s.begin());
			T node = a.second;
			int nodeDist =a.first;
			s.erase(s.begin());

			for(auto neighborPair : m[node])
			{
				if(nodeDist+neighborPair.second < dist[neighborPair.first])
				{
					
					T neighbor = neighborPair.first;
					parent[neighbor]=node;
					dist[neighbor] = nodeDist+neighborPair.second;
					auto index = s.find(make_pair(neighborPair.second,neighbor));
						if(index!=s.end())
							s.erase(index);
						s.insert(make_pair(dist[neighbor],neighbor));
				}
			}

		

		}


	for(auto d:dist)
			{
				cout << "distance of "<<d.first<<" from " <<src<<" is "<<d.second<<endl;
			}

		T temp = dest;
		while(temp!=src)
		{
			cout << temp <<",";
			temp=parent[temp];
		}
		cout << src;




	}
};


int main()
{
	// Graph<int> g;
	// g.addEdge(1,2,1);
	// g.addEdge(1,3,4);
	// g.addEdge(1,4,7);
	// g.addEdge(2,3,1);
	// g.addEdge(3,4,2);
	// g.print();
	// g.dsssp(1);


	Graph<string> India;
	India.addEdge("Amritsar","Delhi",1);
	India.addEdge("Amritsar","Jaipur",4);
	India.addEdge("Jaipur","Delhi",2);
	India.addEdge("Jaipur","Mumbai",8);
	India.addEdge("Bhopal","Agra",2);
	India.addEdge("Mumbai","Bhopal",3);
	India.addEdge("Agra","Delhi",1);
	// India.addEdge("","",);

	India.print();
	India.dsssp("Amritsar","Mumbai");	


}