/*
Problem : Given a Directed Acyclic Graph of N vertices from 0 to N-1 and a 2D Integer array(or vector) edges[ ][ ] of length M, where there is a directed edge from edge[i][0] to edge[i][1] with a distance of edge[i][2] for all i, 0<=i
Find the shortest path from src(0) vertex to all the vertices and if it is impossible to reach any vertex, then return -1 for that vertex.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
  private:
    void TopoSort(int node, stack<int>&st, vector<pair<int, int>>adj[], int vis[]){
        vis[node] = 1;
        for(auto it : adj[node]){
            int v = it.first;
            if(!vis[v]){
                TopoSort(v, st, adj, vis);
            }
        }
        st.push(node);
    }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<pair<int, int>> adj[N];
        for(int i=0; i<M; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            adj[u].push_back({v, wt});
        }
        
        stack<int> st;
        int vis[N] = {0};
        TopoSort(0, st, adj, vis);
        
        vector<int> dist(N);
        for(int i=0; i<N; i++) dist[i] = INT_MAX;
        
        dist[0] = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            for(auto it: adj[node]){
                int v = it.first;
                int wt = it.second;
                
                if(dist[node] + wt < dist[v]){
                    dist[v] = dist[node] + wt;
                }
            }
        }
        
        for(int i=0; i<N; i++){
            if(!vis[i]){
                dist[i] = -1;
            }
        }
        
        return dist;
    }
};