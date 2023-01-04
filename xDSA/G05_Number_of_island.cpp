class Solution {
  private:
    void bfs(vector<vector<char>>& grid, vector<vector<int>>&vis, int row, int col){
        vis[row][col] = 1;
        
        queue<pair<int, int>> q;
        q.push({row, col});
        
        int n = grid.size();
        int m = grid[0].size();
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int i=-1; i<=1; i++){
                for(int j=-1; j<=1; j++){
                    int nrow = row+i;
                    int ncol = col+j;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && !vis[nrow][ncol]){
                        vis[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
    }   

  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int cnt=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j] != 1 && grid[i][j] == '1'){
                    cnt++;
                    bfs(grid, vis, i, j);
                }
            }
        }
        return cnt;
    }
};