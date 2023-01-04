/* Prblm : You are given an n x m binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.
A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.
Find the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.
*/

// TC : N x M x 4
// SC : N x M


//********************** DFS *********************************

class Solution {
private:
    void dfs(int r, int c, vector<vector<int>>& vis, vector<vector<int>>& grid, int delrow[], int delcol[]){
        vis[r][c] = 1;
        int n = grid.size();
        int m = grid[0].size();

        for(int i=0; i<4; i++){
            int nrow = r + delrow[i];
            int ncol = c + delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol] == 1 && !vis[nrow][ncol]){
                dfs(nrow, ncol, vis, grid, delrow, delcol);
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        
        for(int col=0; col<m; col++){
            if(grid[0][col] == 1 && !vis[0][col]){
                dfs(0, col, vis, grid, delrow, delcol);
            }
            
            if(grid[n-1][col] == 1 && !vis[n-1][col]){
                dfs(n-1, col, vis, grid, delrow, delcol);
            }
        }
        
        for(int row=0; row<n; row++){
            if(grid[row][0] == 1 && !vis[row][0]){
                dfs(row, 0, vis, grid, delrow, delcol);
            }
            
            if(grid[row][m-1] == 1 && !vis[row][m-1]){
                dfs(row, m-1, vis, grid, delrow, delcol);
            }
        }
        
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    ans++;
                }
            }
        }
        
        return ans;
    }
};


//*********************************** BFS ************************************
class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>>q;
        
        for(int row=0; row<n; row++){
            for(int col=0; col<m; col++){
                if(row==0 || row==n-1 || col==0 || col == m-1){
                    if(grid[row][col] == 1){
                        vis[row][col] = 1;
                        q.push({row, col});
                    }
                }
            }
        }
        
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int i=0; i<4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
        
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    ans++;
                }
            }
        }
        
        return ans;
        
    }
};

