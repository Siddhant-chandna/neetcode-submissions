class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int zero=0;
        int product=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) zero++;
            else product*=nums[i];
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                if(zero>1) ans.push_back(0);
                else ans.push_back(product);
            } else{
                if(zero) ans.push_back(0);
                else ans.push_back(product/nums[i]);
            }
        }
        return ans;
    }
};
