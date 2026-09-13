class Solution {
public:
    void combine(vector<int> &nums, int target, int i, vector<int> temp, vector<vector<int>> &ans){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if (target < 0) {
            return;
        }
        for(int t=i;t<nums.size();t++){
            temp.push_back(nums[t]);
            combine(nums, target-nums[t], t, temp,ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        combine(nums, target, 0, temp,ans);
        return ans; 
    }
};
