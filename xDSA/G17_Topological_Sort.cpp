/*
Problem : Given a Directed Acyclic Graph (DAG) with V vertices and E edges, Find any Topological Sorting of that Graph.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
  private:
    void dfs(int node, int vis[], vector<int> adj[], stack<int> &st){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it, vis, adj, st);
            }
        }
        st.push(node);
    }
  public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) {
	    int vis[V] = {0};
	    stack<int> st;
	    for(int i=0; i<V; i++){
	        if(vis[i]==0){
	            dfs(i, vis, adj, st);
	        }
	    }
	    
	    vector<int> ans;
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}
};