#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
    void dfs(vector<int>graph[], int vis[], int node){
        vis[node] = 1;
        for(auto it: graph[node]){
            if(vis[it] != 1){
                dfs(graph, vis, it);
            }
        }
    }
    
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int> graph[V];
        
        int vis[V] = {0};
        
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                if(adj[i][j] == 1){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        
        int cnt=0;
        for(int i=0; i<V; i++){
            if(vis[i] == 0){
                cnt++;
                dfs(graph, vis, i);
            }
        }
        
        return cnt;
        
    }
};