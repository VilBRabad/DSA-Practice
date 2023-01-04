class Solution {
  public:
    int minLaptops(int N, int start[], int end[]) {
        map<int,int>mp;
        for(int i=0; i<N; i++)
        {
            mp[start[i]] += 1;
            mp[end[i]] -= 1;
        }
        vector<pair<int,int>> s;
        for(auto it: mp)
            s.push_back(it);
        sort(s.begin(), s.end());
        int c=0,ans=0;
        for(pair<int,int> i:s)
        {
            c+=i.second;
            ans=max(ans,c);
        }
        return ans;
    }
};