#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        
        vector<vector<int>>dist(n, vector<int>(m, 1e9));
        
        dist[0][0] = 0;
        
        pq.push({0, {0, 0}});
        
        int rows[] = {-1, 0, 1, 0};
        int cols[] = {0, 1, 0, -1};
        
        while(!pq.empty()){
            int eff = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            
            for(int i=0; i<4; i++){
                int nRow = row + rows[i];
                int nCol = col + cols[i];
                
                if(nRow >= 0 && nRow < n && nCol>=0 && nCol<m){
                    int diff = abs(heights[nRow][nCol] - heights[row][col]);
                    int nEff = max(eff, diff);
                    if(nEff < dist[nRow][nCol]){
                        dist[nRow][nCol] = nEff;
                        pq.push({nEff, {nRow, nCol}});
                    }
                } 
            }
        }
        return dist[n-1][m-1];
    }
};
