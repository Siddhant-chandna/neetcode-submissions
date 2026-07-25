class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int> s;
        for(auto x:nums){
            if(x>0) s.insert(x);
        }
        int j=1;
        for(auto x:s){
            if(x!=j){
                return j;
            }
            j++;
        }
        return j;
    }
};