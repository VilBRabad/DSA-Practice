/*
Prblm : Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, 
check whether it contains any cycle or not.
*/

class Solution {
  private:
    bool dfs(int node, int vis[], int pvis[], vector<int> adj[]){
        vis[node] = 1;
        pvis[node] = 1;
        
        for(auto it : adj[node]){
            //If not visited, visite them
            if(vis[it]==0){
                if(dfs(it, vis, pvis, adj)) 
                    return true;
            }
            //if visited but if path visited, if yes means cycle detected
            else if(pvis[it] == 1){
                return true;
            }
        }
        pvis[node] = 0;
        return false;
    }
    
  public:
    bool isCyclic(int V, vector<int> adj[]) {
        int vis[V] = {0};
        int pvis[V] = {0};
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(dfs(i, vis, pvis, adj))
                    return true;
            }
        }
        return false;
    }
};