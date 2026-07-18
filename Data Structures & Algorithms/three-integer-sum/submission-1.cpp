class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> ans;
        for(int k=0;k<nums.size()-2;k++){
            int i=k+1,j=nums.size()-1;
            while(i<j){
                if(nums[i]+nums[j]+nums[k]==0) {
                    ans.insert({nums[k], nums[i], nums[j]});
                    i++; j--;
                }
                else if(nums[i]+nums[j]+nums[k]<0) i++;
                else j--; 
            }
        }
        vector<vector<int>> res;
        for(auto x:ans){
            res.push_back(x);
        }
        return res;
    }
};
