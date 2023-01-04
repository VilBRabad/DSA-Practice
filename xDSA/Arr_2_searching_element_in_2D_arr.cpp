#include<bits/stdc++.h>
using namespace std;

//GFG
class Solution{
public:	
	int matSearch (vector <vector <int>> &mat, int N, int M, int X){
	    int i = 0, j = M-1;
	    while(i<N && j>=0){
	        if(mat[i][j] == X){
	            return 1;
	        }
	        else if(mat[i][j] < X){
	            i++;
	        }
	        else{
	            j--;
	        }
	    }
	    return 0;
	}
};

//LeetCode
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0)
            return false;
        
        int n = matrix.size();
        int m = matrix[0].size();
        int lo = 0;
        int hi = (n*m)-1;
        
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(matrix[mid/m][mid%m] == target)
                return true;
            else if(matrix[mid/m][mid%m] > target)
                hi = mid-1;
            else
                lo = mid+1;
        }
        return false;
            
    }
};

int main(){

    
    return 0;
}