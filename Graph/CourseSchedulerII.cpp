#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;


 vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        /*
        create graph
        calculate indegree of each node
        find node with indegree 0 and put it in queue
        while q is not empty
        print the top element and reduce of indegree of all neighbors by 1 
        if indegree of any node becomes 0, put it in queue
        
        //if indegree of any node is still not 0 then disconnected component
            0,1
            0->1
            1
            
            [[1,0],[2,0],[3,1],[3,2]]
            1->0
            2->0
            3->1
            3->2
            
        */
        vector<vector<int>> graph(numCourses);
        int n = prerequisites.size();
        
        for(int i=0;i<n;i++)
           graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        
        // vector<bool> visited(numCourses,false);
        vector<int> indegree(numCourses,0);
        
        for(auto e:graph){
            for(auto neighbor:e){
                indegree[neighbor]++;
            }
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)
                q.push(i);
        }
        vector<int> ans;
        while(q.size()>0){
            int element = q.front();
            q.pop();
            ans.push_back(element);
            for(auto neighbor : graph[element]){
                    indegree[neighbor]--;
                    if(indegree[neighbor]==0)
                        q.push(neighbor);   
            }  
        }  
       reverse(ans.begin(),ans.end());
        return ans;  
    }
int main()
{
    /*int numCourses = 4;
    vector<vector<int>> prerequisites = {{1,0},{2,0},{3,1},{3,2}};*/
    int numCourses = 3;
    vector<vector<int>> prerequisites = {{0,2},{1,2},{2,0}};
    vector<int> ans = findOrder(numCourses,prerequisites);
    for(auto i:ans)
        cout << i <<" ";
    cout << endl;
    return 0;

}