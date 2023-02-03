/*
Problem : You are given an Undirected Graph having unit weight, Find the shortest path from src(0) to all the vertex and if it is unreachable to reach any vertex, then return -1 for that vertex.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int> adj[N];
        for(int i=0; i<M; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        queue<int> q;
        q.push(src);
        vector<int> dist(N);
        
        for(int i=0; i<N; i++) dist[i] = INT_MAX;
        
        dist[src] = 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto adjacents : adj[node]){
                if(dist[node]+1 < dist[adjacents]){
                    dist[adjacents] = dist[node]+1;
                    q.push(adjacents);
                }
            }
        }
        
        vector<int> ans(N, -1);
        for(int i=0; i<N; i++){
            if(dist[i] != INT_MAX){
                ans[i] = dist[i];
            }
        }
        return dist;
    }
};