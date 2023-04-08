/*
Problem : (MST) Given a weighted, undirected and connected graph of V vertices and E edges. 
The task is to find the sum of weights of the edges of the Minimum Spanning Tree.
*/


class Solution{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]){
       
       priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
       vector<int> vis(V, 0);
       int sum=0;
       //{Waieht, node}
       pq.push({0, 0});
       while(!pq.empty()){
           auto it = pq.top();
           pq.pop();
           
           int Node = it.second;
           int wt = it.first;
           
           if(vis[Node] == 1) continue;
           
           vis[Node] = 1;
           sum += wt;
           
           for(auto it : adj[Node]){
               int adjNode = it[0];
               int adjW = it[1];
               if(vis[adjNode] != 1){
                   pq.push({adjW, adjNode});
               }
           }
       }
       return sum; 
    }
};

