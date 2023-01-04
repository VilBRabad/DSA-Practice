#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;
        
        //Storing Indices of array in Deque.
        
        for(int i=0; i<nums.size(); i++){
            int front_index = i-k;  //if i = 3, k = 3 -> 3-3 = 0
            
            if(!dq.empty() && dq.front() == front_index)
                dq.pop_front();
            
            while(!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();
            
            dq.push_back(i);
            if(i >= k-1)
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};
// TC = O(n) + O(n) == O(n);
// SC = O(k); At maximum we can store K elements in Deque

int main(){

    Solution ofQuestion;
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k =3;
    vector<int> Get_ans =  ofQuestion.maxSlidingWindow(nums, k);

    for(auto &it : Get_ans){
        cout<<it<<" ";
    }

    return 0;
}