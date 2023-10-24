//You are in a city that consists of n intersections numbered from 0 to n - 1 
//with bi-directional roads between some intersections.The inputs are
//generated such that you can reach any intersection from any other 
//intersection and that there is at most one road between any two intersections.

//You are given an integer n and a 2D integer array roads where 
//roads[i] = [ui, vi, timei] means that there is a road between 
//intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from 
//intersection 0 to intersection n - 1 in the shortest amount of time.

//Return the number of ways you can arrive at your destination in the 
//shortest amount of time. Since the answer may be large, return it modulo 109 + 7.

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>> adj[n];
        for (auto it : roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        // Defining a priority queue (min heap). 
        priority_queue<pair<long long int, int>,
                       vector<pair<long long int, int>>, greater<pair<long long int, int>>> pq;

        // Initializing the dist array and the ways array
        // along with their first indices.
        vector<long long int> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        // Define modulo value
        int mod = (int)(1e9 + 7);

        // Iterate through the graph with the help of priority queue
        // just as we do in Dijkstra's Algorithm.
        while (!pq.empty()){
            long long int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto it : adj[node]){
                int adjNode = it.first;
                long long int edW = it.second;

                // This ‘if’ condition signifies that this is the first
                // time we’re coming with this short distance, so we push
                // in PQ and keep the no. of ways the same.
                if (dis + edW < dist[adjNode]){
                    dist[adjNode] = dis + edW;
                    pq.push({dis + edW, adjNode});
                    ways[adjNode] = ways[node];
                }

                // If we again encounter a node with the same short distance
                // as before, we simply increment the no. of ways.
                else if (dis + edW == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        // Finally, we return the no. of ways to reach
        // (n-1)th node modulo 10^9+7.
        return ways[n - 1] % mod;
    }
};