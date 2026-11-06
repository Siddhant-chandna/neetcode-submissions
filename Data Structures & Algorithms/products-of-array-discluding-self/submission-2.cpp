class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeros=0;
        int mul=1;
        for(auto x:nums){
            if(x==0){
                zeros++;
            } else{
                mul*=x;
            }
        }
        vector<int> ans;
        for(auto x:nums){
            if(zeros>0){
                if(x==0){
                    if(zeros>1){
                        ans.push_back(0);
                    } else{
                        ans.push_back(mul);
                    }
                } else {
                    ans.push_back(0);
                }
            } else{
                ans.push_back(mul/x);
            }
        }
        return ans;
    }
};
