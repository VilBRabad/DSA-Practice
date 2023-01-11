/*
Prblm : Given a boolean 2D matrix grid of size n * m. You have to find the number of 
distinct islands where a group of connected 1s (horizontally or vertically) forms an island. 
Two islands are considered to be distinct if and only if one island is not equal to 
another (not rotated or reflected)
*/
#include<bits/stdc++.h>
using namespace std;


class Solution {
  private:
    void dfs(int row, int col, int brow, int bcol, vector<vector<int>>& vis, vector<vector<int>>& grid, 
      vector<pair<int, int>> &str, int delrow[], int delcol[]){
        vis[row][col] = 1;
        int x = row-brow;
        int y = col-bcol;
        str.push_back({x, y});
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0; i<4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && !vis[nrow][ncol]){
                dfs(nrow, ncol, brow, bcol, vis, grid, str, delrow, delcol);
            }
        }
    }
    
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<pair<int, int>>> st;
        
        int delrow[] = {0, 1, 0, -1};
        int delcol[] = {1, 0, -1, 0};
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    vector<pair<int, int>> str;
                    dfs(i, j, i, j, vis, grid, str, delrow, delcol);
                    st.insert(str);
                }
            }
        }
        
        //SC : N*M
        //TC = (for loop)*(set insertion) + DFS
        //TC : N*M * log(N*M) +  N*M*4
        int ans = st.size();
        return ans;
    }
};