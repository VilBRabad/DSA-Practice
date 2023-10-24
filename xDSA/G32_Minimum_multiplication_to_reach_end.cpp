//Given start, end and an array arr of n numbers. 
//At each step, start is multiplied with any number in the array and then mod operation with 100000 is done to get the new start.
//Your task is to find the minimum steps in which end can be achieved starting from start. 
//If it is not possible to reach end, then return -1.

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        queue<pair<int, int>>q; // {steps, Num}
        q.push({0, start});
        vector<int> dist(100000, 1e9);
        
        dist[start] = 0;
        int mod = 100000;
        
        while(!q.empty()){
            int steps = q.front().first;
            int num = q.front().second;
            q.pop();
            
            if(num == end) return steps;
            
            for(auto it: arr){
                int newNum = (it*num)%mod;
                if(steps+1 < dist[newNum]){
                    dist[newNum] = steps+1;
                    
                    if(newNum == end) return steps+1;
                    
                    q.push({steps+1, newNum});
                }
            }
        }
        return -1;
    }
};