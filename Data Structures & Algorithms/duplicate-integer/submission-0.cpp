class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto x:nums){
            if(m.find(x)!=m.end()) return true;
            m[x]++;
        }
        return false;
    }
};