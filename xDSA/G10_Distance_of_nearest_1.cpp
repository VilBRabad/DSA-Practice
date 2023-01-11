/*prblm : Given a binary grid of n*m. Find the distance of the nearest 1 in the grid for each cell. The distance is calculated as |i1  - i2| + |j1 - j2|, where i1, j1 are the row number and column number of the current cell, and i2, j2 are the row number and column number of the nearest cell having value 1 */
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
	vector<vector<int>>nearest(vector<vector<int>>grid){
	    int n = grid.size();
	    int m = grid[0].size();
	    
	    vector<vector<int>> vis(n, vector<int>(m, 0));
	    vector<vector<int>> dis(n, vector<int>(m, 0));
	    
	    queue<pair<pair<int, int>, int>> q;
	    for(int i=0; i<n; i++){
	        for(int j=0; j<m; j++){
	            if(grid[i][j] == 1){
	                vis[i][j] = 1;
	                q.push({{i, j}, 0});
	            }
	            else{
	                vis[i][j] = 0;
	            }
	        }
	    }
	    
	    int delrow[] = {-1, 0, 1, 0};
	    int delcol[] = {0, 1, 0, -1};
	    
	    while(!q.empty()){
	        int row = q.front().first.first;
	        int col = q.front().first.second;
	        int step = q.front().second;
	        q.pop();
	        
	        dis[row][col] = step;
	        
	        for(int i=0; i<4;i++){
	            int nrow = row + delrow[i];
	            int ncol = col + delcol[i];
	            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0){
	                vis[nrow][ncol] = 1;
	                q.push({{nrow, ncol}, step+1});
	            }
	        }
	    }
	    return dis;
	}
};