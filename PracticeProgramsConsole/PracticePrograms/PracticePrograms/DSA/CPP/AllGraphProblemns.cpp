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
//https://www.geeksforgeeks.org/problems/city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/1
void DjskstrasAlgo(int src, unordered_map<int, list<pair<int,int>>>& adj, vector<int>& dist) {
        dist[src] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, src});
        
        while(!pq.empty()) {
            auto node = pq.top().second;
            auto nodeDist = pq.top().first;
            pq.pop();
            
            for(auto nbr: adj[node]) {
                if(nbr.second + nodeDist < dist[nbr.first]) {
                    dist[nbr.first] = nodeDist + nbr.second;
                    pq.push({dist[nbr.first], nbr.first});
                }
            }
        }
        
        return;
    }
  
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        // Your code here
        
        unordered_map<int, list<pair<int,int>>> adj;
        for(int i=0; i<m; i++) {
            auto u = edges[i][0];
            auto v = edges[i][1];
            auto w = edges[i][2];
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        int minCities = INT_MAX, ans = 0;
        for(int i=0; i<n; i++) {
            vector<int> dist(n, 1e9);
            
            DjskstrasAlgo(i, adj, dist);
            
            int cityCnt = 0;
            for(int j=0; j<n; j++) {
                // cout << dist[j] << " ";
                if(dist[j] <= distanceThreshold && dist[j] != 0) {
                    cityCnt++;
                }
            }
            
            if(cityCnt <= minCities) {
                minCities = cityCnt;
                ans = i;
            }
        }
        
        return ans;
    }
//https://www.geeksforgeeks.org/problems/number-of-good-components--170647/1
void dfs(int n,vector<int>adj[],vector<bool>&vi,unordered_set<int>&st){
        vi[n]=true;
        st.insert(n);
        for(int i:adj[n]){
            if(!vi[i]){
                dfs(i,adj,vi,st);
            }
        }
    }
    int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges) {
        vector<int>adj[v+1];
        for(auto i:edges){
            int u=i[0];
            int v=i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int c=0;
        vector<bool> visited(v+1,0);
        for(int i=1;i<=v;i++){
            if(!visited[i]){
                unordered_set<int>st;
                dfs(i,adj,visited,st);
                bool isGoodComponent=1;
                for(int n:st){
                    if(adj[n].size()!=st.size()-1){
                        isGoodComponent=0;
                        break;
                    }
                }
                if(isGoodComponent)c++;
            }
        }

        return c;
    }
int main()
{
    return 0;
}