/*
Prblm : Given an adjacency list of a graph adj  of V no. of vertices having 0 based index. 
Check whether the graph is bipartite or not.
*/

/****************************** BFS ***************************/
class Solution {
private:
    bool check(int start, vector<int>adj[], int color[]){
	    queue<int>q;
        q.push(start);
        color[start] = 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto it:adj[node]){
                if(color[it] == -1){
                    q.push(it);
                    color[it] = !color[node];
                }
                else if(color[it] == color[node]){
                    return false;
                }
            }
        }
        return true;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    int color[V];
	    for(int i=0; i<V; i++) color[i] = -1;
	    
	    for(int i=0; i<V; i++){
	        if(color[i] == -1){
	            if(check(i, adj, color) == false){
	                return false;
	            }
	        }
	    }
	    return true;
	}
};

/*********************************** DFS *************************************/

class Solution {
private:
    bool check(int node, int col, vector<int>adj[], int color[]){
	    color[node] = col;
	    
	    for(auto it:adj[node]){
            if(color[it] == -1){
                if(check(it, !col, adj, color) == false) return false;
            }
            else if(color[it] == color[node]){
                return false;
            }
        }
        return true;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    int color[V];
	    for(int i=0; i<V; i++) color[i] = -1;
	    
	    for(int i=0; i<V; i++){
	        if(color[i] == -1){
	            if(check(i, 0, adj, color) == false){
	                return false;
	            }
	        }
	    }
	    return true;
	}
};
