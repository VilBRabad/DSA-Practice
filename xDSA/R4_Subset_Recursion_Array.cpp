#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void solve(vector<int>nums, vector<int>output, int index, vector<vector<int>> &ans){
        //base case:
        if (index >= nums.size()){
            ans.push_back(output);
            return;
        }
        
        //exclude - non take
        solve(nums, output, index+1, ans);
        
        //include - take
        output.push_back(nums[index]);
        solve(nums, output, index+1, ans);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        
        solve(nums, output, 0, ans);
        return ans;
    }
};

int main(){

    Solution vil;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = vil.subsets(nums);
    cout<<"{";
    for(int i=0; i<ans.size(); i++){
        cout<<"{";
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j];
            if(j<ans[i].size()-1){
                cout<<" ";
            }
        }
        cout<<"}";
        if(i<ans.size()-1){
            cout<<", ";
        }
    }
    cout<<"}";
    return 0;
}