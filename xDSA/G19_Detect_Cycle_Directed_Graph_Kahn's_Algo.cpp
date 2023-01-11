/*
Problem : Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    bool isCyclic(int V, vector<int> adj[]){
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
	     
	     int cnt=0;
	     while(!q.empty()){
	         int node = q.front();
	         q.pop();
	         
	         cnt++;
	         for(auto it : adj[node]){
	             inDeg[it]--;
	             if(inDeg[it]==0){
	                 q.push(it);
	             }
	         }
	     }
	     
	     if(cnt == V) return false;
	     
	     return true;
    }
};