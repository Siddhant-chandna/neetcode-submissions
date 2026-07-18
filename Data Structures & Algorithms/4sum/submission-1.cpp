class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        set<vector<int>> ans;
        for(int i=0;i<nums.size()-3;i++){
            for(int j=i+1;j<nums.size()-2;j++){
                int k=j+1,l=nums.size()-1;
                while(k<l){
                    long long sum=(long long)nums[i]+nums[j]+nums[k]+nums[l];
                    if(sum==target){
                        ans.insert({nums[i],nums[j],nums[k],nums[l]});
                        k++;l--;
                    } 
                    else if(sum<target) k++;
                    else l--;
                }
            }
        }
        vector<vector<int>> res;
        for(auto x:ans){
            res.push_back(x);
        }
        return res;
    }
};