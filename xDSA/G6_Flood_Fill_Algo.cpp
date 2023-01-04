class Solution {
private:
    void dfs(vector<vector<int>>& img, vector<vector<int>>& image, int row, int col, int newColor, int curColor, int drow[], int dcol[]) {
        
        int n = img.size();
        int m = img[0].size();
        img[row][col] = newColor;
        
        for(int i=0; i<4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            
            if(nrow >= 0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol] == curColor && img[nrow][ncol] != newColor){
                dfs(img, image, nrow, ncol, newColor, curColor, drow, dcol);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int n = image.size();
        int m = image[0].size();
        
        vector<vector<int>>img = image;
        
        // int vis[n][m] = {0};
        int curColor = image[sr][sc];
                
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        
        dfs(img, image, sr, sc, newColor, curColor, drow, dcol);
        
        return img;
    }
};