class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int x=nums.size()-1;
        int i=0, count=0;
        while(i<=x){
            if(nums[x]==val){
                x--;
                count++;
                continue;
            }
            if(nums[i]==val){
                swap(nums[i], nums[x]);
                x--;
                count++;
            } 
            i++;
        }
        return nums.size()-count;
    }
};