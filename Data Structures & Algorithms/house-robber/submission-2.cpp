class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        // vector<int> dp(n+2, 0);
        int nPlusTwo=0;
        int nPlusOne=0;
        int curr;
        for(int i=n-1;i>=0;i--){
            int take=nPlusTwo+nums[i];
            int notTake=nPlusOne;
            curr=max(take, notTake);
            nPlusTwo=nPlusOne;
            nPlusOne=curr;
        }
        return nPlusOne;
    }
};
