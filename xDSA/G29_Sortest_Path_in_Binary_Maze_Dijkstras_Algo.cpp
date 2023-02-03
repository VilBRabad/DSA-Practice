/*
Problem :  Given a n * m matrix grid where each element can either be 0 or 1. You need to find the shortest distance between a given source cell to a destination cell. The path can only be created out of a cell if its value is 1. 
If the path is not possible between source cell and destination cell, then return -1.\

Note : You can move only 4 Directiob Up, Left, Down & Right in Matricx.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {
        // code here
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dist(m, vector<int>(n, 1e9));
        
        dist[source.first][source.second] = 0;
        q.push({0, source});
        
        //4 Directions
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        
        while(!q.empty()){
            int dis = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            
            // If Destination row & col foud -- return distace.
            if(row == destination.first && col == destination.second){
                return dis;
            }
            
            // Going 4 Direction from Current position
            for(int i=0; i<4; i++){
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                
                // Validation of nrow & ncol and checking grid[][] = 1 or not.
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol] == 1){
                    if(dis + 1 < dist[nrow][ncol]){
                        dist[nrow][ncol] = dis + 1;
                        q.push({dis+1, {nrow, ncol}});
                    }
                }
            }
        }
        return -1;        
    }
};
