#include<iostream>
#include<bits/stdc++.h>
using namespace std;
    unordered_map<int, list<int>>m;
    void addEdge(int u, int v)
    {
        m[u].push_back(v);
    }
    int check(int judge)
    {
        for(auto i:m)
        {
            int node = i.first;
            if(node == judge)
                continue;
            bool flag=false;
            for(auto neighbor : i.second)
            {
                if(neighbor==judge)
                {
                    flag=true;
                    break;
                }
            }
            if(!flag)
                return -1;
                
        }
        return judge;
    }
    int findJudge(int N, vector<vector<int>>& trust) {
        int n = trust.size();
        for(int i=0;i<n;i++)
        {
                addEdge(trust[i][0], trust[i][1]);
        }
        int node;
        for(auto nodes:m)
        {
            node = nodes.first;
            if(m.count(node)==0 and  check(node))
            {
                return node;
            }
        }
        return -1;
        
    }


int main()
{
 

	return 0;
}