/*
Problem : Given a Directed Acyclic Graph (DAG) with V vertices and E edges, Find any Topological Sorting of that Graph.
*/

// Topological sorting : BFS

#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:
	vector<int> topoSort(int V, vector<int> adj[]) {
	     int inDeg[V]={0};
	     queue<int> q;
	     
	     for(int i=0; i<V; i++){
	         for(auto it : adj[i]){
	             inDeg[it]++;
	         }
	     }
	     for(int i=0; i<V; i++){
	         if(inDeg[i]==0){
	             q.push(i);
	         }
	     }
	     
	     vector<int> ans;
	     while(!q.empty()){
	         int node = q.front();
	         q.pop();
	         
	         ans.push_back(node);
	         for(auto it : adj[node]){
	             inDeg[it]--;
	             if(inDeg[it]==0){
	                 q.push(it);
	             }
	         }
	     }
	     return ans;
	}
};