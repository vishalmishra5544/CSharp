#include<bits/stdc++.h>
using namespace std;


    int isTree(int n, int m, vector<vector<int>> &adj) {
        // code here
        unordered_map<int,vector<int>> adjList;
        for(auto & edge:adj)
        {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        vector<int> visited(n,0);
        if(dfs(adjList,visited,0,-1))
        {
            for(auto & v:visited)
            {
                if(!v)
                 return 0;
            }
            return 1;
        }
        return 0;
    }

    int dfs(unordered_map<int,vector<int>> &adjList,vector<int> &visited,int curr,int parent)
    {
        visited[curr]=1;
        for(auto &n:adjList[curr])
        {
            if(!visited[n])
            {
              if(dfs(adjList,visited,n,curr)==0)
                return 0;
            }
            else
            {
                if(n!=parent)
                 return 0;
            }
             
        }
        return 1;
    }
int main()
{
    return 0;
}