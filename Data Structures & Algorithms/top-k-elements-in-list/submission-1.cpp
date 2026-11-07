class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(auto x:nums){
            freq[x]++;
        }
        priority_queue<pair<int,int>> q;
        for(auto x:freq){
            q.push({x.second, x.first});
        }
        vector<int> ans;
        while(!q.empty() && k--){
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
    }
};
