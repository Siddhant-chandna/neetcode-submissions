class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0,j=0;
        int minm=INT_MAX;
        int sum=0;
        while(i<nums.size()){
            sum+=nums[i];
            while(sum>=target && j<=i){
                minm=min(minm,i-j+1);
                sum-=nums[j];
                j++;
            }
            i++;
        }
        return minm==INT_MAX?0:minm;
    }
};