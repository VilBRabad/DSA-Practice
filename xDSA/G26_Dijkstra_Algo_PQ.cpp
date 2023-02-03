/*
Problem: Implementation of Dijkstra Algorithm
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S){
        // Code here
        vector<int>dist(V);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for(int i=0; i<V; i++) dist[i] = 1e9;
        
        dist[S] = 0;
        pq.push({0, S});
        
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it : adj[node]){
                int adjNode = it[0];
                int edgeWeight = it[1];
                
                if(dis + edgeWeight < dist[adjNode]){
                    dist[adjNode] = dis + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};


// *** TC Analysis***
/*

while(!pq.empty()) -----> V
{
    pq.top()  ----------> log(heap size)

    for( iterate All Adjacent nodes) ---> ne ~ (V-1) ==> in Denze case - Edge between every Nodes 
    {  
        if( current dist is Greater than Previous Dist){
            Update Distance
            pq.push() -------> log(heap size)
        }
    }
}

TC:
  O( V * log(heap size) + (ne * log(heap size)) )

  O( V * log(heap size) *(ne + 1))

  O( V * log(heap size) * (V - 1 + 1)) ------> ne ~ (V - 1)

  O( V * log(heap size) * V)

  O( V^2 * log(heap size) )

  // In very very Worst case every node can have edges with V-1 nodes
  // In that case every node will add V-1 node in pq with better TC. VEry Hypothetic Case.
  // So, TC ~ ~ V^2

  O( V^2 * log( V^2 ))

  O( V^2 * 2log(V))

  O( E * 2log(V))

  O(E.log(V)) -------will be TC in WORST CASE
*/