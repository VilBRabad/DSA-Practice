class Solution{
private:
    void dfs(int row, int col, vector<vector<int>>&vis, vector<vector<char>>mat, int delrow[], int delcol[]){
        int n = mat.size();
        int m = mat[0].size();
        
        vis[row][col] = 1;
        
        for(int i=0; i<4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow>=0 && nrow <n && ncol>=0 && ncol<m && mat[nrow][ncol] == 'O' && !vis[nrow][ncol]){
                dfs(nrow, ncol, vis, mat, delrow, delcol);
            }
        }
    }
    
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat){
        vector<vector<int>>vis(n, vector<int>(m, 0));
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        
        //ROW
        for(int col=0; col<m; col++){
            //first row
            if(!vis[0][col] && mat[0][col] == 'O'){
                dfs(0, col, vis, mat, delrow, delcol);
            }
            // last row
            if(!vis[n-1][col] && mat[n-1][col] == 'O'){
                dfs(n-1, col, vis, mat, delrow, delcol);
            }
        }
        
        //COl
        for(int row=0; row<n; row++){
            //first col
            if(!vis[row][0] && mat[row][0] == 'O'){
                dfs(row, 0, vis, mat, delrow, delcol);
            }
            // last col
            if(!vis[row][m-1] && mat[row][m-1] == 'O'){
                dfs(row, m-1, vis, mat, delrow, delcol);
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && mat[i][j] == 'O'){
                    mat[i][j] = 'X';
                }
            }
        }
        
        return mat;
        
        
    }
};