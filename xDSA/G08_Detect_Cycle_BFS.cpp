#include <bits/stdc++.h>
using namespace  std;

class Solution {
    //BFS Traversal
  private:
    bool detect(int src, vector<int>adj[], int vis[]){
        queue<pair<int, int>>q; //({child, parent})
        vis[src] = 1;
        
        q.push({src, -1});
        
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto adjnodes: adj[node]){
                if(!vis[adjnodes]){
                    q.push({adjnodes, node});
                    vis[adjnodes] = 1;
                }
                else if(parent != adjnodes){
                    return true;
                }
            }
        }
        return false;
    }
    
  public:
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(detect(i, adj, vis)) return true;
            }
        }
        return false;
        
    }
};