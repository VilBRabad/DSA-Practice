#include<bits/stdc++.h>
using namespace std;

//Maximum cost with at most k stops
//graph: {node, adjNode, cost}

int getAns(vector<vector<int>> &graph, int V, int src, int dest, int k){
   vector<pair<int, int>> adj[V];
   for(auto it : graph){
      adj[it[0]].push_back({it[1], it[2]});
   }

   queue<pair<int, pair<int, int>>>q;
   vector<int> dist(V);
   for(int i=0; i<V; i++) dist[i] = 1e9;

   q.push({0, {src, 0}});
   dist[src] = 0;

   while(!q.empty()){
      int stops = q.front().first;
      int node = q.front().second.first;
      int cost = q.front().second.second;
      q.pop();

      if(stops > k) continue;

      for(auto it : adj[node]){
         int adjNode = it.first;
         int adjCost = it.second;

         if(cost+adjCost < dist[adjNode] && stops <= k){
            dist[adjNode] = cost + adjCost;
            q.push({stops+1, {adjNode, cost+adjCost}});
         }
      }
   }
   if(dist[dest] == 1e9)
      return -1;

   return dist[dest];
}
