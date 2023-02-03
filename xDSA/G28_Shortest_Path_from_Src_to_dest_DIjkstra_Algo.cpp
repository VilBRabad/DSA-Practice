/*
Problem:You are given a weighted undirected graph having n+1 vertices numbered from 0 to n and m edges describing there are edges between a to b with some weight, find the shortest path between the vertex 1 and the vertex n and if path does not exist then return a list consisting of only -1.
*/
/*
TC : Dijkstra's Algorith Take --> O(E.log(V))
    and at last while loop can take O(N) TC in Worst Case

    total TC : O(E.log(V)) + O(N)
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<pair<int, int>> adj[n+1];
        for(auto it : edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        vector<int> dist(n+1, 1e9);
        vector<int> parent(n+1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 1});
        dist[1] = 0;
        
        while(!pq.empty()){
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it : adj[node]){
                int adjNode = it.first;
                int adjW = it.second;
                if(wt + adjW < dist[adjNode]){
                    dist[adjNode] = wt + adjW;
                    pq.push({dist[adjNode], adjNode});
                    parent[adjNode] = node;
                }
            }
        }
        
        if(dist[n] == 1e9) return {-1};
        
        vector<int> path;
        int node = n;
        while(parent[node] != node){
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        
        reverse(path.begin(), path.end());
        
        return path;
    }
};

int main(){
    return 0;
}