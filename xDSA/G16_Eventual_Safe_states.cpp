/*
Problem: A directed graph of V vertices and E edges is given in the form of an adjacency list adj. 
Each node of the graph is labelled with a distinct integer in the range 0 to V - 1.

A node is a terminal node if there are no outgoing edges. A node is a safe node 
if every possible path starting from that node leads to a terminal node.

You have to return an array containing all the safe nodes of the graph. 
The answer should be sorted in ascending order.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
    bool dfs(int node, int vis[], int pathVis[], int check[], vector<int>adj[]){
        vis[node] = 1;
        pathVis[node] = 1;
        
        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfs(it, vis, pathVis, check, adj) == true){
                    check[it] = 0;
                    return true;
                }
            }
            else if(pathVis[it] == 1){
                return true;
            }
        }
        check[node] = 1;
        pathVis[node] = 0;
        return false;
    }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        int vis[V] = {0};
        int pathVis[V] = {0};
        int check[V] = {0};
        
        vector<int> safenodes;
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i, vis, pathVis, check, adj);
            }
        }
        
        for(int i=0; i<V; i++){
            if(check[i] == 1){
                safenodes.push_back(i);
            }
        }
        return safenodes;
    }
};