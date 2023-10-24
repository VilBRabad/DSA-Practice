#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int>graph[], vector<int> &ans, int vis[]){
    vis[node] = 1;
    ans.push_back(node);

    for(auto it : graph[node]){
        if(!vis[it]){
            dfs(it, graph, ans, vis);
        }
    }
}

// vector<int>dfsinGraph(int V, vector<int> graph[]){
//     int vis[n] = {0}; //Assuming starting point 0
//     vector<int> ans;
//     dfs()
// }

// SC : O(n) + O(n) + O(n) = O(n)
// TC : O(n) + O(V + 2E)

int main(){
    
    return 0;
}