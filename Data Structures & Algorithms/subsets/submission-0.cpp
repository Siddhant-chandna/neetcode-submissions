class Solution {
public:
    void trav(vector<int> nums, int i, vector<int> temp, vector<vector<int>> &ans){
        if(i==nums.size()){
            ans.push_back(temp);
            return;
        }
        trav(nums, i+1, temp, ans);
        temp.push_back(nums[i]);
        trav(nums, i+1, temp, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        trav(nums, 0, temp, ans);
        return ans;
    }
};
