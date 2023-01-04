#include<bits/stdc++.h>
using namespace std;

vector<int> bfsinGraph(vector<int> adj[], int n){
    vector<int>bfs;

    int vis[n] = {0};
    vis[0] = 1;

    queue<int> q;
    q.push(0);

    while(!q.empty()){
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for(auto it : adj[node]){
            if(!vis[it]){
                q.push(it);
                vis[it] = 1;
            }
        }
    }
    return bfs;
}

int main(){
    
    int V, E;
    cin>>V>>E;
    vector<int> graph[V+1];
    for(int i=0; i<E; i++){
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> ans = bfsinGraph(graph, V);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}