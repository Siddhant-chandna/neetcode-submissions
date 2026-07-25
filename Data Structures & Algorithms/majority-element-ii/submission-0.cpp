class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1=0,c2=0;
        int candidate1=0,candidate2=0;
        for(int i=0;i<nums.size();i++){
            if(c1==0 && nums[i]!=candidate2){
                candidate1=nums[i];
                c1=1;
            } else if(c2==0 && nums[i]!=candidate1){
                c2=1;
                candidate2=nums[i];
            } else if(candidate1==nums[i]){
                c1++;
            } else if(candidate2==nums[i]){
                c2++;
            }else{
                c1--;c2--;
            }
        }
        vector<int> ans;
        int x=nums.size()/3;
        int count1=0,count2=0;
        for(int i=0;i<nums.size();i++){
            if(candidate1==nums[i]){
                count1++;
            } else if(candidate2==nums[i]){
                count2++;
            }
        }
        if(count1>x) ans.push_back(candidate1);
        if(count2>x) ans.push_back(candidate2);
        return ans;
    }
};